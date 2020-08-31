// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// AutoTec.cpp
// 31.08.2020 15:09
// =============================================================

#include "AutoTec.hpp"
#include "Style.hpp"
#include <fstream>
#include <fontawesome/icons_font_awesome5.h>
#include <imgui.h>
#include <implot.h>
#include <text_editor.h>
#include <nfd.h>

using namespace ImGui;

/*
 * Normally we are using std::string and std::string_view but in AutoTec
 * we use C-Strings (char*, char[x]) for small strings, because ImGui is using them and converting from and to std::string
 * and calling .data() all the time is really annoying. Also using a char array is just faster sometimes because we do not need any
 * heap allocations. For big strings like scripts we still use std::string.
 * The different string types might be annoying, but it's only here in AutoTec.
 * The rest of the engine is still very modern C++ 20!
 */

namespace kestd
{
	AutoTec::AutoTec() noexcept : currentColorTheme(AutoTecColorTheme::Dark)
	{
		StyleDark();
		StyleRoundingAngular();
		editor.SetLanguageDefinition(TextEditor::LanguageDefinition::Lua());
	}

	void AutoTec::updateAndRender(Environment& env)
	{
		mainMenu();
		if (showSettingsEditor)
		{
			configEditor(env.getBootConfig());
		}
		if (showDiagnosticsProfiler)
		{
			diagnosticsProfiler();
		}
		if (showScriptEditor)
		{
			scriptEditor();
		}
	}

	void AutoTec::mainMenu()
	{
		if (BeginMainMenuBar())
		{
			if (BeginMenu("File"))
			{
				EndMenu();
			}
			if (BeginMenu("Edit"))
			{
				EndMenu();
			}
			if (BeginMenu("Project"))
			{
				EndMenu();
			}
			if (BeginMenu("Scenery"))
			{
				EndMenu();
			}
			if (BeginMenu("Scripts"))
			{
				EndMenu();
			}
			if (BeginMenu("DB"))
			{
				EndMenu();
			}
			if (BeginMenu("Tools"))
			{
				if (MenuItem(ICON_FA_CODE " ScriptEditor"))
				{
					showScriptEditor = true;
				}

				if (MenuItem(ICON_FA_CHART_AREA " Diagnostics"))
				{
					showDiagnosticsProfiler = true;
				}

				if (MenuItem(ICON_FA_COG " Settings"))
				{
					showSettingsEditor = true;
				}
				EndMenu();
			}
			if (BeginMenu("Help"))
			{
				EndMenu();
			}
			EndMainMenuBar();
		}
	}

	void AutoTec::configEditor(Config& cfg)
	{
		SetNextWindowSize({800, 600}, ImGuiCond_FirstUseEver);
		if (Begin("Configuration " ICON_FA_COG, &showSettingsEditor))
		{
			PushStyleColor(ImGuiCol_Text, 0xFF'36'6F'C9);
			TextUnformatted("Some changes may require a restart!");
			PopStyleColor();
			EndTabItem();

			if (CollapsingHeader("Graphics"))
			{
				static constexpr const char* const GraphicsApiNames[]
				{
					"Direct3D9",
					"Direct3D11",
					"Direct3D12",
					"OpenGL2",
					"OpenGL3",
					"OpenGL ES2",
					"OpenGL ES3",
					"Vulkan ",
					"Metal ",
					"WebGL1",
					"WebGL2",
					"WebGPU"
				};

				if (BeginCombo("Graphics API", GraphicsApiNames[static_cast<std::size_t>(cfg.graphics.api)]))
				{
					for (std::size_t i = 0; i < sizeof GraphicsApiNames / sizeof *GraphicsApiNames; ++i)
					{
						if (Selectable(GraphicsApiNames[i], i == static_cast<std::size_t>(cfg.graphics.api)))
						{
							cfg.graphics.api = static_cast<GraphicsApi>(i);
						}
					}
					EndCombo();
				}

				int windowSize[] = {cfg.graphics.width, cfg.graphics.height};
				InputInt2("Window Size", windowSize);
				cfg.graphics.width = windowSize[0];
				cfg.graphics.height = windowSize[1];

				static constexpr const char* const WindowModeNames[]
				{
					"Full Screen",
					"Windowed",
					"Windowed Maximized"
				};

				if (BeginCombo("Window Mode",
				               WindowModeNames[static_cast<std::size_t>(cfg.graphics.windowMode)])) //TODO

				{
					for (std::size_t i = 0; i < sizeof WindowModeNames / sizeof *WindowModeNames; ++i)
					{
						if (Selectable(WindowModeNames[i], i == static_cast<std::size_t>(cfg.graphics.windowMode)))
						{
							cfg.graphics.windowMode = static_cast<WindowMode>(i);
						}
					}
					EndCombo();
				}

				static constexpr const char* const MsaaModeNames[]
				{
					"Off",
					"2 Samples",
					"4 Samples",
					"8 Samples",
					"16 Samples"
				};

				auto getMsaaName = [msaa = cfg.graphics.msaa]() noexcept -> const char*
				{
					switch (msaa)
					{
						default:
						case MultiSampleAntiAliasingMode::Off:
							return MsaaModeNames[0];
						case MultiSampleAntiAliasingMode::X2:
							return MsaaModeNames[1];
						case MultiSampleAntiAliasingMode::X4:
							return MsaaModeNames[2];
						case MultiSampleAntiAliasingMode::X8:
							return MsaaModeNames[3];
						case MultiSampleAntiAliasingMode::X16:
							return MsaaModeNames[4];
					}
				};

				if (BeginCombo("MSAA", getMsaaName()))
				{
					for (std::size_t i = 0; i < sizeof MsaaModeNames / sizeof *MsaaModeNames; ++i)
					{
						if (Selectable(MsaaModeNames[i],
						               UINT64_C(1) << i == static_cast<std::size_t>(cfg.graphics.msaa)))
						{
							cfg.graphics.msaa = static_cast<MultiSampleAntiAliasingMode>(UINT64_C(1) << i);
						}
					}
					EndCombo();
				}
			}

			if (CollapsingHeader("AutoTec"))
			{
				// Roundings:
				SliderFloat("Child Rounding", &cfg.autoTec.theme.childRounding, .0f, 10.f);
				SliderFloat("Frame Rounding", &cfg.autoTec.theme.frameRounding, .0f, 10.f);
				SliderFloat("Grab Rounding", &cfg.autoTec.theme.grabRounding, .0f, 10.f);
				SliderFloat("Popup Rounding", &cfg.autoTec.theme.popupRounding, .0f, 10.f);
				SliderFloat("Scrollbar Rounding", &cfg.autoTec.theme.scrollbarRounding, .0f, 10.f);
				SliderFloat("Tab Rounding", &cfg.autoTec.theme.tabRounding, .0f, 10.f);
				SliderFloat("Window Rounding", &cfg.autoTec.theme.windowRounding, .0f, 10.f);

				// Theme:
				static constexpr const char* const ThemeNames[]
				{
					"Dark",
					"Light",
					"Blue",
					"Cherry",
					"Green"
				};

				const auto previous = cfg.autoTec.theme.colorTheme;
				if (BeginCombo("Theme", ThemeNames[static_cast<std::size_t>(cfg.autoTec.theme.colorTheme)]))
				{
					for (std::size_t i = 0; i < sizeof ThemeNames / sizeof *ThemeNames; ++i)
					{
						if (Selectable(ThemeNames[i],
						               i == static_cast<std::size_t>(cfg.autoTec.theme.colorTheme)))
						{
							cfg.autoTec.theme.colorTheme = static_cast<AutoTecColorTheme>(i);
						}
					}
					EndCombo();
				}
				applyTheme(cfg.autoTec.theme);

				// FontSize:
				int fontSize = cfg.autoTec.fontSize;
				SliderInt("Font Size", &fontSize, 8, 72);
				cfg.autoTec.fontSize = fontSize;
			}
		}
		End();
	}

	void AutoTec::diagnosticsProfiler()
	{
		ImPlot::ShowDemoWindow();
	}

	void AutoTec::scriptEditor()
	{
		SetNextWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
		if (Begin("ScriptEditor " ICON_FA_CODE, &showScriptEditor, ImGuiWindowFlags_MenuBar))
		{
			if (BeginMenuBar())
			{
				if (BeginMenu("File"))
				{
					if (MenuItem("Open", "Ctrl-O"))
					{
						scriptEditorOpenFile();
					}
					EndMenu();
				}
				if (BeginMenu("Edit"))
				{
					auto ro = editor.IsReadOnly();
					if (MenuItem("Readonly Mode", nullptr, &ro))
					{
						editor.SetReadOnly(ro);
					}
					Separator();

					if (MenuItem("Undo", "Ctrl-Z", nullptr, !ro && editor.CanUndo()))
					{
						editor.Undo();
					}
					if (MenuItem("Redo", "Ctrl-Y", nullptr, !ro && editor.CanRedo()))
					{
						editor.Redo();
					}

					Separator();

					if (MenuItem("Copy", "Ctrl-C", nullptr, editor.HasSelection())) 
					{
						editor.Copy();
					}
					if (MenuItem("Cut", "Ctrl-X", nullptr, !ro && editor.HasSelection()))
					{
						editor.Cut();
					}
					if (MenuItem("Delete", "Del", nullptr, !ro && editor.HasSelection()))
					{
						editor.Delete();
					}
					if (MenuItem("Paste", "Ctrl-V", nullptr, !ro && GetClipboardText() != nullptr))
					{
						editor.Paste();
					}

					Separator();

					if (MenuItem("Select All", "Ctrl-A", nullptr)) 
					{
						editor.SetSelection(TextEditor::Coordinates(), TextEditor::Coordinates(editor.GetTotalLines(), 0));
					}

					EndMenu();
				}

				if (BeginMenu("View"))
				{
					if (MenuItem("Dark Palette"))
					{
						editor.SetPalette(TextEditor::GetDarkPalette());
					}
					if (MenuItem("Light Palette"))
					{
						editor.SetPalette(TextEditor::GetLightPalette());
					}
					if (MenuItem("Retro Palette"))
					{
						editor.SetPalette(TextEditor::GetRetroBluePalette());
					}
					EndMenu();
				}
				EndMenuBar();
			}
			
			if (BeginTabBar("##files"))
			{
				for(const auto& script : openScripts)
				{
					if(BeginTabItem(script.second.getFileName().c_str()))
					{
						if(currentScript != script.first)
						{
							scriptEditorSetScript(script.first);
						}
						EndTabItem();
					}
				}
				EndTabBar();
			}
			
			if (BeginChild("##editor"))
			{
				const auto cpos = editor.GetCursorPosition();
				Text("%i/%-i %i Lines | %s | %s | %s", cpos.mLine + 1, cpos.mColumn + 1, editor.GetTotalLines(),
					editor.IsOverwrite() ? ICON_FA_PEN : ICON_FA_PASTE,
					editor.CanUndo() ? "*" : "!",
					editor.GetLanguageDefinition().mName.c_str());

				editor.Render("Script Editor " ICON_FA_CODE);
			}
			EndChild();
		}
		End();
	}

	void AutoTec::scriptEditorPushFile(std::string&& path)
	{
		openScripts.insert_or_assign(scriptHash, Script(std::move(path)));
		currentScript = scriptHash;
		++scriptHash;
	}

	auto AutoTec::scriptEditorOpenFile() -> bool
	{
		/*
		nfdchar_t* outPath = nullptr;
		const nfdresult_t result = NFD_OpenDialog(nullptr, nullptr, &outPath);

		if (result == NFD_OKAY)
		{
			scriptEditorPushFile(outPath);
			editor.SetText(openScripts.begin()->second.getContent());
			free(outPath);
			return true;
		}

		*/

		// Allows to select multiple files:
		nfdpathset_t outPaths;
		const nfdresult_t result = NFD_OpenDialogMultiple(nullptr, nullptr, &outPaths);

		if(result != NFD_OKAY)
		{
			return false;
		}
		
		const auto num = NFD_PathSet_GetCount(&outPaths);
		for (std::size_t i = 0; i < num; ++i)
		{
			auto path = std::string(NFD_PathSet_GetPath(&outPaths, i));

			// Check if script is already loaded:
			bool alreadyLoaded = false;
			for(const auto& script : openScripts)
			{
				if(path == script.second.getFilePath())
				{
					alreadyLoaded = true;
					currentScript = script.first;
					scriptEditorSetCurrentScript();
				}
			}
			if(alreadyLoaded)
			{
				continue;
			}
			scriptEditorPushFile(std::move(path));
		}

		currentScript = num - 1;

		scriptEditorSetCurrentScript();

		NFD_PathSet_Free(&outPaths);
		
		return true;
	}

	auto AutoTec::scriptEditorSetCurrentScript() -> bool
	{
		return scriptEditorSetScript(currentScript);
	}

	auto AutoTec::scriptEditorSetScript(const std::uint16_t id) -> bool
	{
		const auto fi = openScripts.find(id);
		if(fi == openScripts.end())
		{
			return false;
		}
		editor.SetText(fi->second.getContent());
		currentScript = id;
		return true;
	}

	void AutoTec::applyTheme(const AutoTecTheme& theme) const
	{
		auto& style = GetStyle();
		style.ChildRounding = theme.childRounding;
		style.FrameRounding = theme.frameRounding;
		style.GrabRounding = theme.grabRounding;
		style.PopupRounding = theme.popupRounding;
		style.ScrollbarRounding = theme.scrollbarRounding;
		style.TabRounding = theme.tabRounding;
		style.WindowRounding = theme.windowRounding;
		if (currentColorTheme == theme.getColorTheme())
		{
			return;
		}
		switch (theme.colorTheme)
		{
			default:
			case AutoTecColorTheme::Dark:
				StyleDark();
				break;

			case AutoTecColorTheme::Light:
				StyleLight();
				break;

			case AutoTecColorTheme::Cherry:
				StyleCherry();
				break;

			case AutoTecColorTheme::Blue:
				StyleBlue();
				break;

			case AutoTecColorTheme::Green:
				StyleGreen();
				break;
		}
	}
}
