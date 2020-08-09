// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Winput.cpp
// 07.08.2020 14:40
// =============================================================

#include "Winput.hpp"
#include "../../Platform.hpp"
#include "../../Sys.hpp"

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

namespace kestd::drivers
{
	void* G_NDT = nullptr;
	void* G_NWH = nullptr;
	void* G_WIN = nullptr;

	Winput::Winput(): ISubsystem("WindowInputSystem", true)
	{
		callbacks.onPreStartup = true;
		callbacks.onPostStartup = true;
		callbacks.onPreTick = true;
		callbacks.onPreShutdown = true;
	}

	auto Winput::onPreStartup(Sys& sys) -> bool
	{
		if (!glfwInit())
		{
			return false;
		}

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_NATIVE_CONTEXT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

		auto* const monitor = glfwGetPrimaryMonitor();
		if (!monitor)
		{
			return false;
		}

		const auto* const videoMode = glfwGetVideoMode(monitor);
		if (!videoMode)
		{
			return false;
		}

		auto* const win = glfwCreateWindow(videoMode->width,
		                                      videoMode->height,
		                                      "KESTD Ronin Engine",
		                                      nullptr,
		                                      nullptr);
		if (!win)
		{
			return false;
		}
		//glfwSetWindowMonitor(win, monitor, 0, 0, videoMode->width, videoMode->height, 144);

		int width, height;
		glfwGetFramebufferSize(win, &width, &height);

		sys.screen.width = static_cast<std::uint16_t>(width);
		sys.screen.height = static_cast<std::uint16_t>(height);

		window = win;
		G_WIN = win;


#if SYS_LINUX
		G_NDT = glfwGetX11Display();
		G_NWH = reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(glfwGetX11Window(win)));
#elif SYS_WINDOWS
		G_NWH = glfwGetWin32Window(win);
#elif SYS_MAC
		G_NWH = glfwGetCocoaWindow(win);
#endif

		return true;
	}

	auto Winput::onPostStartup(Sys& sys) -> bool
	{
		glfwShowWindow(window);
		glfwFocusWindow(window);
		return true;
	}

	auto Winput::onPreTick(Sys& sys) -> bool
	{
		glfwPollEvents();
		//glfwWaitEvents();
		return !glfwWindowShouldClose(window);
	}

	void Winput::onPreShutdown(Sys& sys)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		G_NDT = G_NWH = G_WIN = nullptr;
	}
}
