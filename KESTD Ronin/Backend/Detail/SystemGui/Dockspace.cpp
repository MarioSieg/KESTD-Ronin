// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Dockspace.cpp
// 24.08.2020 15:04
// =============================================================

#include "Gui.hpp"

using namespace ImGui;

namespace kestd::detail::systemgui
{
	void SystemGui::beginDockSpace() const
	{
		// Create dockspace:
		constexpr auto isFullscrenDockspace = true;
		constexpr auto isPaddingDockspace = false;

		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoDocking;
		ImGuiDockNodeFlags dockspaceFlags = ImGuiDockNodeFlags_None;

		if constexpr (isFullscrenDockspace)
		{
			auto* viewport = GetMainViewport();
			SetNextWindowPos(viewport->GetWorkPos());
			SetNextWindowSize(viewport->GetWorkSize());
			SetNextWindowViewport(viewport->ID);
			PushStyleVar(ImGuiStyleVar_WindowRounding, .0f);
			PushStyleVar(ImGuiStyleVar_WindowBorderSize, .0f);
			windowFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
				ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		}
		else
		{
			dockspaceFlags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
		}

		if (dockspaceFlags & ImGuiDockNodeFlags_PassthruCentralNode)
			windowFlags |= ImGuiWindowFlags_NoBackground;

		if constexpr (!isPaddingDockspace)
			PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		Begin("DockSpace", nullptr, windowFlags);
		if constexpr (!isPaddingDockspace)
			PopStyleVar();

		if constexpr (isFullscrenDockspace)
			PopStyleVar(2);

		// DockSpace:
		auto& io = GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			const auto dockspaceID = GetID("DockSpace");
			DockSpace(dockspaceID, ImVec2(0.0f, 0.0f), dockspaceFlags);
		}
		else
		{
			Text("Docking is not enabled!");
			SameLine(.0f, .0f);
			if (SmallButton("Enable"))
				io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		}
	}

	void SystemGui::endDockSpace() const
	{
		End();
	}
}
