// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// KernelStats.cpp
// 31.08.2020 15:10
// =============================================================

#include "Export/KESTD/KernelStats.hpp"

namespace kestd
{
	auto SubsystemStats::getInitializeTime() const noexcept -> float
	{
		return initializeTime;
	}

	auto SubsystemStats::getPrepareTime() const noexcept -> float
	{
		return prepareTime;
	}

	auto SubsystemStats::getTickTime() const noexcept -> float
	{
		return tickTime;
	}

	auto SubsystemStats::getShutdownTime() const noexcept -> float
	{
		return shutdownTime;
	}

	auto SubsystemStats::getDeinitializeTime() const noexcept -> float
	{
		return deinitializeTime;
	}
}
