// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// SystemGui.cpp
// 08.08.2020 00:59
// =============================================================

#include "SystemGui.hpp"
#include "../../Screen.hpp"

namespace kestd::drivers
{
	extern Screen G_SCREEN;

	void SystemGui::initialize()
	{
		context = ImGui::CreateContext();
		ImGui::StyleColorsDark();
		auto& io = ImGui::GetIO();
		io.DisplaySize = ImVec2{static_cast<float>(G_SCREEN.width), static_cast<float>(G_SCREEN.height)};
		io.IniFilename = nullptr;
		initializeRendering();
		initializeInput();
		installCallbackProcPtrs();
	}

	void SystemGui::beginGui()
	{
		beginInput();
		ImGui::NewFrame();
	}

	void SystemGui::endGui()
	{
		ImGui::Render();
		renderDrawData();
	}

	void SystemGui::shutdown() const
	{
		ImGui::DestroyContext(context);
	}
}
