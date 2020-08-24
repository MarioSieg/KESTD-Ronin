// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Sys.cpp
// 09.08.2020 07:24
// =============================================================

#include "Sys.hpp"

namespace kestd
{
	Sys::Sys()
	{
		platform.osInfo.query();
		platform.cpuInfo.query();
		platform.gpuInfos.query();
	}
}
