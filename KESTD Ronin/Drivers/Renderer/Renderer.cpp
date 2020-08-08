// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD Ronin
// Mario
// Renderer.cpp
// 07.08.2020 21:39

#include "Renderer.hpp"
#include "../../Sys.hpp"

namespace kestd::drivers
{
	Screen G_SCREEN;
	
	Renderer::Renderer() : ISubsystem("Renderer", Event::PreStartup | Event::PostTick | Event::PreShutdown, true)
	{
	}

	auto Renderer::OnPreStartup(Sys& sys) -> bool
	{
		G_SCREEN = sys.Screen;
		return Context.Initialize();
	}

	auto Renderer::OnPostTick(Sys& sys) -> bool
	{
		Context.BeginGui();
		Context.EndGui();
		Context.Begin();
		Context.End();
		return true;
	}

	void Renderer::OnPreShutdown(Sys& sys)
	{
		Context.Shutdown();
	}
}
