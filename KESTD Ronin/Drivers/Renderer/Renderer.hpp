// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Renderer.hpp
// 07.08.2020 21:39
// =============================================================

#pragma once

#include "../../Kernel/Subsystem.hpp"
#include "Context.hpp"

namespace kestd::drivers
{
	struct Renderer final : kernel::ISubsystem
	{
		Renderer();
		auto OnPreStartup(Sys& sys) -> bool final;
		auto OnPreTick(Sys& sys) -> bool final;
		auto OnPostTick(Sys& sys) -> bool final;
		void OnPreShutdown(Sys& sys) final;

		RenderContext Context = {};
	};
}
