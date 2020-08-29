// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// BootConfig.hpp
// 29.08.2020 13:43
// =============================================================

#pragma once

#include "ConfigAutoTec.hpp"
#include "IO.hpp"

namespace kestd
{
	class BootConfig final
	{
	public:
		AutoTecConfig autoTec;
		IOConfig io;
	};
}
