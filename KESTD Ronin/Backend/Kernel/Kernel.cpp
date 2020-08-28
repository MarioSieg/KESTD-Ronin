// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Kernel.cpp
// 09.08.2020 10:43
// =============================================================

#include "Kernel.hpp"
#include "LegacySubsystemBuilder.hpp"
#include "../../Frontend/PlatformInfo.hpp"
#include "../../Frontend/Environment.hpp"
#include <fmt/core.h>
#include <chrono>

namespace kestd::kernel
{
	struct Kernel::Pimpl final
	{
		volatile bool trapFlag = false;
		SystemState state = SystemState::Offline;
		std::vector<std::unique_ptr<ISubsystem>> systems = {};
		std::tuple<std::string, std::string> info = {};
		SecurityManager securityManager;
		Environment env = {};
	};

	Kernel::Kernel(std::string&& appName, std::string&& companyName, const User usr, const Pin pin) : core(
		std::make_unique<Pimpl>())
	{
		core->info = std::make_tuple(std::move(appName), std::move(companyName));

		// Setup stopwatch:
		const auto stopwatch = std::chrono::high_resolution_clock::now();

		// Fetch environment data:
		auto& proto = core->env.getProtocol();
		const auto& platformInfo = core->env.getPlatformInfo();

		// Write engine info to protocol:
		dumpBootInfo();
		proto << "[Kernel] Booting kernel & subsystems...";

		// Allocate subsystems and dispatch onStartup() event:
		InitializeLegacySubsystens({ core->env.getBootConfig(), core->env, core->systems });
		// Create and initialize subsystems

		// Dispatch onStartup()
		for (const auto& sys : core->systems)
		{
			if (sys->events & Event::OnStartup && !sys->onStartup(core->env))
			{
				throw std::runtime_error("[Kernel] Failed to dispatch 'OnStartup' on system: " + sys->name);
			}
		}

		// Calculate boot time and print it:
		const auto bootTime = std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::high_resolution_clock::now() - stopwatch).count();
		proto % fmt::format("[Kernel] System online! BootTime: {:.1f}s", bootTime / 1000.f);

		// System is ready now:
		core->state = SystemState::Ready;
	}

	auto Kernel::execute() const -> std::uint32_t
	{
		// Check if system is ready:
		if (core->systems.empty() || core->state != SystemState::Ready)
		{
			throw std::runtime_error("System is not ready for execution! Invalid state or subsystem container!");
		}

		{
			auto& proto = core->env.getProtocol();
			proto << "[Kernel] Preparing runtime...";
			const auto stopwatch = std::chrono::high_resolution_clock::now();

			// Dispatch onPrepare()
			for (const auto& sys : core->systems)
			{
				if (sys->events & Event::OnPrepare && !sys->onPrepare(core->env))
				{
					throw std::runtime_error("[Kernel] Failed to dispatch 'OnStartup' on system : " + sys->name);
				}
			}

			proto >> fmt::format("FinalSubsystems -> {} Interfaces:", core->systems.size());

			// Print info about all final subsystems:
			for (std::size_t i = 0; i < core->systems.size(); ++i)
			{
				const auto& sys = core->systems[i];
				const auto* const type = typeid(decltype(*sys)).name();
				proto >> fmt::format("\tSubsystem[{}] -> Name: {}, IsLegacy: {}, EventMask: {:08b} Type: {}",
				                     i,
				                     sys->name,
				                     sys->isLegacy,
				                     sys->events,
				                     type);
			}

			const auto bootTime = std::chrono::duration_cast<std::chrono::milliseconds>(
				std::chrono::high_resolution_clock::now() - stopwatch).count();

			proto % fmt::format("[Kernel] System prepared for executing! PrepareTime: {:.1f}s", bootTime / 1000.f);
			proto % "[Kernel] Executing runtime...";
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

		core->env.getProtocol() << "Shutting down kernel & subsystems...";

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

	void Kernel::dumpBootInfo() const
	{
		auto& protocol = core->env.getProtocol();

		//Print boot info:
		protocol <<
			"KESTD Ronin Game Engine (C) Copyright KerboGames(R), Germany 2020! All rights reserved!";
		protocol << "[Kernel] Initializing native engine runtime...";
		protocol << "[Kernel] Compiler: " COM_NAME;
		protocol << "[Kernel] STD: C++20";
		protocol << fmt::format("[Kernel] KernelSize: {}B", sizeof(Kernel) + sizeof(Pimpl));
		protocol << fmt::format("[Kernel] SystemSize: {}B", sizeof(Environment));
		protocol << fmt::format("[Kernel] EngineSize: {}B", sizeof(Environment) + sizeof(Kernel) + sizeof(Pimpl));
	}
}
