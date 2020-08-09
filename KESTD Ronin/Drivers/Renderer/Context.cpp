// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Context.cpp
// 08.08.2020 00:21
// =============================================================

#include "Context.hpp"
#include "../../Screen.hpp"
#include <bgfx/bgfx.h>

using namespace std;
using namespace bgfx;

namespace kestd::drivers
{
	extern void* G_NDT;
	extern void* G_NWH;
	extern Screen G_SCREEN;

	auto RenderContext::initialize() -> bool
	{
		if (!G_NWH)
		{
			return false;
		}

		Init initData;
		initData.type = RendererType::Direct3D11;
		initData.resolution.width = G_SCREEN.width;
		initData.resolution.height = G_SCREEN.height;
		initData.resolution.reset = BGFX_RESET_MSAA_X16;
		initData.platformData.nwh = G_NWH;
		initData.platformData.ndt = G_NDT;

		if (!init(initData))
		{
			return false;
		}

		setDebug(BGFX_DEBUG_NONE);

		setViewClear(0,
		             BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH,
		             0x303030ff,
		             1.0f,
		             0
		);

		setViewRect(0, 0, 0, G_SCREEN.width, G_SCREEN.height);

		sysGui.initialize();
		sysGui.applyStyle(Style::Dark);

		return true;
	}

	void RenderContext::beginGui()
	{
		sysGui.beginGui();
	}

	void RenderContext::endGui()
	{
		sysGui.endGui();
	}

	void RenderContext::begin()
	{
		bgfx::touch(0);
	}

	void RenderContext::end()
	{
		bgfx::frame();
	}

	void RenderContext::shutdown()
	{
		bgfx::shutdown();
	}
}
