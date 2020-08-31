// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// LegacySubsystemBuilder.cpp
// 30.08.2020 12:40
// =============================================================

#include "LegacySubsystemBuilder.hpp"
#include "Detail/Platform/PlatformSystem.hpp"
#include "Detail/Renderer/RenderSystem.hpp"
#include "Detail/Service/ServiceSystem.hpp"
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
