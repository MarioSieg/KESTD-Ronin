// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Winput.hpp
// 07.08.2020 14:40
// =============================================================

#pragma once

#include "../../Kernel/ISubsystem.hpp"
#include <GLFW/glfw3.h>

namespace kestd::drivers
{
	class Winput final : public kernel::ISubsystem
	{
	public:
		Winput();

	private:
		auto onPreStartup(Sys& sys) -> bool override;
		auto onPostStartup(Sys& sys) -> bool override;
		auto onPreTick(Sys& sys) -> bool override;
		void onPreShutdown(Sys& sys) override;
		GLFWwindow* window = nullptr;
	};
}
