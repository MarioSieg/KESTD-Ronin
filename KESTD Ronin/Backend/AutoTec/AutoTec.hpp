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
	class AutoTecTheme;
	class BootConfig;
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
		void configEditor(BootConfig& bcfg);
		void diagnosticsProfiler();
		void applyTheme(const AutoTecTheme& theme);
		void styleDark() const noexcept;
		void styleLight() const noexcept;
		void styleCherry() const noexcept;
		void styleBlue() const noexcept;
		void styleGreen() const noexcept;

	private:
		AutoTecColorTheme currentColorTheme;
	};
}
