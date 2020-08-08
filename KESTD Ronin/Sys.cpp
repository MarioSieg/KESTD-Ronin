// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD Ronin
// Mario
// Sys.cpp
// 07.08.2020 14:21

#include "Sys.hpp"

namespace kestd
{
	Sys::Sys(): Logger(1024), Screen{0, 0}
	{
		Platform.OsInfo.query();
		Platform.CpuInfo.query();
		Platform.GpuInfos.query();
	}
}
