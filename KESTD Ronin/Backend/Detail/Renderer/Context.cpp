// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Context.cpp
// 09.08.2020 07:24
// =============================================================

#include "Context.hpp"
#include "../../Frontend/Config.hpp"

namespace kestd::detail::renderer
{
	RenderContext::RenderContext(const Config& cfg) : drivers(cfg.getConfigForGraphics()),
	                                                  gui(cfg.getConfigForAutoTec().getFontSize(),
	                                                      cfg.getConfigForGraphics().getWidth(),
	                                                      cfg.getConfigForGraphics().getHeight())
	{
	}
}
