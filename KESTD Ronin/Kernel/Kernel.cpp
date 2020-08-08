// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD Ronin
// Mario
// Kernel.cpp
// 07.08.2020 02:30

#include "Kernel.hpp"

#include "../Platform.hpp"
#include "../Sys.hpp"

namespace kestd::kernel
{
	extern void QueryLegacySubsystems(std::vector<std::unique_ptr<ISubsystem>>&);

	struct Kernel::Pimpl final
	{
		bool IsLocked = false;
		volatile bool TrapFlag = false;
		SystemState State = SystemState::Offline;
		std::vector<std::unique_ptr<ISubsystem>> Systems = {};
		std::tuple<std::string, std::string> Info = {};
		SecurityManager SecurityManager;
		Sys Sys = {};
	};

	auto Kernel::Startup(const User usr, const Pin pin) const -> bool
	{
		if (Core->Systems.empty() || Core->State != SystemState::Offline)
		{
			return false;
		}

		if (!Core->SecurityManager.LogIn(usr, pin))
		{
			return false;
		}

		Core->IsLocked = true;

		for (const auto& sys : Core->Systems)
		{
			if ((sys->SubscribedEvents & Event::PreStartup) != 0 && !sys->OnPreStartup(Core->Sys))
			{
				Core->Sys.Logger & "[Kernel] Failed to dispatch 'OnPreStartup' on system: " + sys->Name;
				return false;
			}
		}

		for (const auto& sys : Core->Systems)
		{
			if ((sys->SubscribedEvents & Event::PostShutdown) != 0 && !sys->OnPostStartup(Core->Sys))
			{
				Core->Sys.Logger & "[Kernel] Failed to dispatch 'OnPostStartup' on system: " + sys->Name;
				return false;
			}
		}

		Core->State = SystemState::Ready;

		return true;
	}

	auto Kernel::Execute() const -> std::tuple<bool, uint32_t>
	{
		if (Core->Systems.empty() || Core->State != SystemState::Ready)
		{
			return std::make_tuple(false, 0);
		}

		Core->Systems.shrink_to_fit();
		Core->TrapFlag = true;
		uint32_t cycles = 0;

		auto tick = [&]
		{
			for (const auto& sys : Core->Systems)
			{
				if ((sys->SubscribedEvents & Event::PreTick) != 0 && !sys->OnPreTick(Core->Sys))
				{
					return false;
				}
			}
			for (const auto& sys : Core->Systems)
			{
				if ((sys->SubscribedEvents & Event::PostTick) != 0 && !sys->OnPostTick(Core->Sys))
				{
					return false;
				}
			}
			return true;
		};

		while (Core->TrapFlag && tick())
		{
			++cycles;
		}

		Core->State = SystemState::Ready;
		return std::make_tuple(true, cycles);
	}

	auto Kernel::GetState() const noexcept -> SystemState
	{
		return Core->State;
	}

	auto Kernel::GetTrapFlag() const noexcept -> bool
	{
		return Core->TrapFlag;
	}

	auto Kernel::Interrupt() const noexcept
	{
		Core->TrapFlag = false;
	}

	auto Kernel::GetSystems() const noexcept -> const std::vector<std::unique_ptr<ISubsystem>>&
	{
		return Core->Systems;
	}

	Kernel::Kernel(std::string&& appName, std::string&& companyName) : Core(std::make_unique<Pimpl>())
	{
		Core->Info = std::make_tuple(std::move(appName), std::move(companyName));
		QueryLegacySubsystems(Core->Systems);
		Core->Sys.Logger << "KESTD Ronin Game Engine (C) Copyright KerboGames(R), Germany 2020! All rights reserved!";
		Core->Sys.Logger << "[Kernel] Initializing native engine C++ runtime...";
		Core->Sys.Logger << "[Kernel] Engine Kernel Size: " + std::to_string(sizeof(Kernel) + sizeof(Pimpl)) + "B";
		Core->Sys.Logger << "[Kernel] Running on: " SYS_NAME;
		Core->Sys.Logger << "[Kernel] Compiled with: " COM_NAME;
		Core->Sys.Logger << Core->Sys.Platform.OsInfo;
		Core->Sys.Logger << Core->Sys.Platform.CpuInfo;
		Core->Sys.Logger << Core->Sys.Platform.GpuInfos;
	}

	Kernel::~Kernel()
	{
		if (Core->State != SystemState::Ready)
		{
			return;
		}

		for (const auto& sys : Core->Systems)
		{
			if ((sys->SubscribedEvents & Event::PreShutdown) != 0)
			{
				sys->OnPreShutdown(Core->Sys);
			}
		}
		for (const auto& sys : Core->Systems)
		{
			if ((sys->SubscribedEvents & Event::PostShutdown) != 0)
			{
				sys->OnPostShutdown(Core->Sys);
			}
		}
	}
} // namespace kestd::kernel // namespace kestd::kernel
