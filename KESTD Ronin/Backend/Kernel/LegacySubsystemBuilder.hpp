// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// LegacySubsystemBuilder.hpp
// 28.08.2020 01:57
// =============================================================

#pragma once

#include "ISubsystem.hpp"

namespace kestd::kernel
{
	extern void InitializeLegacySubsystens(const BootConfig& cfg,
	                                       Environment& env,
	                                       std::vector<std::unique_ptr<ISubsystem>>&);
}
