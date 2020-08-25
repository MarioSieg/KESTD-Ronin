// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// TerminalRenderer.hpp
// 24.08.2020 13:52
// =============================================================

#pragma once

#include "../../Frontend/BufferedProtocolLogger.hpp"
#include "../../Frontend/TerminalController.hpp"

namespace kestd::detail::sysgui
{
	struct TerminalRenderer final
	{
		void render(const BufferedProtocolLogger& protocol, bool& display);
		char terminalBuffer[TerminalController::MAX_COMMAND_LEN] = {};
	};
}
