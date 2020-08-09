// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Security.cpp
// 07.08.2020 02:30
// =============================================================

#include "Security.hpp"

namespace kestd::kernel
{
	auto SecurityManager::LogIn(const User wanted, const Pin pin) noexcept -> bool
	{
		++UserUpdates;
		if (FailedAttempts >= MAX_ATTEMPTS)
		{
			IsLocked = true;
			return !IsLocked;
		}
		if (GetCorrespondingPin(wanted) == pin)
		{
			++SucceededAttempts;
			Current = wanted;
			return true;
		}
		++FailedAttempts;
		return false;
	}

	auto SecurityManager::LogOff() noexcept
	{
		Current = User::Normal;
	}
}
