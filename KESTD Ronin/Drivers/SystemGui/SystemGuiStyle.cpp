// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// SystemGuiStyle.cpp
// 09.08.2020 01:24
// =============================================================

#include "SystemGui.hpp"

namespace kestd::drivers
{
	void SystemGui::ApplyStyle(const Style sty)
	{
		auto& style = ImGui::GetStyle();
		switch (sty)
		{
			default:
			case Style::Dark:
			{
				style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
				style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
				style.Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
				style.Colors[ImGuiCol_ChildBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
				style.Colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
				style.Colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
				style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
				style.Colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.21f, 0.22f, 0.54f);
				style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.40f);
				style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.18f, 0.18f, 0.18f, 0.67f);
				style.Colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
				style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.29f, 0.29f, 0.29f, 1.00f);
				style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
				style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
				style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
				style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
				style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
				style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
				style.Colors[ImGuiCol_CheckMark] = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);
				style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
				style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
				style.Colors[ImGuiCol_Button] = ImVec4(0.44f, 0.44f, 0.44f, 0.40f);
				style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.46f, 0.47f, 0.48f, 1.00f);
				style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.42f, 0.42f, 0.42f, 1.00f);
				style.Colors[ImGuiCol_Header] = ImVec4(0.70f, 0.70f, 0.70f, 0.31f);
				style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.70f, 0.70f, 0.70f, 0.80f);
				style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.48f, 0.50f, 0.52f, 1.00f);
				style.Colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
				style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.72f, 0.72f, 0.72f, 0.78f);
				style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
				style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.91f, 0.91f, 0.91f, 0.25f);
				style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.81f, 0.81f, 0.81f, 0.67f);
				style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.46f, 0.46f, 0.46f, 0.95f);
				style.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
				style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
				style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.73f, 0.60f, 0.15f, 1.00f);
				style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
				style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.87f, 0.87f, 0.87f, 0.35f);
				style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
				style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
				style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
				style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
			}
				break;

			case Style::Light:
			{
				style.Colors[ImGuiCol_Text] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
				style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
				//style.Colors[ImGuiCol_TextHovered] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
				//style.Colors[ImGuiCol_TextActive] = ImVec4(1.00f, 1.00f, 0.00f, 1.00f);
				style.Colors[ImGuiCol_WindowBg] = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);
				//style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
				style.Colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.39f);
				style.Colors[ImGuiCol_BorderShadow] = ImVec4(1.00f, 1.00f, 1.00f, 0.10f);
				style.Colors[ImGuiCol_FrameBg] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
				style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
				style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
				style.Colors[ImGuiCol_TitleBg] = ImVec4(0.96f, 0.96f, 0.96f, 1.00f);
				style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 1.00f, 1.00f, 0.51f);
				style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.82f, 0.82f, 0.82f, 1.00f);
				style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
				style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.98f, 0.98f, 0.98f, 0.53f);
				style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.69f, 0.69f, 0.69f, 0.80f);
				style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.49f, 0.49f, 0.49f, 0.80f);
				style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
				//style.Colors[ImGuiCol_ComboBg] = ImVec4(0.86f, 0.86f, 0.86f, 0.99f);
				style.Colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
				style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.26f, 0.59f, 0.98f, 0.78f);
				style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
				style.Colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
				style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
				style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
				style.Colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
				style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
				style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
				//style.Colors[ImGuiCol_Column] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
				//style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.78f);
				//style.Colors[ImGuiCol_ColumnActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
				style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
				style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
				style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
				//style.Colors[ImGuiCol_CloseButton] = ImVec4(0.59f, 0.59f, 0.59f, 0.50f);
				//style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);
				//style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);
				style.Colors[ImGuiCol_PlotLines] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
				style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
				style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
				style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
				style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
				//style.Colors[ImGuiCol_TooltipBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.94f);
				style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);
			}
			break;

			case Style::Cherry:
			{
				style.Colors[ImGuiCol_Text] = ImVec4(0.860f, 0.930f, 0.890f, 0.78f);
				style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.860f, 0.930f, 0.890f, 0.28f);
				style.Colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
				//style.Colors[ImGuiCol_ChildWindowBg] = BG(0.58f);
				style.Colors[ImGuiCol_PopupBg] = ImVec4(0.200f, 0.220f, 0.270f, 0.9f);
				style.Colors[ImGuiCol_Border] = ImVec4(0.31f, 0.31f, 1.00f, 0.00f);
				style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
				style.Colors[ImGuiCol_FrameBg] = ImVec4(0.200f, 0.220f, 0.270f, 1.00f);
				style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.455f, 0.198f, 0.301f, 0.78f);
				style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.455f, 0.198f, 0.301f, 1.00f);
				style.Colors[ImGuiCol_TitleBg] = ImVec4(0.232f, 0.201f, 0.271f, 1.00f);
				style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.502f, 0.075f, 0.256f, 1.00f);
				style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.200f, 0.220f, 0.270f, 0.75f);
				style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.200f, 0.220f, 0.270f, 0.47f);
				style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.200f, 0.220f, 0.270f, 1.00f);
				style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.09f, 0.15f, 0.16f, 1.00f);
				style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.455f, 0.198f, 0.301f, 0.78f);
				style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.455f, 0.198f, 0.301f, 1.00f);
				style.Colors[ImGuiCol_CheckMark] = ImVec4(0.71f, 0.22f, 0.27f, 1.00f);
				style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
				style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.71f, 0.22f, 0.27f, 1.00f);
				style.Colors[ImGuiCol_Button] = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
				style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.455f, 0.198f, 0.301f, 0.86f);
				style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.455f, 0.198f, 0.301f, 1.00f);
				style.Colors[ImGuiCol_Header] = ImVec4(0.455f, 0.198f, 0.301f, 0.76f);
				style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.455f, 0.198f, 0.301f, 0.86f);
				style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.502f, 0.075f, 0.256f, 1.00f);
				//style.Colors[ImGuiCol_Column] = ImVec4(0.14f, 0.16f, 0.19f, 1.00f);
				//style.Colors[ImGuiCol_ColumnHovered] = MED(0.78f);
				//style.Colors[ImGuiCol_ColumnActive] = MED(1.00f);
				style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.47f, 0.77f, 0.83f, 0.04f);
				style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.455f, 0.198f, 0.301f, 0.78f);
				style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.455f, 0.198f, 0.301f, 1.00f);
				style.Colors[ImGuiCol_PlotLines] = ImVec4(0.860f, 0.930f, 0.890f, 0.63f);
				style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.455f, 0.198f, 0.301f, 1.00f);
				style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.860f, 0.930f, 0.890f, 0.63f);
				style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.455f, 0.198f, 0.301f, 1.00f);
				style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.455f, 0.198f, 0.301f, 0.43f);
				style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.200f, 0.220f, 0.270f, 0.73f);
				style.Colors[ImGuiCol_Border] = ImVec4(0.539f, 0.479f, 0.255f, 0.162f);

				style.WindowPadding = ImVec2(6, 4);
				style.WindowRounding = 0.0f;
				style.FramePadding = ImVec2(5, 2);
				style.FrameRounding = 3.0f;
				style.ItemSpacing = ImVec2(7, 1);
				style.ItemInnerSpacing = ImVec2(1, 1);
				style.TouchExtraPadding = ImVec2(0, 0);
				style.IndentSpacing = 6.0f;
				style.ScrollbarSize = 12.0f;
				style.ScrollbarRounding = 16.0f;
				style.GrabMinSize = 20.0f;
				style.GrabRounding = 2.0f;
				style.WindowTitleAlign.x = 0.50f;
				style.FrameBorderSize = 0.0f;
				style.WindowBorderSize = 1.0f;
			}
			break;

			case Style::Blue:
			{
				style.Colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
				style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.36f, 0.42f, 0.47f, 1.00f);
				style.Colors[ImGuiCol_WindowBg] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
				style.Colors[ImGuiCol_ChildBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
				style.Colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
				style.Colors[ImGuiCol_Border] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
				style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
				style.Colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
				style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.12f, 0.20f, 0.28f, 1.00f);
				style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.09f, 0.12f, 0.14f, 1.00f);
				style.Colors[ImGuiCol_TitleBg] = ImVec4(0.09f, 0.12f, 0.14f, 0.65f);
				style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
				style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
				style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
				style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.39f);
				style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
				style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.18f, 0.22f, 0.25f, 1.00f);
				style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.09f, 0.21f, 0.31f, 1.00f);
				style.Colors[ImGuiCol_CheckMark] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
				style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
				style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.37f, 0.61f, 1.00f, 1.00f);
				style.Colors[ImGuiCol_Button] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
				style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
				style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
				style.Colors[ImGuiCol_Header] = ImVec4(0.20f, 0.25f, 0.29f, 0.55f);
				style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
				style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
				style.Colors[ImGuiCol_Separator] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
				style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
				style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
				style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
				style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
				style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
				style.Colors[ImGuiCol_Tab] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
				style.Colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
				style.Colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
				style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
				style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
				style.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
				style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
				style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
				style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
				style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
				style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
				style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
				style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
				style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
				style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
			}
			break;

			case Style::Green:
			{
				style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
				style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
				style.Colors[ImGuiCol_WindowBg] = ImVec4(0.29f, 0.34f, 0.26f, 1.00f);
				style.Colors[ImGuiCol_ChildBg] = ImVec4(0.29f, 0.34f, 0.26f, 1.00f);
				style.Colors[ImGuiCol_PopupBg] = ImVec4(0.24f, 0.27f, 0.20f, 1.00f);
				style.Colors[ImGuiCol_Border] = ImVec4(0.54f, 0.57f, 0.51f, 0.50f);
				style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.14f, 0.16f, 0.11f, 0.52f);
				style.Colors[ImGuiCol_FrameBg] = ImVec4(0.24f, 0.27f, 0.20f, 1.00f);
				style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.27f, 0.30f, 0.23f, 1.00f);
				style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.30f, 0.34f, 0.26f, 1.00f);
				style.Colors[ImGuiCol_TitleBg] = ImVec4(0.24f, 0.27f, 0.20f, 1.00f);
				style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.29f, 0.34f, 0.26f, 1.00f);
				style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
				style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.24f, 0.27f, 0.20f, 1.00f);
				style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
				style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.28f, 0.32f, 0.24f, 1.00f);
				style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.25f, 0.30f, 0.22f, 1.00f);
				style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.23f, 0.27f, 0.21f, 1.00f);
				style.Colors[ImGuiCol_CheckMark] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
				style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
				style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.54f, 0.57f, 0.51f, 0.50f);
				style.Colors[ImGuiCol_Button] = ImVec4(0.29f, 0.34f, 0.26f, 0.40f);
				style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
				style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.54f, 0.57f, 0.51f, 0.50f);
				style.Colors[ImGuiCol_Header] = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
				style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.35f, 0.42f, 0.31f, 0.6f);
				style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.54f, 0.57f, 0.51f, 0.50f);
				style.Colors[ImGuiCol_Separator] = ImVec4(0.14f, 0.16f, 0.11f, 1.00f);
				style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.54f, 0.57f, 0.51f, 1.00f);
				style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
				style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.19f, 0.23f, 0.18f, 0.00f);
				style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.54f, 0.57f, 0.51f, 1.00f);
				style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
				style.Colors[ImGuiCol_Tab] = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
				style.Colors[ImGuiCol_TabHovered] = ImVec4(0.54f, 0.57f, 0.51f, 0.78f);
				style.Colors[ImGuiCol_TabActive] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
				style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.24f, 0.27f, 0.20f, 1.00f);
				style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
				//style.Colors[ImGuiCol_DockingPreview] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
				//style.Colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
				style.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
				style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
				style.Colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.78f, 0.28f, 1.00f);
				style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
				style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
				style.Colors[ImGuiCol_DragDropTarget] = ImVec4(0.73f, 0.67f, 0.24f, 1.00f);
				style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
				style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
				style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
				style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

				style.FrameBorderSize = 1.0f;
				style.WindowRounding = 0.0f;
				style.ChildRounding = 0.0f;
				style.FrameRounding = 0.0f;
				style.PopupRounding = 0.0f;
				style.ScrollbarRounding = 0.0f;
				style.GrabRounding = 0.0f;
				style.TabRounding = 0.0f;
			}
			break;
		}
	}
}
