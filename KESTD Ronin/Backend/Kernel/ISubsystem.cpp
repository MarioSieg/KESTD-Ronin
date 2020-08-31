// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// ISubsystem.cpp
// 31.08.2020 15:09
// =============================================================

#include "ISubsystem.hpp"

namespace kestd::kernel
{
	ISubsystem::ISubsystem(const std::string_view name,
	                       const bool isLegacy,
	                       const EventFlags events) noexcept
		: name(name), legacy(isLegacy), events(events)
	{
	}

	auto ISubsystem::getName() const noexcept -> std::string_view
	{
		return name;
	}

	auto ISubsystem::isLegacy() const noexcept -> bool
	{
		return legacy;
	}

	auto ISubsystem::getEventFlags() const noexcept -> EventFlags
	{
		return events;
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
