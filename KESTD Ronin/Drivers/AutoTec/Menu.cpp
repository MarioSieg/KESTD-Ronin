// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Menu.cpp
// 09.08.2020 08:40
// =============================================================

#include "AutoTecSystem.hpp"
#include "UI/UI.hpp"

namespace kestd::drivers
{
	void AutoTecSystem::menu() const
	{
		if (BeginMainMenuBar())
		{
			if (MenuItem("File"))
			{
			}
			if (MenuItem("Edit"))
			{
			}
			if (MenuItem("Scripts"))
			{
			}
			if (MenuItem("Scenery"))
			{
			}
			if (MenuItem("Simulation"))
			{
			}
			if (MenuItem("Tools"))
			{
			}
			if (MenuItem("Options"))
			{
			}
			if (MenuItem("Help"))
			{
			}
		}
		EndMainMenuBar();
	}
}
