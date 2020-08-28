// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// AutoTec.hpp
// 26.08.2020 10:47
// =============================================================

#pragma once

namespace kestd
{
	class BootConfig;
	class Environment;
}

namespace kestd::detail::systemgui
{
	class AutoTec final
	{
	public:
		void updateAndRender(Environment& env);

	private:
		bool showSettingsEditor = false;
		void mainMenu();
		void configEditor(BootConfig& bcfg);
	};
}
