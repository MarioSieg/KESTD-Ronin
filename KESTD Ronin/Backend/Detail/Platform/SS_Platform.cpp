// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// SS_Platform.cpp
// 09.08.2020 10:43
// =============================================================

#include "SS_Platform.hpp"
#include "../../Frontend/PlatformInfo.hpp"
#include "../../Frontend/Environment.hpp"

using namespace kestd::kernel;

#if SYS_LINUX
#define GLFW_EXPOSE_NATIVE_X11
#elif SYS_WINDOWS
#define WIN32_LEAN_AND_MEAN
#define GLFW_EXPOSE_NATIVE_WIN32
#elif SYS_MAC
#define GLFW_EXPOSE_NATIVE_COCOA
#endif
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

void* NativeDisplayHandle = nullptr;
void* WindowHandle = nullptr;
void* NativeWindowHandle = nullptr;
extern kestd::ScreenInfo G_SCREEN;

namespace kestd::detail::platform
{
	WindowSystem::WindowSystem(Environment& env): ISubsystem(
		"WindowInputSystem",
		true,
		Event::OnTick | Event::OnPrepare)
	{
		if (!glfwInit())
		{
			throw std::runtime_error("Failed to initialize glfw!");
		}

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_NATIVE_CONTEXT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
		glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

		auto* const monitor = glfwGetPrimaryMonitor();
		if (!monitor)
		{
			throw std::runtime_error("Failed to query primary monitor!");
		}

		const auto* const videoMode = glfwGetVideoMode(monitor);
		if (!videoMode)
		{
			throw std::runtime_error("Failed to query main video mode from monitor!");
		}

		auto* const win = glfwCreateWindow(videoMode->width,
		                                   videoMode->height,
		                                   "KESTD Ronin Engine",
		                                   nullptr,
		                                   nullptr);
		if (!win)
		{
			throw std::runtime_error("Failed to create window!");
		}
		//glfwSetWindowMonitor(win, monitor, 0, 0, videoMode->width, videoMode->height, 144);

		int width, height;
		glfwGetFramebufferSize(win, &width, &height);

		G_SCREEN.width = static_cast<std::uint16_t>(width);
		G_SCREEN.height = static_cast<std::uint16_t>(height);

		window = win;
		NativeWindowHandle = win;

#if SYS_LINUX
		NativeDisplayHandle = glfwGetX11Display();
		WindowHandle = reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(glfwGetX11Window(win)));
#elif SYS_WINDOWS
		WindowHandle = glfwGetWin32Window(win);
#elif SYS_MAC
		WindowHandle = glfwGetCocoaWindow(win);
#endif
	}

	auto WindowSystem::onPrepare(Environment&) -> bool
	{
		glfwShowWindow(window);
		glfwFocusWindow(window);
		return true;
	}

	auto WindowSystem::onTick(Environment&) -> bool
	{
		glfwPollEvents();
		return !glfwWindowShouldClose(window);
	}

	WindowSystem::~WindowSystem()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		NativeDisplayHandle = WindowHandle = NativeWindowHandle = nullptr;
	}
}
