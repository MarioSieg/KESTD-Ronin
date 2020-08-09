// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// AutoTec.hpp
// 09.08.2020 03:00
// =============================================================

#pragma once

#include "../../Logger.hpp"
#include "../../Terminal.hpp"
#include "../../Kernel/Subsystem.hpp"

namespace kestd::drivers
{
	struct AutoTec final : kernel::ISubsystem
	{
		AutoTec();
		auto OnPostStartup(Sys&) -> bool override;
		auto OnPostTick(Sys&) -> bool override;
		void OnPostShutdown(Sys&) override;
		void Terminal(Logger& logger, Terminal& terminal);
		char TerminalBuffer[Terminal::MAX_COMMAND_LEN] = {};
	};
}
