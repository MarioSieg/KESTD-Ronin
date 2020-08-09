// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Terminal.cpp
// 09.08.2020 03:01
// =============================================================

#include "AutoTec.hpp"
#include "UI/UI.hpp"

namespace kestd::drivers
{
	void AutoTec::Terminal(Logger& logger, kestd::Terminal& terminal)
	{
		SetNextWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
		if (Begin("</> Terminal", &terminal.DisplayTerminal, ImGuiWindowFlags_AlwaysAutoResize))
		{
			const auto footerHeightToReserve = GetStyle().ItemSpacing.y + GetFrameHeightWithSpacing();
			if (BeginChild("proto", ImVec2(.0, -footerHeightToReserve), false, ImGuiWindowFlags_HorizontalScrollbar))
			{
				const auto& buffer = logger.GetBuffer();
				PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1));
				for (const auto& msg : buffer)
				{
					TextUnformatted(msg.Msg.c_str());
				}
				PopStyleVar();
			}
			EndChild();
			Separator();
			bool cmd = InputText("", TerminalBuffer, sizeof TerminalBuffer, ImGuiInputTextFlags_EnterReturnsTrue);
			SameLine();
			cmd |= SmallButton("Send");
			if (cmd && *TerminalBuffer != '\0')
			{
				logger.Log(TerminalBuffer);
				memset(TerminalBuffer, 0, sizeof TerminalBuffer);
			}
			SameLine();
			if (SmallButton("Clear"))
			{
				logger.Clear();
			}
			SameLine();
			if (SmallButton("Flush"))
			{
				logger.Flush();
			}
		}
		End();
	}
}
