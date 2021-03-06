// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Callbacks.hpp
// 31.08.2020 15:09
// =============================================================

#pragma once

class GLFWwindow;

namespace kestd::detail::platform
{
	void MouseButtonCallback(GLFWwindow* win, int button, int action, int mods);
	void ScrollCallback(GLFWwindow* win, double x, double y);
	void KeyCallback(GLFWwindow* win, int key, int scancode, int action, int mods);
	void CharCallback(GLFWwindow* win, unsigned c);
}
