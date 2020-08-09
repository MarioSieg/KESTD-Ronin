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

	Winput::Winput(): ISubsystem("WindowInputSystem",
	                             Event::OnPreStartup | Event::OnPostStartup | Event::OnPreTick | Event::OnPreShutdown,
	                             true)
	{
	}

	auto Winput::OnPreStartup(Sys& sys) -> bool
	{
		if (!glfwInit())
		{
			return false;
		}

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
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

		auto* const window = glfwCreateWindow(videoMode->width,
		                                      videoMode->width,
		                                      "KESTD Ronin Engine",
		                                      nullptr,
		                                      nullptr);
		if (!window)
		{
			return false;
		}

		int width, height;
		glfwGetFramebufferSize(window, &width, &height);

		sys.Screen.Width = static_cast<std::uint16_t>(width);
		sys.Screen.Height = static_cast<std::uint16_t>(height);

		Window = window;
		G_WIN = window;


#if SYS_LINUX
		G_NDT = glfwGetX11Display();
		G_NWH = reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(glfwGetX11Window(Window)));
#elif SYS_WINDOWS
		G_NWH = glfwGetWin32Window(Window);
#elif SYS_MAC
		G_NWH = glfwGetCocoaWindow(Window);
#endif

		return true;
	}

	auto Winput::OnPostStartup(Sys& sys) -> bool
	{
		glfwShowWindow(Window);
		glfwFocusWindow(Window);
		return true;
	}

	auto Winput::OnPreTick(Sys& sys) -> bool
	{
		glfwPollEvents();
		return !glfwWindowShouldClose(Window);
	}

	void Winput::OnPreShutdown(Sys& sys)
	{
		glfwDestroyWindow(Window);
		glfwTerminate();
		G_NDT = G_NWH = G_WIN = nullptr;
	}
}
