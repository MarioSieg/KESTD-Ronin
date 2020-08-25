// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// RenderSystem.hpp
// 09.08.2020 10:43
// =============================================================

#pragma once

#include "../../Frontend/BootConfig.hpp"
#include "../../Kernel/ISubsystem.hpp"
#include "../SystemGui/TerminalRenderer.hpp"
#include "Context.hpp"

namespace kestd::detail
{
	class RenderSystem final : public kernel::ISubsystem
	{
	public:
		RenderSystem(const BootConfig& cfg);
		RenderSystem(const RenderSystem&) = delete;
		RenderSystem(RenderSystem&&) = delete;
		auto operator=(const RenderSystem&) -> RenderSystem& = delete;
		auto operator=(RenderSystem&&) -> RenderSystem& = delete;
		~RenderSystem() override;

	private:
		auto onTick(Environment& sys) -> bool override;

		RenderContext context;
		sysgui::TerminalRenderer terminalRenderer;
	};
}
