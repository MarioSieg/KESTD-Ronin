// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// TerminalData.cpp
// 09.08.2020 03:01
// =============================================================

#include "AutoTec.hpp"
#include "UI/UI.hpp"

namespace kestd::drivers
{
	void AutoTec::terminal(Logger& logger, kestd::Terminal& terminal)
	{
		SetNextWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
		if (Begin("</> TerminalData", &terminal.displayTerminal, ImGuiWindowFlags_None))
		{
			const auto footerHeightToReserve = GetStyle().ItemSpacing.y + GetFrameHeightWithSpacing();
			if (BeginChild("proto", ImVec2(.0, -footerHeightToReserve), false, ImGuiWindowFlags_HorizontalScrollbar))
			{
				const auto& buffer = logger.getBuffer();
				PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1));

				for (const auto& msg : buffer)
				{
					ImVec4 color;
					bool hasColor = false;
					switch (msg.type)
					{
						case MessageType::Info:
						case MessageType::Trace:
						{
							break;
						}
						case MessageType::Error:
						case MessageType::Warning:
						{
							color = {1.f, .4f, .4f, 1.f};
							hasColor = true;
						}
					}
					if (hasColor)
					{
						PushStyleColor(ImGuiCol_Text, color);
					}
					TextUnformatted(msg.msg.c_str());
					if (hasColor)
					{
						PopStyleColor();
					}
				}
				PopStyleVar();
			}
			EndChild();
			Separator();
			PushItemWidth(GetWindowSize().x);
			if (InputText("",
			              terminalBuffer,
			              sizeof terminalBuffer,
			              ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CharsNoBlank))
			{
				logger.log(terminalBuffer);
				memset(terminalBuffer, 0, sizeof terminalBuffer);
			}
			PopItemWidth();
		}
		End();
	}
}
