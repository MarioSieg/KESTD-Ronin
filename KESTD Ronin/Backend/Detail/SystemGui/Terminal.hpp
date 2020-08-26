// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Terminal.hpp
// 24.08.2020 13:52
// =============================================================

#pragma once

#include "../../Frontend/BufferedProtocolLogger.hpp"
#include "../../Frontend/TerminalController.hpp"

namespace kestd::detail::sysgui
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

		void updateAndRender(const BufferedProtocolLogger& protocol, bool& display);
		auto getBuffer() const noexcept -> const char(&)[TerminalController::MAX_COMMAND_LEN];

	private:
		char terminalBuffer[TerminalController::MAX_COMMAND_LEN] = {};
	};
}
