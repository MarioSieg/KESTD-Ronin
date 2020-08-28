// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Context.hpp
// 09.08.2020 07:24
// =============================================================

#pragma once

#include "Drivers.hpp"
#include "../SystemGui/Gui.hpp"

namespace kestd
{
	class AutoTecTheme;
}

namespace kestd::detail::renderer
{
	class RenderContext final
	{
	public:
		RenderContext(std::size_t fontSize, const AutoTecTheme& style);
		RenderContext(const RenderContext&) = delete;
		RenderContext(RenderContext&&) = delete;
		auto operator=(const RenderContext&) -> RenderContext& = delete;
		auto operator=(RenderContext&&) -> RenderContext& = delete;
		~RenderContext();

		Drivers drivers;
		systemgui::SystemGui gui;
	};
}
