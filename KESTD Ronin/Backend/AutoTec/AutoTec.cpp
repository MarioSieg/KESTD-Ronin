// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// AutoTec.cpp
// 31.08.2020 15:09
// =============================================================

#include "AutoTec.hpp"
#include "../../Frontend/Export/KESTD/Environment.hpp"
#include "../../Frontend/Export/KESTD/Config.hpp"
#include <fontawesome/icons_font_awesome5.h>
#include <imgui.h>
#include <implot.h>

#include "Style.hpp"

using namespace ImGui;

namespace kestd
{
	AutoTec::AutoTec() noexcept : currentColorTheme(AutoTecColorTheme::Dark)
	{
		StyleDark();
		StyleRoundingAngular();
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
				if (MenuItem("Diagnostics"))
				{
					showDiagnosticsProfiler = true;
				}

				if (MenuItem("Settings"))
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
