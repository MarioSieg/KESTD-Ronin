// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Gui.cpp
// 09.08.2020 07:24
// =============================================================

#include "Gui.hpp"
#include "../../Screen.hpp"

namespace kestd::drivers
{
	extern Screen G_SCREEN;

	SystemGui::SystemGui()
	{
		ImGui::StyleColorsDark();
		auto& io = ImGui::GetIO();
		io.DisplaySize = ImVec2{static_cast<float>(G_SCREEN.width), static_cast<float>(G_SCREEN.height)};
		io.IniFilename = nullptr;
	}

	SystemGui::~SystemGui()
	{
		ImGui::DestroyContext(context);
	}

	void SystemGui::begin()
	{
		input.update();
		ImGui::NewFrame();
	}

	void SystemGui::end() const
	{
		ImGui::Render();
		const ImDrawData* const data = ImGui::GetDrawData();
		renderer.draw(data);
	}
}
