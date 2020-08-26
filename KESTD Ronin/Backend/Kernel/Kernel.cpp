// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Kernel.cpp
// 09.08.2020 10:43
// =============================================================

#include "Kernel.hpp"
#include "../../Frontend/PlatformInfo.hpp"
#include "../../Frontend/Environment.hpp"
#include <fmt/core.h>
#include <chrono>

namespace kestd::kernel
{
	extern void InitializeLegacySubsystens(const BootConfig& cfg, std::vector<std::unique_ptr<ISubsystem>>&);

	struct Kernel::Pimpl final
	{
		bool isLocked = false;
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
		auto& protocol = core->env.getProtocol();
		const auto& platformInfo = core->env.getPlatformInfo();

		// Write engine info to protocol:
		dumpBootInfo();
		protocol << "[Kernel] Booting kernel & subsystems...";

		// Allocate subsystems and dispatch onStartup() event:
		InitializeLegacySubsystens(core->env.getBootConfig(), core->systems); // Create and initialize subsystems

		// TODO move this into utility subsystem!
		// Perform system analysis and dump it into the protocol:
		protocol << "[Kernel] Performing system analysis...";
		core->env.refreshBootStages();
		protocol ^ platformInfo.osInfo.toStr();
		protocol ^ platformInfo.cpuInfo.toStr();
		protocol ^ platformInfo.gpuInfos.toStr();
		protocol ^ platformInfo.peripheryInfo.toStr();

		// Dispatch onStartup()
		for (const auto& sys : core->systems)
		{
			if (sys->events & Event::Startup && !sys->onStartup(core->env))
			{
				protocol & "[Kernel] Failed to dispatch 'OnPreStartup' on system: " + sys->name;
				break;
			}
		}

		// Calculate boot time and print it:
		const auto bootTime = std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::high_resolution_clock::now() - stopwatch).count();
		protocol % fmt::format("[Kernel] System online! BootTime: {:.1f}s", bootTime / 1000.f);

		// System is ready now:
		core->state = SystemState::Ready;
	}

	auto Kernel::execute() const -> std::tuple<bool, uint32_t>
	{
		// Check if system is ready:
		if (core->systems.empty() || core->state != SystemState::Ready)
		{
			core->env.getProtocol() & "System is not ready for execution! Invalid state or subsystem container!";
			return std::make_tuple(false, 0);
		}

		core->env.getProtocol() % "[Kernel] Executing runtime...";

		// TODO move this into utility subsystem!
		{
			auto& proto = core->env.getProtocol();
			proto >> fmt::format("Compressing protocol... Streamcapacity: {}, Length: {}",
			                     proto.getBuffer().capacity(),
			                     proto.getBuffer().size());
			// Compress all logged messages to minimize memory usage:
			proto.compressMessages();
		}

		// Prepare for runtime:
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
				if (sys->events & Event::Tick && !sys->onTick(core->env))
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
		return std::make_tuple(true, cycles);
	}

	Kernel::~Kernel()
	{
		if (core->state != SystemState::Ready)
		{
			return;
		}

		// Dispatch onShutdown()
		for (std::size_t i = core->systems.size() - 1; i; --i)
		{
			const auto& sys = core->systems[i];
			if (sys->events & Event::Shutdown)
			{
				sys->onShutdown(core->env);
			}
		}

		core->env.getProtocol().flush();
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
		auto& platform = core->env.getPlatformInfo();

		//Print boot info:
		protocol <<
			"KESTD Ronin Game Engine (C) Copyright KerboGames(R), Germany 2020! All rights reserved!";
		protocol << "[Kernel] Initializing native engine runtime...";
		protocol << "[Kernel] Compiler: " COM_NAME;
		protocol << "[Kernel] STD: C++20";
		protocol << fmt::format("[Kernel] WorkingDir: \"{}\"", std::filesystem::current_path().string());
		protocol << fmt::format("[Kernel] KernelSize: {}B", sizeof(Kernel) + sizeof(Pimpl));
		protocol << fmt::format("[Kernel] SystemSize: {}B", sizeof(Environment));
		protocol << fmt::format("[Kernel] EngineSize: {}B", sizeof(Environment) + sizeof(Kernel) + sizeof(Pimpl));
	}
}
