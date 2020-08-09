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
	class AutoTec final : public kernel::ISubsystem
	{
	public:
		AutoTec();

	private:
		auto onPostStartup(Sys&) -> bool override;
		auto onPostTick(Sys&) -> bool override;
		void onPostShutdown(Sys&) override;

		void terminal(Logger& logger, Terminal& terminal);
		void menu();

		char terminalBuffer[Terminal::MAX_COMMAND_LEN] = {};
	};
}
