// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Subsystem.cpp
// 07.08.2020 02:30
// =============================================================

#include "Subsystem.hpp"

#include <utility>

namespace kestd::kernel
{
	ISubsystem::ISubsystem(std::string name,
	                       const std::underlying_type<Event::Enum>::type events,
	                       const bool is_legacy) noexcept
		: Name(std::move(name)), SubscribedEvents(events), IsLegacy(is_legacy)
	{
	}

	auto ISubsystem::OnPreStartup(Sys&) -> bool
	{
		return true;
	}

	auto ISubsystem::OnPostStartup(Sys&) -> bool
	{
		return true;
	}

	auto ISubsystem::OnPreTick(Sys&) -> bool
	{
		return true;
	}

	auto ISubsystem::OnPostTick(Sys&) -> bool
	{
		return true;
	}

	void ISubsystem::OnPreShutdown(Sys&)
	{
	}

	void ISubsystem::OnPostShutdown(Sys&)
	{
	}
}
