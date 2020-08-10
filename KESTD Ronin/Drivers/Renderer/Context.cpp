// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Context.cpp
// 09.08.2020 07:24
// =============================================================

#include "Context.hpp"

namespace kestd::drivers
{
	RenderContext::RenderContext()
	{
		gui.applyStyle(Style::Dark);
	}

	RenderContext::~RenderContext() = default;
}
