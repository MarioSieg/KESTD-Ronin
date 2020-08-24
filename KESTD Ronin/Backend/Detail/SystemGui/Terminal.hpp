#pragma once

#include "../../Frontend/Logger.hpp"
#include "../../Frontend/Terminal.hpp"

namespace kestd::detail::sysgui
{
	struct TerminalRenderer final
	{
		void render(const Logger& protocol, bool& display);
		char terminalBuffer[Terminal::MAX_COMMAND_LEN] = {};
	};
}
