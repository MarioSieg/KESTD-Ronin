// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD Ronin
// Mario
// Winput.hpp
// 07.08.2020 14:40

#pragma once

#include "../../Kernel/Subsystem.hpp"
#include <GLFW/glfw3.h>

using namespace kestd::kernel;

namespace kestd::drivers
{
	struct Winput : ISubsystem
	{
		Winput();
		auto OnPreStartup(Sys& sys) -> bool final;
		auto OnPostStartup(Sys& sys) -> bool final;
		auto OnPreTick(Sys& sys) -> bool final;
		void OnPreShutdown(Sys& sys) final;
		GLFWwindow* Window = nullptr;
	};
}
