// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// IRenderSystem.cpp
// 30.08.2020 12:40
// =============================================================

#include "IRenderSystem.hpp"
#include "../../Frontend/Export/KESTD/Environment.hpp"

using namespace kestd::kernel;

namespace kestd::detail::renderer
{
	IRenderSystem::IRenderSystem(Environment& env) :
		ISubsystem("IRenderSystem", true, Event::OnTick),
		context(env.getBootConfig())
	{
	}

	IRenderSystem::~IRenderSystem() = default;

	auto IRenderSystem::onTick(Environment& sys) -> bool
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
