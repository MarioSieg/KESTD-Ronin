// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// RenderSystem.hpp
// 09.08.2020 10:43
// =============================================================

#pragma once

#include "../../Kernel/ISubsystem.hpp"
#include "../SystemGui/Terminal.hpp"
#include "Context.hpp"

namespace kestd::detail
{
	class RenderSystem final : public kernel::ISubsystem
	{
	public:
		RenderSystem();
		RenderSystem(const RenderSystem&) = delete;
		RenderSystem(RenderSystem&&) = delete;
		auto operator=(const RenderSystem&) -> RenderSystem& = delete;
		auto operator=(RenderSystem&&) -> RenderSystem& = delete;
		~RenderSystem() override;

	private:
		auto onTick(Sys& sys) -> bool override;

		RenderContext context;
		sysgui::TerminalRenderer terminalRenderer;
	};
}
