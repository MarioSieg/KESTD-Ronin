// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Renderer.cpp
// 07.08.2020 21:39
// =============================================================

#include "Renderer.hpp"
#include "../../Sys.hpp"

using namespace kestd::kernel;

namespace kestd::drivers
{
	Screen G_SCREEN;

	Renderer::Renderer() : ISubsystem("Renderer", true)
	{
		callbacks.onPreStartup = true;
		callbacks.onPreTick = true;
		callbacks.onPostTick = true;
		callbacks.onPreShutdown = true;
	}
	 
	auto Renderer::onPreStartup(Sys& sys) -> bool
	{
		G_SCREEN = sys.screen;
		return context.initialize();
	}

	auto Renderer::onPreTick(Sys& sys) -> bool
	{
		context.beginGui();
		return true;
	}

	auto Renderer::onPostTick(Sys& sys) -> bool
	{
		context.endGui();
		context.begin();
		context.end();
		return true;
	}

	void Renderer::onPreShutdown(Sys& sys)
	{
		context.shutdown();
	}
}
