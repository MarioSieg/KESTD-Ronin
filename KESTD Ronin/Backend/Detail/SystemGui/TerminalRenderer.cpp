// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// TerminalRenderer.cpp
// 24.08.2020 13:52
// =============================================================

#include "TerminalRenderer.hpp"
#include <imgui.h>

using namespace ImGui;

namespace kestd::detail::sysgui
{
	void TerminalRenderer::render(const BufferedProtocolLogger& protocol, bool& display)
	{
		if (!display)
		{
			return;
		}
		SetNextWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
		if (Begin("</> TerminalController", &display, ImGuiWindowFlags_None))
		{
			const auto footerHeightToReserve = GetStyle().ItemSpacing.y + GetFrameHeightWithSpacing();
			if (BeginChild("proto", ImVec2(.0, -footerHeightToReserve), false, ImGuiWindowFlags_HorizontalScrollbar))
			{
				PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1));
				for (const auto& msg : protocol.getBuffer())
				{
					PushStyleColor(ImGuiCol_Text, TerminalController::COLORS[static_cast<std::size_t>(msg.type)]);
					TextUnformatted(msg.msg.c_str());
					PopStyleColor();
				}
				PopStyleVar();
			}
			EndChild();
			Separator();
			PushItemWidth(GetWindowSize().x);
			if (InputText("",
			              terminalBuffer,
			              sizeof terminalBuffer,
			              ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CharsNoBlank) && *terminalBuffer !=
				'\0')
			{
				memset(terminalBuffer, 0, sizeof terminalBuffer);
			}
			PopItemWidth();
		}
		End();
	}
}
