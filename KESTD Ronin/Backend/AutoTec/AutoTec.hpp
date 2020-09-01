// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// AutoTec.hpp
// 31.08.2020 15:09
// =============================================================

#pragma once

#include "text_editor.h"
#include "../../Frontend/Export/KESTD/Config.hpp"
#include "../../Frontend/Export/KESTD/Environment.hpp"
#include "Script.hpp"

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
		bool showScriptEditor = false;
		void updateAndRender(Environment& env);
		void mainMenu();
		void configEditor(Config& bcfg);
		void diagnosticsProfiler();
		void applyTheme(const AutoTecTheme& theme) const;
		void scriptEditor();
		void scriptEditorPushFile(std::string&& path);
		auto scriptEditorOpenFile() -> bool;
		auto scriptEditorSetScript(std::uint16_t id) -> bool;
		auto scriptEditorSetCurrentScript() -> bool;

	private:
		AutoTecColorTheme currentColorTheme = {};
		TextEditor editor = {};
		std::unordered_map<std::uint16_t, Script> openScripts = {};
		std::uint16_t currentScript = 0;
		std::uint16_t scriptHash = 0;
	};
}
