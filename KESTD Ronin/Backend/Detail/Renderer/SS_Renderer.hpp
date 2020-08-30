// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// SS_Renderer.hpp
// 30.08.2020 12:40
// =============================================================

#pragma once

#include "../../Kernel/ISubsystem.hpp"
#include "../SystemGui/Terminal.hpp"
#include "../../AutoTec/AutoTec.hpp"
#include "Context.hpp"

namespace kestd::detail::renderer
{
	class RenderSystem final : public kernel::ISubsystem
	{
	public:
		RenderSystem(Environment& env);
		RenderSystem(const RenderSystem&) = delete;
		RenderSystem(RenderSystem&&) = delete;
		RenderSystem& operator=(const RenderSystem&) = delete;
		RenderSystem& operator=(RenderSystem&&) = delete;
		~RenderSystem() override;

	private:
		auto onTick(Environment& sys) -> bool override;

		RenderContext context;
		systemgui::Terminal terminalRenderer;
		AutoTec autoTec;
	};
}
