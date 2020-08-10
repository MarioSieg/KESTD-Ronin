// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Kernel.cpp
// 09.08.2020 10:43
// =============================================================

#include "Kernel.hpp"
#include "../Platform.hpp"
#include "../Sys.hpp"

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

		// Dispatch OnStartup()
		for (std::size_t i = 0; i < core->systems.size(); ++i)
		{
			const auto& sys = core->systems[i];
			if (sys->callbacks.onStartup && !sys->onStartup(core->sys))
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

		// Dispatch OnShutdown()
		for (std::size_t i = core->systems.size() - 1; i; --i)
		{
			const auto& sys = core->systems[i];
			if (sys->callbacks.onShutdown)
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
			// Dispatch OnPreTick()
			for (std::size_t i = 0; i < core->systems.size(); ++i)
			{
				const auto& sys = core->systems[i];
				if (sys->callbacks.onPreTick && !sys->onPreTick(core->sys))
				{
					return false;
				}
			}

			// Dispatch OnPostTick()
			for (std::size_t i = core->systems.size() - 1; i; --i)
			{
				const auto& sys = core->systems[i];
				if (sys->callbacks.onPostTick && !sys->onPostTick(core->sys))
				{
					return false;
				}
			}
			return true;
		};

		while (core->trapFlag && tick())
		{
			++cycles;
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
		core->sys.protocol << "[Kernel] Initializing native engine C++ runtime...";
		core->sys.protocol << "[Kernel] Engine Kernel Size: " + std::to_string(sizeof(Kernel) + sizeof(Pimpl)) +
			"B";
		core->sys.protocol << "[Kernel] Running on: " SYS_NAME;
		core->sys.protocol << "[Kernel] Compiled with: " COM_NAME;
		core->sys.protocol << core->sys.platform.osInfo;
		core->sys.protocol << core->sys.platform.cpuInfo;
		core->sys.protocol << core->sys.platform.gpuInfos;
	}
}
