// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Context.cpp
// 31.08.2020 15:09
// =============================================================

#include "Context.hpp"
#include "../../Frontend/Export/KESTD/Config.hpp"

namespace kestd::detail::renderer
{
	RenderContext::RenderContext(const Config& cfg) : drivers(cfg.getConfigForGraphics()),
	                                                  gui(cfg.getConfigForAutoTec().getFontSize(),
	                                                      cfg.getConfigForGraphics().getWidth(),
	                                                      cfg.getConfigForGraphics().getHeight())
	{
	}
}
