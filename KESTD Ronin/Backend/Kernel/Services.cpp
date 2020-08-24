// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Services.cpp
// 09.08.2020 07:25
// =============================================================

#include <memory>
#include <vector>

#include "../Detail/Platform/WindowSystem.hpp"
#include "../Detail/Renderer/RenderSystem.hpp"

namespace kestd::kernel
{
	void queryLegacySubsystems(std::vector<std::unique_ptr<ISubsystem>>& services)
	{
		services.reserve(3);
		services.emplace_back(std::make_unique<detail::WindowSystem>());
		services.emplace_back(std::make_unique<detail::RenderSystem>());
	}
}
