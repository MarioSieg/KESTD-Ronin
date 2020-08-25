// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Environment.cpp
// 09.08.2020 07:24
// =============================================================

#include "Environment.hpp"

namespace kestd
{
	Environment::Environment()
	{
		platform.osInfo.query();
		platform.cpuInfo.query();
		platform.gpuInfos.query();
	}

	Environment::~Environment() = default;
}
