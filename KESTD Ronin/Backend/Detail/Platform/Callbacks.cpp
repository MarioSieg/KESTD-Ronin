// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Callbacks.cpp
// 10.08.2020 13:33
// =============================================================

#include "Callbacks.hpp"
#include <GLFW/glfw3.h>
#include <imgui.h>

bool G_MOUSE_PRESSED[ImGuiMouseButton_COUNT];

namespace kestd::detail
{
	void mouseButtonCallback(GLFWwindow* const win, const int button, const int action, const int mods)
	{
		if (action == GLFW_PRESS && button >= 0 && button < static_cast<int>(sizeof G_MOUSE_PRESSED / sizeof *
			G_MOUSE_PRESSED))
		{
			G_MOUSE_PRESSED[button] = true;
		}
	}

	void scrollCallback(GLFWwindow* const win, const double x, const double y)
	{
		auto& io = ImGui::GetIO();
		io.MouseWheelH += static_cast<float>(x);
		io.MouseWheel += static_cast<float>(y);
	}

	void keyCallback(GLFWwindow* const win, const int key, const int scancode, const int action, const int mods)
	{
		auto& io = ImGui::GetIO();
		if (action == GLFW_PRESS)
		{
			io.KeysDown[key] = true;
		}
		if (action == GLFW_RELEASE)
		{
			io.KeysDown[key] = false;
		}
		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
#if SYS_WINDOWS
		io.KeySuper = false;
#else
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
#endif
	}

	void charCallback(GLFWwindow* const win, const unsigned c)
	{
		auto& io = ImGui::GetIO();
		io.AddInputCharacter(c);
	}
}
