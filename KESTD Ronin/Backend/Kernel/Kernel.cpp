// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Kernel.cpp
// 30.08.2020 12:40
// =============================================================

#include "Kernel.hpp"
#include "../LegacySubsystemBuilder.hpp"
#include "../../Frontend/Export/KESTD/Platform.hpp"
#include "../../Frontend/Export/KESTD/Environment.hpp"
#include <fmt/core.h>
#include <chrono>

#define STR "[Kernel] "

namespace kestd::kernel
{
	class Kernel::Pimpl final
	{
	public:
		volatile bool trapFlag = false;
		SystemState state = SystemState::Offline;
		std::vector<std::unique_ptr<ISubsystem>> systems = {};
		std::tuple<std::string, std::string> info = {};
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
		proto.info(STR "Booting kernel & subsystems...");

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
		core->trapFlag = true;
		std::uint32_t cycles = 0;

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

			++cycles;
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
		return cycles;
	}

	Kernel::~Kernel()
	{
		if (core->state != SystemState::Ready)
		{
			return;
		}

		core->env.getProtocol().info(STR "Shutting down kernel & subsystems...");

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
		auto& protocol = core->env.getProtocol();

		//Print boot info:
		protocol.logDump("KESTD Ronin Game Engine (C) Copyright KerboGames(R), Germany 2020! All rights reserved!");
		protocol.info(
			STR "Initializing native engine runtime... Compiler: " COM_NAME " STD: C++20");
		protocol.info(STR "KernelSize: {}B", sizeof(Kernel) + sizeof(Pimpl));
		protocol.info(STR "SystemSize: {}B", sizeof(Environment));
		protocol.info(
			STR "EngineSize: {}B",
			sizeof(Environment) + sizeof(Kernel) + sizeof(Pimpl));
	}
}
