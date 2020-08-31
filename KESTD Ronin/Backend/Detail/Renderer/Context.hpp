// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Context.hpp
// 31.08.2020 15:09
// =============================================================

#pragma once

#include "Drivers.hpp"
#include "../SystemGui/Gui.hpp"

namespace kestd
{
	class Config;
	class AutoTecTheme;
}

namespace kestd::detail::renderer
{
	class RenderContext final
	{
	public:
		RenderContext(const Config& cfg);
		RenderContext(const RenderContext&) = delete;
		RenderContext(RenderContext&&) = delete;
		auto operator=(const RenderContext&) -> RenderContext& = delete;
		auto operator=(RenderContext&&) -> RenderContext& = delete;
		~RenderContext() = default;

		Drivers drivers;
		systemgui::SystemGui gui;
	};
}
