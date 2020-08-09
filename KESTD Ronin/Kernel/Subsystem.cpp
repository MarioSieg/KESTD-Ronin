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
	                       const bool isLegacy) noexcept
		: name(std::move(name)), subscribedEvents(events), isLegacy(isLegacy)
	{
	}

	auto ISubsystem::onPreStartup(Sys&) -> bool
	{
		return true;
	}

	auto ISubsystem::onPostStartup(Sys&) -> bool
	{
		return true;
	}

	auto ISubsystem::onPreTick(Sys&) -> bool
	{
		return true;
	}

	auto ISubsystem::onPostTick(Sys&) -> bool
	{
		return true;
	}

	void ISubsystem::onPreShutdown(Sys&)
	{
	}

	void ISubsystem::onPostShutdown(Sys&)
	{
	}
}
