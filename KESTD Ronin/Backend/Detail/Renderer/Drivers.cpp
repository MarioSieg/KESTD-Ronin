// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Drivers.cpp
// 10.08.2020 13:41
// =============================================================

#include "../../Frontend/ScreenInfo.hpp"
#include "Drivers.hpp"
#include <stdexcept>
#include <bgfx/bgfx.h>

using namespace bgfx;

extern void* NativeDisplayHandle;
extern void* WindowHandle;
extern kestd::ScreenInfo G_SCREEN;

namespace kestd::detail::renderer
{
	Drivers::Drivers()
	{
		if (!WindowHandle)
		{
			throw std::runtime_error("Invalid window handle!");
		}

		Init initData;
		initData.type = RendererType::Vulkan;
		initData.resolution.width = G_SCREEN.width;
		initData.resolution.height = G_SCREEN.height;
		initData.resolution.reset = BGFX_RESET_MSAA_X16;
		initData.platformData.nwh = WindowHandle;
		initData.platformData.ndt = NativeDisplayHandle;

		if (!init(initData))
		{
			throw std::runtime_error("Failed to initialize graphics backend!");
		}

		setDebug(BGFX_DEBUG_NONE);

		setViewClear(0,
		             BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH,
		             0x303030ff,
		             1.0f,
		             0
		);

		setViewRect(0, 0, 0, G_SCREEN.width, G_SCREEN.height);
	}

	Drivers::~Drivers()
	{
		shutdown();
	}

	void Drivers::beginFrame()
	{
		touch(0);
	}

	void Drivers::endFrame()
	{
		frame();
	}
}
