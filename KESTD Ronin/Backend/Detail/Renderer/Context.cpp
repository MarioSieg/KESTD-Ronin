// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Context.cpp
// 09.08.2020 07:24
// =============================================================

#include "Context.hpp"

namespace kestd::detail
{
	RenderContext::RenderContext()
	{
		gui.applyStyle(sysgui::Style::Dark);
	}

	RenderContext::~RenderContext() = default;
}
