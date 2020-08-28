// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Callbacks.hpp
// 10.08.2020 13:33
// =============================================================

#pragma once

struct GLFWwindow;

namespace kestd::detail::platform
{
	void MouseButtonCallback(GLFWwindow* const win, const int button, const int action, const int mods);
	void ScrollCallback(GLFWwindow* const win, const double x, const double y);
	void KeyCallback(GLFWwindow* const win, const int key, const int scancode, const int action, const int mods);
	void CharCallback(GLFWwindow* const win, const unsigned c);
}
