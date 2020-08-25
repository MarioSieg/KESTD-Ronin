// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Gui.cpp
// 09.08.2020 07:24
// =============================================================

#include "Gui.hpp"
#include "../../Frontend/ScreenInfo.hpp"

extern kestd::ScreenInfo G_SCREEN;

namespace kestd::detail::sysgui
{
	SystemGui::SystemGui(const std::size_t fontSize) : renderer(fontSize)
	{
		// Initialize ImGui:
		ImGui::StyleColorsDark();
		auto& io = ImGui::GetIO();
		io.DisplaySize = ImVec2{static_cast<float>(G_SCREEN.width), static_cast<float>(G_SCREEN.height)};
		io.IniFilename = nullptr;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	}

	SystemGui::~SystemGui()
	{
		ImGui::DestroyContext(context);
	}

	void SystemGui::begin()
	{
		input.update();
		ImGui::NewFrame();
		beginDockSpace();
	}

	void SystemGui::end() const
	{
		endDockSpace();
		ImGui::Render();
		const ImDrawData* const data = ImGui::GetDrawData();
		renderer.draw(data);
	}
}
