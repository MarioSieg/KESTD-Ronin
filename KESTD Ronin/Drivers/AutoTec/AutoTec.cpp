// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// AutoTec.cpp
// 09.08.2020 03:13
// =============================================================

#include "AutoTec.hpp"
#include "../../Sys.hpp"

using namespace kestd::kernel;

namespace kestd::drivers
{
	AutoTec::AutoTec() : ISubsystem("AutoTec", true)
	{
		callbacks.onPostStartup = true;
		callbacks.onPostTick = true;
		callbacks.onPostShutdown = true;
	}

	auto AutoTec::onPostStartup(Sys&) -> bool
	{
		return true;
	}

	auto AutoTec::onPostTick(Sys& sys) -> bool
	{
		if (sys.terminal.displayTerminal)
		{
			terminal(sys.protocol, sys.terminal);
		}

		menu();

		return true;
	}

	void AutoTec::onPostShutdown(Sys&)
	{
	}
}
