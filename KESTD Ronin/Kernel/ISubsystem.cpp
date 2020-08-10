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
	ISubsystem::ISubsystem(std::string&& name, const bool isLegacy) noexcept
		: name(std::move(name)), isLegacy(isLegacy), callbacks()
	{
	}

	auto ISubsystem::onStartup(Sys&) -> bool
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

	void ISubsystem::onShutdown(Sys&)
	{
	}
}
