// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Renderer.hpp
// 07.08.2020 21:39
// =============================================================

#pragma once

#include "../../Kernel/ISubsystem.hpp"
#include "Context.hpp"

namespace kestd::drivers
{
	class Renderer final : public kernel::ISubsystem
	{
	public:
		Renderer();

	private:
		auto onPreStartup(Sys& sys) -> bool override;
		auto onPreTick(Sys& sys) -> bool override;
		auto onPostTick(Sys& sys) -> bool override;
		void onPreShutdown(Sys& sys) override;

		RenderContext context = {};
	};
}
