// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// ISubsystem.cpp
// 30.08.2020 12:40
// =============================================================

#include "ISubsystem.hpp"

#include <utility>

namespace kestd::kernel
{
	ISubsystem::ISubsystem(std::string&& name,
	                       const bool isLegacy,
	                       const std::underlying_type<Event::Enum>::type events) noexcept
		: name(std::move(name)), isLegacy(isLegacy), events(events)
	{
	}

	auto ISubsystem::onStartup(Environment&) -> bool
	{
		return true;
	}

	auto ISubsystem::onPrepare(Environment&) -> bool
	{
		return true;
	}

	auto ISubsystem::onTick(Environment&) -> bool
	{
		return true;
	}

	void ISubsystem::onShutdown(Environment&)
	{
	}
}
