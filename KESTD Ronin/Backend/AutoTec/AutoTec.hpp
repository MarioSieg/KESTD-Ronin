// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// AutoTec.hpp
// 26.08.2020 10:47
// =============================================================

#pragma once

namespace kestd
{
	class ConfigAutoTec;
	class Config;
	class Environment;
	enum class AutoTecColorTheme;
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
		void applyTheme(const ConfigAutoTec& theme) const;

	private:
		AutoTecColorTheme currentColorTheme;
	};
}
