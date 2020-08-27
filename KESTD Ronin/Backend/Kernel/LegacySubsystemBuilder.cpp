// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// LegacySubsystemBuilder.cpp
// 09.08.2020 07:25
// =============================================================

#include <memory>
#include <vector>

#include "../Detail/Platform/WindowSystem.hpp"
#include "../Detail/Renderer/RenderSystem.hpp"
#include "../Detail/Service/ServiceSystem.hpp"

namespace kestd::kernel
{
	void InitializeLegacySubsystens(const BootConfig& cfg, std::vector<std::unique_ptr<ISubsystem>>& services)
	{
		services.reserve(3);
		services.emplace_back(std::make_unique<detail::service::ServiceSystem>(cfg));
		services.emplace_back(std::make_unique<detail::WindowSystem>(cfg));
		services.emplace_back(std::make_unique<detail::RenderSystem>(cfg));
	}
}
