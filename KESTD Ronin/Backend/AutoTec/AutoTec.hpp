// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// AutoTec.hpp
// 31.08.2020 15:09
// =============================================================

#pragma once

namespace kestd
{
	class AutoTecTheme;
	class Config;
	enum class AutoTecColorTheme;
	class Environment;
}

namespace kestd
{
	class AutoTec final
	{
	public:
		AutoTec() noexcept;
		AutoTec(const AutoTec&) = delete;
		AutoTec(AutoTec&&) = delete;
		AutoTec& operator=(const AutoTec&) = delete;
		AutoTec& operator=(AutoTec&&) = delete;
		~AutoTec() = default;

		bool showSettingsEditor = false;
		bool showDiagnosticsProfiler = false;
		void updateAndRender(Environment& env);
		void mainMenu();
		void configEditor(Config& bcfg);
		void diagnosticsProfiler();
		void applyTheme(const AutoTecTheme& theme) const;

	private:
		AutoTecColorTheme currentColorTheme;
	};
}
