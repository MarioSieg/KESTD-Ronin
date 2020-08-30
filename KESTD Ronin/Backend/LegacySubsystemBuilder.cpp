// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// LegacySubsystemBuilder.cpp
// 30.08.2020 12:40
// =============================================================

#include "LegacySubsystemBuilder.hpp"
#include "Detail/Platform/SS_Platform.hpp"
#include "Detail/Renderer/SS_Renderer.hpp"
#include "Detail/Service/SS_Service.hpp"
#include "Kernel/Kernel.hpp"

namespace kestd::kernel
{
	void PushLegacySubsystens(Kernel& ker)
	{
		ker.makeSubsystem<detail::service::ServiceSystem>();
		ker.makeSubsystem<detail::platform::WindowSystem>();
		ker.makeSubsystem<detail::renderer::RenderSystem>();
	}
}
