// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// SS_Renderer.cpp
// 30.08.2020 12:40
// =============================================================

#include "SS_Renderer.hpp"
#include "../../Frontend/Export/KESTD/Environment.hpp"

using namespace kestd::kernel;

namespace kestd::detail::renderer
{
	RenderSystem::RenderSystem(Environment& env) :
		ISubsystem("RenderSystem", true, Event::OnTick),
		context(env.getBootConfig())
	{
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
