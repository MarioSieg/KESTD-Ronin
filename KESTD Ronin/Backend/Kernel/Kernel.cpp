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
		Environment sys = {};
	};

	Kernel::Kernel(std::string&& appName, std::string&& companyName, const User usr, const Pin pin) : core(
		std::make_unique<Pimpl>())
	{
		core->info = std::make_tuple(std::move(appName), std::move(companyName));
		const auto stopwatch = std::chrono::high_resolution_clock::now();
		auto& protocol = core->sys.getProtocol();
		protocol | "Booting kernel & subsystems...";
		InitializeLegacySubsystens(core->sys.getBootConfig(), core->systems); // Create and initialize subsystems
		for (const auto& sys : core->systems)                                 // Dispatch onStartup()
		{
			if (sys->events & Event::Startup && !sys->onStartup(core->sys))
			{
				protocol & "[Kernel] Failed to dispatch 'OnPreStartup' on system: " + sys->name;
				break;
			}
		}
		dumpInfo();
		const auto bootTime = std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::high_resolution_clock::now() - stopwatch).count();
		protocol % fmt::format("System online! BootTime: {}s", bootTime / 1000.f);
		core->state = SystemState::Ready;
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
				sys->onShutdown(core->sys);
			}
		}
	}

	auto Kernel::execute() const -> std::tuple<bool, uint32_t>
	{
		if (core->systems.empty() || core->state != SystemState::Ready)
		{
			return std::make_tuple(false, 0);
		}

		core->systems.shrink_to_fit();
		core->trapFlag = true;
		std::uint32_t cycles = 0;

		auto tick = [&]
		{
			// Dispatch onTick()
			for (const auto& sys : core->systems)
			{
				if (sys->events & Event::Tick && !sys->onTick(core->sys))
				{
					return false;
				}
			}

			++cycles;
			return true;
		};

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

	void Kernel::dumpInfo() const
	{
		auto& protocol = core->sys.getProtocol();
		auto& platform = core->sys.getPlatformInfo();

		protocol <<
			"KESTD Ronin Game Engine (C) Copyright KerboGames(R), Germany 2020! All rights reserved!";
		protocol << "[Kernel] Initializing native engine runtime...";
		protocol << "[Kernel] Compiler: " COM_NAME;
		protocol << "[Kernel] STD: C++20";
		protocol << fmt::format("[Kernel] WorkingDir: \"{}\"", std::filesystem::current_path().string());
		protocol << fmt::format("[Kernel] KernelSize: {}B", sizeof(Kernel) + sizeof(Pimpl));
		protocol << fmt::format("[Kernel] SystemSize: {}B", sizeof(Environment));
		protocol << fmt::format("[Kernel] EngineSize: {}B", sizeof(Environment) + sizeof(Kernel) + sizeof(Pimpl));
		protocol ^ platform.osInfo.toStr();
		protocol ^ platform.cpuInfo.toStr();
		protocol ^ platform.gpuInfos.toStr();
	}
}
