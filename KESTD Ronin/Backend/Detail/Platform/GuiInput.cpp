// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// GuiInput.cpp
// 09.08.2020 07:24
// =============================================================

#include "GuiInput.hpp"
#include "Callbacks.hpp"

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <cstddef>
#include <limits>

#define HAS_NEW_CURSORS (GLFW_VERSION_MAJOR * 1000 + GLFW_VERSION_MINOR * 100 >= 3400)
#define MAP_BUTTON(NAV_NO, BUTTON_NO)       { if (buttonsCount > BUTTON_NO && buttons[BUTTON_NO] == GLFW_PRESS) io.NavInputs[NAV_NO] = 1.0f; }
#define MAP_ANALOG(NAV_NO, AXIS_NO, V0, V1) { float v = (axesCount > AXIS_NO) ? axes[AXIS_NO] : V0; v = (v - V0) / (V1 - V0); if (v > 1.0f) v = 1.0f; if (io.NavInputs[NAV_NO] < v) io.NavInputs[NAV_NO] = v; }

extern void* G_NWH;
extern void* G_WIN;
extern bool G_MOUSE_PRESSED[ImGuiMouseButton_COUNT];

namespace
{
	GLFWcursor* G_CURSORS[ImGuiMouseCursor_COUNT] = {};
}

namespace kestd::detail
{
	SystemGuiInput::SystemGuiInput()
	{
		auto& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
		io.BackendPlatformName = "KESTR Ronin";

		// Keyboard mapping:
		io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
		io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

		//io.SetClipboardTextFn = ImGui_ImplGlfw_SetClipboardText;
		//io.GetClipboardTextFn = ImGui_ImplGlfw_GetClipboardText;
		//io.ClipboardUserData = g_Window;

		G_CURSORS[ImGuiMouseCursor_Arrow] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
		G_CURSORS[ImGuiMouseCursor_TextInput] = glfwCreateStandardCursor(GLFW_IBEAM_CURSOR);
		G_CURSORS[ImGuiMouseCursor_ResizeNS] = glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR);
		G_CURSORS[ImGuiMouseCursor_ResizeEW] = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);
		G_CURSORS[ImGuiMouseCursor_Hand] = glfwCreateStandardCursor(GLFW_HAND_CURSOR);

#if HAS_NEW_CURSORS

		G_CURSORS[ImGuiMouseCursor_ResizeAll] = glfwCreateStandardCursor(GLFW_RESIZE_ALL_CURSOR);
		G_CURSORS[ImGuiMouseCursor_ResizeNESW] = glfwCreateStandardCursor(GLFW_RESIZE_NESW_CURSOR);
		G_CURSORS[ImGuiMouseCursor_ResizeNWSE] = glfwCreateStandardCursor(GLFW_RESIZE_NWSE_CURSOR);
		G_CURSORS[ImGuiMouseCursor_NotAllowed] = glfwCreateStandardCursor(GLFW_NOT_ALLOWED_CURSOR);

#else

		G_CURSORS[ImGuiMouseCursor_ResizeAll] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
		G_CURSORS[ImGuiMouseCursor_ResizeNESW] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
		G_CURSORS[ImGuiMouseCursor_ResizeNWSE] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
		G_CURSORS[ImGuiMouseCursor_NotAllowed] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);

#endif

		installCallbackProcedures();
	}

	SystemGuiInput::~SystemGuiInput()
	{
		for (auto*& cur : G_CURSORS)
		{
			glfwDestroyCursor(cur);
			cur = nullptr;
		}
	}

	void SystemGuiInput::update()
	{
		int w, h;
		int displayW, displayH;
		glfwGetWindowSize(static_cast<GLFWwindow *>(G_WIN), &w, &h);
		glfwGetFramebufferSize(static_cast<GLFWwindow *>(G_WIN), &displayW, &displayH);
		auto& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(static_cast<float>(w), static_cast<float>(h));
		io.DisplayFramebufferScale = ImVec2(static_cast<float>(displayW) / w, static_cast<float>(displayH) / h);

		// Calculate time:
		const auto currentTime = glfwGetTime();
		static double g_Time;
		io.DeltaTime = g_Time > 0.0 ? static_cast<float>(currentTime - g_Time) : static_cast<float>(1.f / 60.f);
		g_Time = currentTime;
		updateMouse();
		updateCursor();
		updateGamepads();
	}

	void SystemGuiInput::updateMouse()
	{
		auto* const win = static_cast<GLFWwindow *>(G_WIN);
		auto& io = ImGui::GetIO();

		for (std::size_t i = 0; i < sizeof io.MouseDown / sizeof *io.MouseDown; i++)
		{
			io.MouseDown[i] = G_MOUSE_PRESSED[i] || glfwGetMouseButton(win, i);
			G_MOUSE_PRESSED[i] = false;
		}

		// Update mouse position:
		const ImVec2 mousePosBackup = io.MousePos;
		io.MousePos = ImVec2(-std::numeric_limits<float>::max(), -std::numeric_limits<float>::max());

		const bool focused = glfwGetWindowAttrib(win, GLFW_FOCUSED);

		if (focused)
		{
			if (io.WantSetMousePos)
			{
				glfwSetCursorPos(win, static_cast<double>(mousePosBackup.x), static_cast<double>(mousePosBackup.y));
			}
			else
			{
				double mouseX, mouseY;
				glfwGetCursorPos(win, &mouseX, &mouseY);
				io.MousePos = ImVec2(static_cast<float>(mouseX), static_cast<float>(mouseY));
			}
		}
	}

	void SystemGuiInput::updateCursor()
	{
		auto* const win = static_cast<GLFWwindow *>(G_WIN);
		auto& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange || glfwGetInputMode(win, GLFW_CURSOR) ==
			GLFW_CURSOR_DISABLED)
		{
			return;
		}

		const auto guiMouseCursor = ImGui::GetMouseCursor();
		if (guiMouseCursor == ImGuiMouseCursor_None || io.MouseDrawCursor)
		{
			// Hide OS mouse cursor if imgui is drawing it or if it wants no cursor:
			glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
		}
		else
		{
			// Show OS mouse cursor:
			glfwSetCursor(win,
			              G_CURSORS[guiMouseCursor] ? G_CURSORS[guiMouseCursor] : G_CURSORS[ImGuiMouseCursor_Arrow]);
			glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}
	}

	void SystemGuiInput::updateGamepads()
	{
		ImGuiIO& io = ImGui::GetIO();
		memset(io.NavInputs, 0, sizeof io.NavInputs);
		if ((io.ConfigFlags & ImGuiConfigFlags_NavEnableGamepad) == 0)
			return;


		auto axesCount = 0, buttonsCount = 0;
		const float* const axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCount);
		const unsigned char* const buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonsCount);
		MAP_BUTTON(ImGuiNavInput_Activate, 0);   // Cross / A
		MAP_BUTTON(ImGuiNavInput_Cancel, 1);     // Circle / B
		MAP_BUTTON(ImGuiNavInput_Menu, 2);       // Square / X
		MAP_BUTTON(ImGuiNavInput_Input, 3);      // Triangle / Y
		MAP_BUTTON(ImGuiNavInput_DpadLeft, 13);  // D-Pad Left
		MAP_BUTTON(ImGuiNavInput_DpadRight, 11); // D-Pad Right
		MAP_BUTTON(ImGuiNavInput_DpadUp, 10);    // D-Pad Up
		MAP_BUTTON(ImGuiNavInput_DpadDown, 12);  // D-Pad Down
		MAP_BUTTON(ImGuiNavInput_FocusPrev, 4);  // L1 / LB
		MAP_BUTTON(ImGuiNavInput_FocusNext, 5);  // R1 / RB
		MAP_BUTTON(ImGuiNavInput_TweakSlow, 4);  // L1 / LB
		MAP_BUTTON(ImGuiNavInput_TweakFast, 5);  // R1 / RB
		MAP_ANALOG(ImGuiNavInput_LStickLeft, 0, -0.3f, -0.9f);
		MAP_ANALOG(ImGuiNavInput_LStickRight, 0, +0.3f, +0.9f);
		MAP_ANALOG(ImGuiNavInput_LStickUp, 1, +0.3f, +0.9f);
		MAP_ANALOG(ImGuiNavInput_LStickDown, 1, -0.3f, -0.9f);

		if (axesCount > 0 && buttonsCount > 0)
		{
			io.BackendFlags |= ImGuiBackendFlags_HasGamepad;
		}
		else
		{
			io.BackendFlags &= ~ImGuiBackendFlags_HasGamepad;
		}
	}

	void SystemGuiInput::installCallbackProcedures()
	{
		auto* const win = static_cast<GLFWwindow *>(G_WIN);
		glfwSetMouseButtonCallback(win, mouseButtonCallback);
		glfwSetScrollCallback(win, scrollCallback);
		glfwSetKeyCallback(win, keyCallback);
		glfwSetCharCallback(win, charCallback);
	}
}
