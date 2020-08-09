// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Kernel.cpp
// 07.08.2020 02:30
// =============================================================

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

		// Dispatch OnPreStartup()
		for (std::size_t i = 0; i < Core->Systems.size(); ++i)
		{
			const auto& sys = Core->Systems[i];
			if (sys->SubscribedEvents & Event::OnPreStartup != 0 && !sys->OnPreStartup(Core->Sys))
			{
				Core->Sys.Protocol & "[Kernel] Failed to dispatch 'OnPreStartup' on system: " + sys->Name;
				return false;
			}
		}

		// Dispatch OnPostStartup()
		for (std::size_t i = Core->Systems.size() - 1; i > 0; --i)
		{
			const auto& sys = Core->Systems[i];
			if ((sys->SubscribedEvents & Event::OnPostShutdown) != 0 && !sys->OnPostStartup(Core->Sys))
			{
				Core->Sys.Protocol & "[Kernel] Failed to dispatch 'OnPostStartup' on system: " + sys->Name;
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
			// Dispatch OnPreTick()
			for (std::size_t i = 0; i < Core->Systems.size(); ++i)
			{
				const auto& sys = Core->Systems[i];
				if ((sys->SubscribedEvents & Event::OnPreTick) != 0 && !sys->OnPreTick(Core->Sys))
				{
					return false;
				}
			}

			// Dispatch OnPostTick()
			for (std::size_t i = Core->Systems.size() - 1; i > 0; --i)
			{
				const auto& sys = Core->Systems[i];
				if ((sys->SubscribedEvents & Event::OnPostTick) != 0 && !sys->OnPostTick(Core->Sys))
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
		Core->Sys.Protocol << "KESTD Ronin Game Engine (C) Copyright KerboGames(R), Germany 2020! All rights reserved!";
		Core->Sys.Protocol << "[Kernel] Initializing native engine C++ runtime...";
		Core->Sys.Protocol << "[Kernel] Engine Kernel Size: " + std::to_string(sizeof(Kernel) + sizeof(Pimpl)) + "B";
		Core->Sys.Protocol << "[Kernel] Running on: " SYS_NAME;
		Core->Sys.Protocol << "[Kernel] Compiled with: " COM_NAME;
		Core->Sys.Protocol << Core->Sys.Platform.OsInfo;
		Core->Sys.Protocol << Core->Sys.Platform.CpuInfo;
		Core->Sys.Protocol << Core->Sys.Platform.GpuInfos;
	}

	Kernel::~Kernel()
	{
		if (Core->State != SystemState::Ready)
		{
			return;
		}

		// Dispatch OnPreShutdown()
		for (std::size_t i = 0; i < Core->Systems.size(); ++i)
		{
			const auto& sys = Core->Systems[i];
			if ((sys->SubscribedEvents & Event::OnPreShutdown) != 0)
			{
				sys->OnPreShutdown(Core->Sys);
			}
		}

		// Dispatch OnPostShutdown()
		for (std::size_t i = Core->Systems.size() - 1; i > 0; --i)
		{
			const auto& sys = Core->Systems[i];
			if ((sys->SubscribedEvents & Event::OnPostShutdown) != 0)
			{
				sys->OnPostShutdown(Core->Sys);
			}
		}
	}
} // namespace kestd::kernel // namespace kestd::kernel
