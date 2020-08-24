// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// WindowSystem.cpp
// 09.08.2020 10:43
// =============================================================

#include "WindowSystem.hpp"
#include "../../Frontend/Platform.hpp"
#include "../../Frontend/Sys.hpp"

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

void* G_NDT = nullptr;
void* G_NWH = nullptr;
void* G_WIN = nullptr;
extern kestd::Screen G_SCREEN;

namespace kestd::detail
{

	WindowSystem::WindowSystem(): ISubsystem("WindowInputSystem", true)
	{
		callbacks.onPreTick = true;

		if (!glfwInit())
		{
			return;
		}

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_NATIVE_CONTEXT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

		auto* const monitor = glfwGetPrimaryMonitor();
		if (!monitor)
		{
			return;
		}

		const auto* const videoMode = glfwGetVideoMode(monitor);
		if (!videoMode)
		{
			return;
		}

		auto* const win = glfwCreateWindow(videoMode->width,
		                                   videoMode->height,
		                                   "KESTD Ronin Engine",
		                                   nullptr,
		                                   nullptr);
		if (!win)
		{
			return;
		}
		//glfwSetWindowMonitor(win, monitor, 0, 0, videoMode->width, videoMode->height, 144);

		int width, height;
		glfwGetFramebufferSize(win, &width, &height);

		G_SCREEN.width = static_cast<std::uint16_t>(width);
		G_SCREEN.height = static_cast<std::uint16_t>(height);

		window = win;
		G_WIN = win;


#if SYS_LINUX
		G_NDT = glfwGetX11Display();
		G_NWH = reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(glfwGetX11Window(win)));
#elif SYS_WINDOWS
		G_NWH = glfwGetWin32Window(win);
#elif SYS_MAC
		G_NWH = glfwGetCocoaWindow(win);
#endif

		glfwShowWindow(window);
		glfwFocusWindow(window);
	}

	WindowSystem::~WindowSystem()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		G_NDT = G_NWH = G_WIN = nullptr;
	}

	auto WindowSystem::onPreTick(Sys& sys) -> bool
	{
		glfwPollEvents();
		//glfwWaitEvents();
		return !glfwWindowShouldClose(window);
	}
}
