// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// AutoTec.cpp
// 26.08.2020 10:47
// =============================================================

#include "AutoTec.hpp"
#include "Gui.hpp"
#include "IconsFontAwesome5.hpp"
#include "../../Frontend/Environment.hpp"
#include <imgui.h>
#include <implot.h>

using namespace ImGui;

namespace kestd::detail::systemgui
{
	void AutoTec::updateAndRender(Environment& env)
	{
		mainMenu();
		if (showSettingsEditor)
		{
			configEditor(env.getBootConfig());
		}
		if(showDiagnosticsProfiler)
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

	void AutoTec::configEditor(BootConfig& cfg)
	{
		SetNextWindowSize({800, 600}, ImGuiCond_FirstUseEver);
		if (Begin("Configuration " ICON_FA_COG, &showSettingsEditor))
		{
			if (BeginTabBar(""))
			{
				if (BeginTabItem("Runtime"))
				{
					EndTabItem();
				}
				if (BeginTabItem("Boot"))
				{
					PushStyleColor(ImGuiCol_Text, 0xFF'36'6F'C9);
					TextUnformatted("Changes may require a restart!");
					PopStyleColor();
					EndTabItem();
				}
				if (BeginTabItem("AutoTec"))
				{
					PushStyleColor(ImGuiCol_Text, 0xFF'36'6F'C9);
					TextUnformatted("Some changes may require a restart!");
					PopStyleColor();

					// Roundings:
					SliderFloat("ChildRounding", &cfg.autoTec.theme.childRounding, .0f, 10.f);
					SliderFloat("FrameRounding", &cfg.autoTec.theme.frameRounding, .0f, 10.f);
					SliderFloat("GrabRounding", &cfg.autoTec.theme.grabRounding, .0f, 10.f);
					SliderFloat("PopupRounding", &cfg.autoTec.theme.popupRounding, .0f, 10.f);
					SliderFloat("ScrollbarRounding", &cfg.autoTec.theme.scrollbarRounding, .0f, 10.f);
					SliderFloat("TabRounding", &cfg.autoTec.theme.tabRounding, .0f, 10.f);
					SliderFloat("WindowRounding", &cfg.autoTec.theme.windowRounding, .0f, 10.f);

					// Theme:
					static constexpr std::string_view ThemeNames[]
					{
						"Dark",
						"Light",
						"Blue",
						"Cherry",
						"Green"
					};
					const auto previous = cfg.autoTec.theme.theme;
					if (BeginCombo("Theme", ThemeNames[static_cast<std::size_t>(cfg.autoTec.theme.theme)].data()))
					{
						for (std::size_t i = 0; i < sizeof ThemeNames / sizeof *ThemeNames; ++i)
						{
							if (Selectable(ThemeNames[i].data(),
							               i == static_cast<std::size_t>(cfg.autoTec.theme.theme)))
							{
								cfg.autoTec.theme.theme = static_cast<AutoTecTheme::Theme>(i);
							}
						}
						EndCombo();
					}
					SystemGui::ApplyTheme(cfg.autoTec.theme, previous != cfg.autoTec.theme.theme);

					// FontSize:
					int fontSize = cfg.autoTec.fontSize;
					SliderInt("FontSize", &fontSize, 8, 72);
					cfg.autoTec.fontSize = fontSize;

					// Enable editor:
					Checkbox("IsEnabled", &cfg.autoTec.isEnabled);

					EndTabItem();
				}
				EndTabBar();
			}
		}
		End();
	}

	void AutoTec::diagnosticsProfiler()
	{
		ImPlot::ShowDemoWindow();
	}
}
