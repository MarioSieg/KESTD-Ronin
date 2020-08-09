#include "AutoTec.hpp"
#include "UI/UI.hpp"

namespace kestd::drivers
{
	void AutoTec::menu()
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
