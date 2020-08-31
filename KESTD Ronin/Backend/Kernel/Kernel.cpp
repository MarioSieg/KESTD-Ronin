// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Kernel.cpp
// 31.08.2020 15:09
// =============================================================

#include "Kernel.hpp"
#include "../LegacySubsystemBuilder.hpp"
#include "../../Frontend/Export/KESTD/Platform.hpp"
#include "../../Frontend/Export/KESTD/Environment.hpp"
#include <fmt/core.h>
#include <fmt/chrono.h>
#include <chrono>

#define STR "[Kernel] "

namespace kestd::kernel
{
	class Kernel::Pimpl final
	{
	public:
		volatile bool trapFlag = false;
		std::uint32_t cycles = 0;
		std::vector<std::unique_ptr<ISubsystem>> systems = {};
		std::tuple<std::string, std::string> info = {};
		std::chrono::system_clock::time_point begin = {};
		SystemState state = SystemState::Offline;
		SecurityManager securityManager;
		Environment env = {};
	};

	Kernel::Kernel(KernelDescriptor&& desc) : core(std::make_unique<Pimpl>())
	{
		core->info = std::make_tuple(std::move(desc.appName), std::move(desc.companyName));

		// Setup stopwatch:
		const auto stopwatch = std::chrono::high_resolution_clock::now();

		// Fetch environment data:
		auto& proto = core->env.getProtocol();
		const auto& platformInfo = core->env.getPlatformDiagnostics();

		// Write engine info to protocol:
		dumpBootInfo();

		// Allocate subsystems and dispatch onStartup() event:
		if (desc.pushLegacySubsystems)
		{
			PushLegacySubsystens(*this);
		}
		else
		{
			proto.warning(STR "No legacy subsystem pushed - it was disabled in the boot config!");
		}

		// Create and initialize subsystems

		// Dispatch onStartup()
		for (const auto& sys : core->systems)
		{
			if (sys->events & Event::OnStartup && !sys->onStartup(core->env))
			{
				throw std::runtime_error(
					STR "Failed to dispatch 'OnStartup' on system: " + std::string(sys->name));
			}
		}

		// Calculate boot time and print it:
		const auto bootTime = std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::high_resolution_clock::now() - stopwatch).count();
		proto.success(STR "System online! BootTime: {:.1f}s", bootTime / 1000.f);

		// System is ready now:
		core->state = SystemState::Ready;
	}

	auto Kernel::pushSubsystem(std::unique_ptr<ISubsystem>&& ptr) const -> std::size_t
	{
		// Begin stopwatch:
		const auto stopwatch = std::chrono::high_resolution_clock::now();

		// Construct subsystem:
		core->systems.emplace_back(std::move(ptr));

		// Profile boot time:
		const auto bootTime = std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::high_resolution_clock::now() - stopwatch).count() / 1000.f;

		// Log boot time:
		core->env.getProtocol().success(
			STR "Subsystem[{}] BootTime: {}s",
			core->systems.back()->name,
			bootTime);

		return core->systems.size();
	}

	auto Kernel::execute() const -> std::uint32_t
	{
		// Check if system is ready:
		if (core->systems.empty() || core->state != SystemState::Ready)
		{
			throw std::runtime_error(STR "System is not ready for execution! Invalid state or subsystem container!");
		}

		{
			auto& proto = core->env.getProtocol();
			proto.info(STR "Preparing runtime...");
			const auto stopwatch = std::chrono::high_resolution_clock::now();

			// Dispatch onPrepare()
			for (const auto& sys : core->systems)
			{
				if (sys->events & Event::OnPrepare && !sys->onPrepare(core->env))
				{
					throw std::runtime_error(
						STR "Failed to dispatch 'OnStartup' on system : " + std::string(sys->name));
				}
			}

			proto.info(STR "FinalSubsystems -> {} Interfaces:", core->systems.size());

			// Print info about all final subsystems:
			for (std::size_t i = 0; i < core->systems.size(); ++i)
			{
				const auto& sys = core->systems[i];
				const auto* const type = typeid(decltype(*sys)).name();
				proto.info(
					"\tSubsystem[{}] -> Name: {}, IsLegacy: {}, EventMask: {:08b} Type: {}",
					i,
					sys->name,
					sys->legacy,
					sys->events,
					type);
			}

			const auto bootTime = std::chrono::duration_cast<std::chrono::milliseconds>(
				std::chrono::high_resolution_clock::now() - stopwatch).count();

			proto.success(
				STR "System prepared for executing! PrepareTime: {:.1f}s",
				bootTime / 1000.f);
			proto.success(STR "Executing runtime...");
		}

		// OnPrepare for runtime:
		core->state = SystemState::Online;
		core->systems.shrink_to_fit();
		core->begin = std::chrono::system_clock::now();
		core->trapFlag = true;

		// Engine tick procedure:
		auto tick = [&]
		{
			// Dispatch onTick()
			for (const auto& sys : core->systems)
			{
				if (sys->events & Event::OnTick && !sys->onTick(core->env))
				{
					return false;
				}
			}

			++core->cycles;
			return true;
		};

		// Runtime loop:
		for (;;)
		{
			if (!tick())
			{
				break;
			}
		}

		core->state = SystemState::Ready;
		return core->cycles;
	}

	Kernel::~Kernel()
	{
		if (core->state != SystemState::Ready)
		{
			return;
		}

		const auto end = std::chrono::duration_cast<std::chrono::minutes>(std::chrono::system_clock::now() - core->begin).count();

		core->env.getProtocol().info(STR "Shutting down kernel & subsystems...");
		core->env.getProtocol().info(STR "Uptime: {}h, Cycles: {}", end / 60.f, core->cycles);

		// Dispatch onShutdown()
		for (std::size_t i = core->systems.size() - 1; i -- > 0;)
		{
			const auto& sys = core->systems[i];
			if (sys->events & Event::OnShutdown)
			{
				sys->onShutdown(core->env);
			}
		}
	}

	auto Kernel::getState() const noexcept -> SystemState
	{
		return core->state;
	}

	auto Kernel::getTrapFlag() const noexcept -> bool
	{
		return core->trapFlag;
	}

	void Kernel::interrupt() const noexcept
	{
		core->trapFlag = false;
	}

	auto Kernel::getSystems() const noexcept -> const std::vector<std::unique_ptr<ISubsystem>>&
	{
		return core->systems;
	}

	auto Kernel::getEnvironment() const noexcept -> const Environment&
	{
		return core->env;
	}

	void Kernel::dumpBootInfo() const
	{
		auto& proto = core->env.getProtocol();

		//Print boot info:
		proto.logDump(fmt::format("{:%d.%m.%Y %H:%M:%S}", fmt::localtime(std::time(nullptr))));
		proto.logDump("KESTD Ronin Game Engine (C) Copyright KerboGames(R), Germany 2020! All rights reserved!");
		proto.info(STR "Initializing native engine runtime... Compiler: " COM_NAME " STD: C++20");
		proto.info(STR "EnvironmentSize: {}B", sizeof(Environment));
		proto.info(STR "Booting kernel & subsystems...");
		proto.separator();
	}
}
