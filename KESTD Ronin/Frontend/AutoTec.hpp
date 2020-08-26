// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// AutoTec.hpp
// 26.08.2020 00:19
// =============================================================

#pragma once

#include <cstdint>

namespace kestd
{
	enum class AutoTecTheme
	{
		Dark,
		Light,
		Blue,
		Cherry,
		Green,
	};

	struct AutoTecConfig final
	{
		std::uint8_t fontSize = 18;
		bool isEnabled = true;
		AutoTecTheme theme = AutoTecTheme::Dark;
	};
}
