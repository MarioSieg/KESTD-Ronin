// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Drivers.cpp
// 10.08.2020 13:41
// =============================================================

#include "Drivers.hpp"
#include "../../Frontend/ScreenInfo.hpp"
#include <bgfx/bgfx.h>

using namespace bgfx;

extern void* G_NDT;
extern void* G_NWH;
extern kestd::ScreenInfo G_SCREEN;

namespace kestd::detail
{
	Drivers::Drivers()
	{
		if (!G_NWH)
		{
			return;
		}

		Init initData;
		initData.type = RendererType::Vulkan;
		initData.resolution.width = G_SCREEN.width;
		initData.resolution.height = G_SCREEN.height;
		initData.resolution.reset = BGFX_RESET_MSAA_X16;
		initData.platformData.nwh = G_NWH;
		initData.platformData.ndt = G_NDT;

		if (!init(initData))
		{
			return;
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

	void Drivers::begin()
	{
		touch(0);
	}

	void Drivers::end()
	{
		frame();
	}
}
