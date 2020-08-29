// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// SS_Platform.hpp
// 09.08.2020 10:43
// =============================================================

#pragma once

#include "../../Kernel/ISubsystem.hpp"

class GLFWwindow;

namespace kestd::detail::platform
{
	class WindowSystem final : public kernel::ISubsystem
	{
	public:
		WindowSystem(Environment& env);
		WindowSystem(const WindowSystem&) = delete;
		WindowSystem(WindowSystem&&) = delete;
		WindowSystem& operator=(const WindowSystem&) = delete;
		WindowSystem& operator=(WindowSystem&&) = delete;
		~WindowSystem() override;

	private:
		auto onPrepare(Environment&) -> bool override;
		auto onTick(Environment& sys) -> bool override;
		GLFWwindow* window;
	};
}
