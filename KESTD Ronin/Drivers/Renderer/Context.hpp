// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Context.hpp
// 08.08.2020 00:21
// =============================================================

#pragma once

#include "../SystemGui/SystemGui.hpp"

namespace kestd
{
	class Logger;
}

namespace kestd::drivers
{
	class RenderContext final
	{
	public:
		auto initialize() -> bool;
		void shutdown();

		void beginGui();
		void endGui();
		void begin();
		void end();

		SystemGui sysGui = {};
	};
}
