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

	void SystemGui::Initialize()
	{
		Context = ImGui::CreateContext();
		ImGui::StyleColorsDark();
		auto& io = ImGui::GetIO();
		io.DisplaySize = ImVec2{static_cast<float>(G_SCREEN.Width), static_cast<float>(G_SCREEN.Height)};
		io.IniFilename = nullptr;
		InitializeRendering();
		InitializeInput();
		InstallCallbackProcPtrs();
	}

	void SystemGui::BeginGui()
	{
		BeginInput();
		ImGui::NewFrame();
	}

	void SystemGui::EndGui()
	{
		ImGui::Render();
		RenderDrawData();
	}

	void SystemGui::Shutdown() const
	{
		ImGui::DestroyContext(Context);
	}
}
