// =============================================================
// � Copyright KerboGames�, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Kernel.cpp
// 09.08.2020 10:43
// =============================================================

#include "Kernel.hpp"
#include "../../Frontend/Platform.hpp"
#include "../../Frontend/Sys.hpp"
#include <fmt/core.h>

namespace kestd::kernel
{
	extern void queryLegacySubsystems(std::vector<std::unique_ptr<ISubsystem>>&);

	struct Kernel::Pimpl final
	{
		bool isLocked = false;
		volatile bool trapFlag = false;
		SystemState state = SystemState::Offline;
		std::vector<std::unique_ptr<ISubsystem>> systems = {};
		std::tuple<std::string, std::string> info = {};
		SecurityManager securityManager;
		Sys sys = {};
	};


	Kernel::Kernel(std::string&& appName, std::string&& companyName, const User usr, const Pin pin) : core(
		std::make_unique<Pimpl>())
	{
		core->info = std::make_tuple(std::move(appName), std::move(companyName));
		queryLegacySubsystems(core->systems);

		// Dispatch onStartup()
		for (const auto& sys : core->systems)
		{
			if (sys->events & Event::Startup && !sys->onStartup(core->sys))
			{
				core->sys.protocol & "[Kernel] Failed to dispatch 'OnPreStartup' on system: " + sys->name;
				break;
			}
		}

		dumpInfo();
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
		uint32_t cycles = 0;

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

		for(;;)
		{
			if(!tick())
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
		core->sys.protocol <<
			"KESTD Ronin Game Engine (C) Copyright KerboGames(R), Germany 2020! All rights reserved!";
		core->sys.protocol << "[Kernel] Initializing native engine runtime...";
		core->sys.protocol << "[Kernel] Compiler: " COM_NAME;
		core->sys.protocol << "[Kernel] STD: C++20";
		core->sys.protocol << fmt::format("[Kernel] WorkingDir: \"{}\"", std::filesystem::current_path().string());
		core->sys.protocol << fmt::format("[Kernel] KernelSize: {}B", sizeof(Kernel) + sizeof(Pimpl));
		core->sys.protocol << fmt::format("[Kernel] SystemSize: {}B", sizeof(Sys));
		core->sys.protocol << fmt::format("[Kernel] EngineSize: {}B", sizeof(Sys) + sizeof(Kernel) + sizeof(Pimpl));
		core->sys.protocol ^ core->sys.platform.osInfo.toStr();
		core->sys.protocol ^ core->sys.platform.cpuInfo.toStr();
		core->sys.protocol ^ core->sys.platform.gpuInfos.toStr();
	}
}