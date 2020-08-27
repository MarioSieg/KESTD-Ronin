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
	struct AutoTecTheme final
	{
		enum Theme
		{
			Dark,
			Light,
			Blue,
			Cherry,
			Green,
		} theme;

		float childRounding;
		float frameRounding;
		float grabRounding;
		float popupRounding;
		float scrollbarRounding;
		float tabRounding;
		float windowRounding;
	};

	struct AutoTecConfig final
	{
		std::uint8_t fontSize = 18;
		bool isEnabled = true;
		AutoTecTheme theme;
	};
}
