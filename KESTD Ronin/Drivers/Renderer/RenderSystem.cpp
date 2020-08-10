// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// RenderSystem.cpp
// 09.08.2020 10:43
// =============================================================

#include "RenderSystem.hpp"
#include "../../Sys.hpp"

using namespace kestd::kernel;

namespace kestd::drivers
{
	Screen G_SCREEN;

	RenderSystem::RenderSystem() : ISubsystem("RenderSystem", true)
	{
		callbacks.onPreTick = true;
		callbacks.onPostTick = true;
		G_SCREEN.width = 1920;
		G_SCREEN.height = 1080;
	}

	RenderSystem::~RenderSystem() = default;

	auto RenderSystem::onPreTick(Sys& sys) -> bool
	{
		context.gui.begin();
		return true;
	}

	auto RenderSystem::onPostTick(Sys& sys) -> bool
	{
		context.gui.end();
		context.drivers.begin();
		context.drivers.end();
		return true;
	}
}
