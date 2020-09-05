// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// IPlatformSystem.hpp
// 31.08.2020 15:09
// =============================================================

#pragma once

#include "../../Kernel/Export/KESTD/ISubsystem.hpp"
#include <GLFW/glfw3.h>

namespace kestd::detail::platform
{
	class IPlatformSystem final : public kernel::ISubsystem
	{
	public:
		IPlatformSystem(Environment& env);
		IPlatformSystem(const IPlatformSystem&) = delete;
		IPlatformSystem(IPlatformSystem&&) = delete;
		IPlatformSystem& operator=(const IPlatformSystem&) = delete;
		IPlatformSystem& operator=(IPlatformSystem&&) = delete;
		~IPlatformSystem() override;

	private:
		auto onPrepare(Environment&) -> bool override;
		auto onTick(Environment& sys) -> bool override;
		GLFWwindow* window;
	};
}
