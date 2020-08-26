// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// AutoTec.cpp
// 26.08.2020 10:47
// =============================================================

#include "../../Frontend/Environment.hpp"
#include "../../Frontend/BootConfig.hpp"
#include "IconsFontAwesome5.hpp"
#include "AutoTec.hpp"
#include <imgui.h>

#include "Gui.hpp"

using namespace ImGui;

namespace kestd::detail::sysgui
{
	void AutoTec::updateAndRender(Environment& env)
	{
		mainMenu();
		if (showSettingsEditor)
		{
			configEditor(env.getBootConfig());
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

					// Theme:
					static constexpr std::string_view ThemeNames[]
					{
						"Dark",
						"Light",
						"Blue",
						"Cherry",
						"Green"
					};
					const auto previous = cfg.autoTec.theme;
					if (BeginCombo("Theme", ThemeNames[static_cast<std::size_t>(cfg.autoTec.theme)].data()))
					{
						for (std::size_t i = 0; i < sizeof ThemeNames / sizeof *ThemeNames; ++i)
						{
							if (Selectable(ThemeNames[i].data(), i == static_cast<std::size_t>(cfg.autoTec.theme)))
							{
								cfg.autoTec.theme = static_cast<AutoTecTheme>(i);
							}
						}
						EndCombo();
					}
					if (previous != cfg.autoTec.theme)
					{
						SystemGui::ApplyTheme(cfg.autoTec.theme);
					}

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
}
