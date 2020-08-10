// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// AutoTecSystem.cpp
// 09.08.2020 10:43
// =============================================================

#include "AutoTecSystem.hpp"
#include "../../Sys.hpp"

using namespace kestd::kernel;

namespace kestd::drivers
{
	AutoTecSystem::AutoTecSystem() : ISubsystem("AutoTecSystem", true)
	{
		callbacks.onPostTick = true;
	}

	AutoTecSystem::~AutoTecSystem()
	= default;

	auto AutoTecSystem::onPostTick(Sys& sys) -> bool
	{
		if (sys.terminal.displayTerminal)
		{
			terminal(sys.protocol, sys.terminal);
		}

		menu();

		return true;
	}
}
