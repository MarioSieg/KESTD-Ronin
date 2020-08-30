// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Callbacks.hpp
// 30.08.2020 12:40
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
