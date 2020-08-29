// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Gui.cpp
// 09.08.2020 07:24
// =============================================================

#include "Gui.hpp"
#include <imgui.h>
#include <implot.h>

#include "../../../Frontend/ConfigGraphics.hpp"

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
