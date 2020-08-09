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
		auto Initialize() -> bool;
		void Shutdown();

		void BeginGui();
		void EndGui();
		void Begin();
		void End();

		SystemGui SysGui = {};
	};
}
