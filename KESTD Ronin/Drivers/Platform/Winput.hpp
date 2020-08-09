// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Winput.hpp
// 07.08.2020 14:40
// =============================================================

#pragma once

#include "../../Kernel/Subsystem.hpp"
#include <GLFW/glfw3.h>

namespace kestd::drivers
{
	struct Winput final : kernel::ISubsystem
	{
		Winput();
		auto OnPreStartup(Sys& sys) -> bool override;
		auto OnPostStartup(Sys& sys) -> bool override;
		auto OnPreTick(Sys& sys) -> bool override;
		void OnPreShutdown(Sys& sys) override;
		GLFWwindow* Window = nullptr;
	};
}
