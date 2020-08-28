// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// SS_Renderer.cpp
// 09.08.2020 10:43
// =============================================================

#include "SS_Renderer.hpp"
#include "../../Frontend/Environment.hpp"

using namespace kestd::kernel;

kestd::ScreenInfo G_SCREEN;

namespace kestd::detail::renderer
{
	RenderSystem::RenderSystem(Environment& env) :
		ISubsystem("RenderSystem", true, Event::OnTick),
		context(env.getBootConfig().autoTec.getFontSize(), env.getBootConfig().autoTec.getTheme())
	{
		G_SCREEN.width = 1920;
		G_SCREEN.height = 1080;
	}

	RenderSystem::~RenderSystem() = default;

	auto RenderSystem::onTick(Environment& sys) -> bool
	{
		// Begin GUI rendering:
		context.gui.beginFrame();

		// Draw the terminal:
		terminalRenderer.updateAndRender(sys.getProtocol(), sys.getTerminal().displayTerminal);

		// Update and draw the AutoTec editor:
		autoTec.updateAndRender(sys);

		// End GUI rendering:
		context.gui.endFrame();

		// Begin 3D rendering:
		context.drivers.beginFrame();

		// End frame
		context.drivers.endFrame();
		return true;
	}
}
