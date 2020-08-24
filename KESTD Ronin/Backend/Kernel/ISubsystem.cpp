// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// ISubsystem.cpp
// 09.08.2020 10:43
// =============================================================

#include "ISubsystem.hpp"

#include <utility>

namespace kestd::kernel
{
	ISubsystem::ISubsystem(std::string&& name, const bool isLegacy, const Event::Enum events) noexcept
		: name(std::move(name)), isLegacy(isLegacy), events(events)
	{
	}

	auto ISubsystem::onStartup(Sys&) -> bool
	{
		return true;
	}

	auto ISubsystem::onTick(Sys&) -> bool
	{
		return true;
	}

	void ISubsystem::onShutdown(Sys&)
	{
	}
}
