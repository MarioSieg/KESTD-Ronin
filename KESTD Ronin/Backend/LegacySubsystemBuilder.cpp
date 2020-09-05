// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// LegacySubsystemBuilder.cpp
// 31.08.2020 15:09
// =============================================================

#include "LegacySubsystemBuilder.hpp"
#include "../Kernel/Export/KESTD/Kernel.hpp"

//-----LegacySubsystems-----//
#include "Detail/Platform/IPlatformSystem.hpp"
#include "Detail/Renderer/IRenderSystem.hpp"
#include "Detail/Service/IServiceSystem.hpp"
#include "Detail/Scripting/IScriptingSystem.hpp"

namespace kestd::kernel
{
	void PushLegacySubsystens(Kernel& ker)
	{
		ker.makeSubsystem<detail::service::IServiceSystem>();
		ker.makeSubsystem<detail::platform::IPlatformSystem>();
		ker.makeSubsystem<detail::renderer::IRenderSystem>();
		ker.makeSubsystem<detail::scripting::IScriptingSystem>();
	}
}
