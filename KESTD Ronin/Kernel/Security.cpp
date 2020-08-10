// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Security.cpp
// 09.08.2020 07:25
// =============================================================

#include "Security.hpp"

namespace kestd::kernel
{
	auto SecurityManager::logIn(const User wanted, const Pin pin) noexcept -> bool
	{
		++userUpdates;
		if (failedAttempts >= MAX_ATTEMPTS)
		{
			isLocked = true;
			return !isLocked;
		}
		if (getCorrespondingPin(wanted) == pin)
		{
			++succeededAttempts;
			current = wanted;
			return true;
		}
		++failedAttempts;
		return false;
	}

	auto SecurityManager::logOff() noexcept
	{
		current = User::Normal;
	}
}
