#include "Terminal.hpp"
#include <imgui.h>

using namespace ImGui;

namespace kestd::detail::sysgui
{
	void TerminalRenderer::render(const Logger& protocol, bool& display)
	{
		SetNextWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
		if (Begin("</> Terminal", &display, ImGuiWindowFlags_None))
		{
			const auto footerHeightToReserve = GetStyle().ItemSpacing.y + GetFrameHeightWithSpacing();
			if (BeginChild("proto", ImVec2(.0, -footerHeightToReserve), false, ImGuiWindowFlags_HorizontalScrollbar))
			{
				PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1));

				for (const auto& msg : protocol.getBuffer())
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
						color = { 1.f, .4f, .4f, 1.f };
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
