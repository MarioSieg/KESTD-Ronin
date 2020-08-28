// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Context.cpp
// 09.08.2020 07:24
// =============================================================

#include "Context.hpp"

namespace kestd::detail::renderer
{
	RenderContext::RenderContext(const std::size_t fontSize, const AutoTecTheme& style) : gui(fontSize)
	{
		systemgui::SystemGui::ApplyTheme(style);
	}

	RenderContext::~RenderContext() = default;
}
