// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// IPlatformSystem.cpp
// 30.08.2020 12:40
// =============================================================

#include "IPlatformSystem.hpp"
#include "../../Frontend/Export/KESTD/Platform.hpp"
#include "../../Frontend/Export/KESTD/Environment.hpp"

using namespace kestd::kernel;

#if SYS_LINUX
#define GLFW_EXPOSE_NATIVE_X11
#elif SYS_WINDOWS
#define WIN32_LEAN_AND_MEAN
#define GLFW_EXPOSE_NATIVE_WIN32
#elif SYS_MAC
#define GLFW_EXPOSE_NATIVE_COCOA
#endif
#include <GLFW/glfw3native.h>

void* NativeDisplayHandle = nullptr;
void* WindowHandle = nullptr;
void* NativeWindowHandle = nullptr;

namespace kestd::detail::platform
{
	IPlatformSystem::IPlatformSystem(Environment& env): ISubsystem(
		"WindowInputSystem",
		true,
		Event::OnTick | Event::OnPrepare)
	{
		if (!glfwInit())
		{
			throw std::runtime_error("Failed to initialize glfw!");
		}

		const auto windowMode = env.getBootConfig().getConfigForGraphics().getWindowMode();

		// TODO: Replace with Resolution
		const auto width = env.getBootConfig().getConfigForGraphics().getWidth();
		const auto height = env.getBootConfig().getConfigForGraphics().getHeight();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_NATIVE_CONTEXT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
		glfwWindowHint(GLFW_MAXIMIZED, windowMode == WindowMode::WindowedMaximized ? GLFW_TRUE : GLFW_FALSE);

		auto* const monitor = glfwGetPrimaryMonitor();
		if (!monitor)
		{
			throw std::runtime_error("Failed to query primary monitor!");
		}

		const auto* const videoMode = glfwGetVideoMode(monitor);
		if (!videoMode)
		{
			throw std::runtime_error("Failed to query primary video mode!");
		}

		auto* const win = glfwCreateWindow(windowMode == WindowMode::FullScreen ? videoMode->width : width,
		                                   windowMode == WindowMode::FullScreen ? videoMode->height : height,
		                                   "KESTD Ronin Engine",
		                                   windowMode == WindowMode::FullScreen ? monitor : nullptr,
		                                   nullptr);
		if (!win)
		{
			throw std::runtime_error("Failed to create window!");
		}

		if (windowMode != WindowMode::Windowed)
		{
			int w, h;
			glfwGetFramebufferSize(win, &w, &h);
			env.getBootConfig().getConfigForGraphics().setWidth(w);
			env.getBootConfig().getConfigForGraphics().setHeight(h);
		}

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

	auto IPlatformSystem::onPrepare(Environment&) -> bool
	{
		glfwShowWindow(window);
		glfwFocusWindow(window);
		return true;
	}

	auto IPlatformSystem::onTick(Environment&) -> bool
	{
		glfwPollEvents();
		return !glfwWindowShouldClose(window);
	}

	IPlatformSystem::~IPlatformSystem()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		NativeDisplayHandle = WindowHandle = NativeWindowHandle = nullptr;
	}
}
