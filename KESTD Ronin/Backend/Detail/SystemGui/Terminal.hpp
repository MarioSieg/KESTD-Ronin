// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Terminal.hpp
// 30.08.2020 12:40
// =============================================================

#pragma once

#include "../../Frontend/Export/KESTD/Logger.hpp"
#include "../../Frontend/Export/KESTD/TerminalController.hpp"

namespace kestd::detail::systemgui
{
	class Terminal final
	{
	public:
		Terminal() = default;
		Terminal(const Terminal&) = delete;
		Terminal(Terminal&&) = delete;
		Terminal& operator=(const Terminal&) = delete;
		Terminal& operator=(Terminal&&) = delete;
		~Terminal() = default;

		void updateAndRender(const Logger& protocol, bool& display);
		auto getBuffer() const noexcept -> const char(&)[TerminalController::MAX_COMMAND_LEN];

	private:
		char terminalBuffer[TerminalController::MAX_COMMAND_LEN] = {};
	};
}
