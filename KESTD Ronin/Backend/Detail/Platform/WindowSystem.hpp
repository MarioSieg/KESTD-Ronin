// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// WindowSystem.hpp
// 09.08.2020 10:43
// =============================================================

#pragma once

#include "../../Kernel/ISubsystem.hpp"
#include <GLFW/glfw3.h>

namespace kestd::detail
{
	class WindowSystem final : public kernel::ISubsystem
	{
	public:
		WindowSystem();
		~WindowSystem() override;

	private:
		auto onPreTick(Sys& sys) -> bool override;
		GLFWwindow* window = nullptr;
	};
}
