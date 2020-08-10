// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// AutoTecSystem.hpp
// 09.08.2020 10:43
// =============================================================

#pragma once

#include "../../Logger.hpp"
#include "../../Terminal.hpp"
#include "../../Kernel/ISubsystem.hpp"

namespace kestd::drivers
{
	class AutoTecSystem final : public kernel::ISubsystem
	{
	public:
		AutoTecSystem();
		~AutoTecSystem() override;

	private:
		auto onPostTick(Sys&) -> bool override;

		void terminal(Logger& logger, Terminal& terminal);
		void menu() const;

		char terminalBuffer[Terminal::MAX_COMMAND_LEN] = {};
	};
}
