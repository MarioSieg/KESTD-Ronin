// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Drivers.cpp
// 30.08.2020 12:40
// =============================================================

#include "Drivers.hpp"
#include <stdexcept>
#include <bgfx/bgfx.h>

using namespace bgfx;

extern void* NativeDisplayHandle;
extern void* WindowHandle;

namespace kestd::detail::renderer
{
	Drivers::Drivers(const GraphicsConfig& cfg)
	{
		if (!WindowHandle)
		{
			throw std::runtime_error("Invalid window handle!");
		}

		Init initData;
		initData.type = RendererType::Vulkan;
		initData.resolution.width = cfg.getWidth();
		initData.resolution.height = cfg.getHeight();
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

		setViewRect(0, 0, 0, cfg.getWidth(), cfg.getHeight());
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
