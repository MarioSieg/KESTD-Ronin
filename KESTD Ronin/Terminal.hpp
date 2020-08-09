// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Terminal.hpp
// 09.08.2020 01:59
// =============================================================

#pragma once

namespace kestd
{
	struct Terminal final
	{
		static constexpr auto MAX_COMMAND_LEN = 64;

		bool DisplayTerminal = true;
		bool AutoScroll = true;
		bool AutoFocus = true;
	};
}
