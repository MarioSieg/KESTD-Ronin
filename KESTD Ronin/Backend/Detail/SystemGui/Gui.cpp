// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Gui.cpp
// 31.08.2020 15:09
// =============================================================

#include "Gui.hpp"
#include "../../../Frontend/Export/KESTD/Config.hpp"

namespace kestd::detail::systemgui
{
	SystemGui::SystemGui(const std::uint8_t fontSize, const std::uint16_t width, const std::uint16_t heigth) :
		guiContext(ImGui::CreateContext()),
		plotContext(ImPlot::CreateContext()),
		renderer(fontSize)
	{
		// Initialize ImGui:
		ImGui::StyleColorsDark();
		auto& io = ImGui::GetIO();
		io.DisplaySize = ImVec2{static_cast<float>(width), static_cast<float>(heigth)};
		io.IniFilename = nullptr;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	}

	void SystemGui::beginFrame()
	{
		input.update();
		ImGui::NewFrame();
		beginDockSpace();
	}

	void SystemGui::endFrame() const
	{
		endDockSpace();
		ImGui::Render();
		const ImDrawData* const data = ImGui::GetDrawData();
		renderer.draw(data);
	}

	SystemGui::~SystemGui()
	{
		ImPlot::DestroyContext(plotContext);
		ImGui::DestroyContext(guiContext);
	}
}
