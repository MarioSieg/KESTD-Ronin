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

	auto RenderContext::Initialize() -> bool
	{
		if (!G_NWH)
		{
			return false;
		}

		Init initData;
		initData.type = RendererType::Direct3D11;
		initData.resolution.width = G_SCREEN.Width;
		initData.resolution.height = G_SCREEN.Height;
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

		setViewRect(0, 0, 0, G_SCREEN.Width, G_SCREEN.Height);

		SysGui.Initialize();
		SysGui.ApplyStyle(Style::Dark);

		return true;
	}

	void RenderContext::BeginGui()
	{
		SysGui.BeginGui();
	}

	void RenderContext::EndGui()
	{
		SysGui.EndGui();
	}

	void RenderContext::Begin()
	{
		touch(0);
	}

	void RenderContext::End()
	{
		frame();
	}

	void RenderContext::Shutdown()
	{
		shutdown();
	}
}
