// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD Ronin
// Mario
// SystemGui.cpp
// 08.08.2020 00:59

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
		io.DisplaySize = ImVec2{ static_cast<float>(G_SCREEN.Width), static_cast<float>(G_SCREEN.Height) };
		io.IniFilename = nullptr;
		InitializeRendering();
		InitializeInput();
		InstallCallbackProcPtrs();
	}

	void SystemGui::Begin()
	{
		BeginInput();
		BeginRendering();
	}

	void SystemGui::End()
	{
		Render();
	}

	void SystemGui::Shutdown()
	{
		ImGui::DestroyContext(Context);
	}

}

#undef MAP_ANALOG
#undef MAP_BUTTON
