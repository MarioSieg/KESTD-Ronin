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
#include "../SystemGui/Terminal.hpp"
#include "../SystemGui/AutoTec.hpp"
#include "Context.hpp"

namespace kestd::detail
{
	class RenderSystem final : public kernel::ISubsystem
	{
	public:
		RenderSystem(const BootConfig& cfg, Environment& env);
		RenderSystem(const RenderSystem&) = delete;
		RenderSystem(RenderSystem&&) = delete;
		RenderSystem& operator=(const RenderSystem&) = delete;
		RenderSystem& operator=(RenderSystem&&) = delete;
		~RenderSystem() override;

	private:
		auto onTick(Environment& sys) -> bool override;

		RenderContext context;
		sysgui::Terminal terminalRenderer;
		sysgui::AutoTec autoTec;
	};
}
