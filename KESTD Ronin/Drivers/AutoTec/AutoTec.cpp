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
	AutoTec::AutoTec() : ISubsystem("AutoTec", Event::OnPostStartup | Event::OnPostTick | Event::OnPostShutdown, true)
	{
	}

	auto AutoTec::OnPostStartup(Sys&) -> bool
	{
		return true;
	}

	auto AutoTec::OnPostTick(Sys& sys) -> bool
	{
		if (sys.Terminal.DisplayTerminal)
		{
			Terminal(sys.Protocol, sys.Terminal);
		}

		return true;
	}

	void AutoTec::OnPostShutdown(Sys&)
	{
	}
}
