// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// RenderSystem.cpp
// 09.08.2020 10:43
// =============================================================

#include "RenderSystem.hpp"
#include "../../Frontend/Environment.hpp"

using namespace kestd::kernel;

kestd::ScreenInfo G_SCREEN;

namespace kestd::detail
{
	RenderSystem::RenderSystem(const BootConfig& cfg) : ISubsystem("RenderSystem", true, Event::Tick),
	                                                    context(cfg.autoTec.fontSize, cfg.autoTec.style)
	{
		G_SCREEN.width = 1920;
		G_SCREEN.height = 1080;
	}

	RenderSystem::~RenderSystem() = default;


	auto RenderSystem::onTick(Environment& sys) -> bool
	{
		context.gui.begin();
		terminalRenderer.render(sys.getProtocol(), sys.getTerminal().displayTerminal);
		context.gui.end();
		context.drivers.begin();
		context.drivers.end();
		return true;
	}
}
