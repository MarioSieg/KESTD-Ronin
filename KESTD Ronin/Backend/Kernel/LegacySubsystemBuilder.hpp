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
	struct LegacySubsystemBuildDescriptor final
	{
		const BootConfig& cfg;
		Environment& env;
		std::vector<std::unique_ptr<ISubsystem>>& sysref;
	};
	
	extern void InitializeLegacySubsystens(LegacySubsystemBuildDescriptor desc);

	template<typename T, typename... Args> requires std::is_base_of_v<ISubsystem, T>
	extern void PushSubsystem(LegacySubsystemBuildDescriptor desc, Args&&... args);
}
