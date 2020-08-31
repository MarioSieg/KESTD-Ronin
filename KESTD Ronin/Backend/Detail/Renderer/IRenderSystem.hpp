// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// IRenderSystem.hpp
// 31.08.2020 15:09
// =============================================================

#pragma once

#include "../../Kernel/ISubsystem.hpp"
#include "../SystemGui/Terminal.hpp"
#include "../../AutoTec/AutoTec.hpp"
#include "Context.hpp"

namespace kestd::detail::renderer
{
	class IRenderSystem final : public kernel::ISubsystem
	{
	public:
		IRenderSystem(Environment& env);
		IRenderSystem(const IRenderSystem&) = delete;
		IRenderSystem(IRenderSystem&&) = delete;
		IRenderSystem& operator=(const IRenderSystem&) = delete;
		IRenderSystem& operator=(IRenderSystem&&) = delete;
		~IRenderSystem() override;

	private:
		auto onTick(Environment& sys) -> bool override;

		RenderContext context;
		systemgui::Terminal terminalRenderer;
		AutoTec autoTec;
	};
}
