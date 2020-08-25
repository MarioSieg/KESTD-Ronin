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
	void InitializeLegacySubsystens(const BootConfig& cfg, std::vector<std::unique_ptr<ISubsystem>>& services)
	{
		services.reserve(2);
		services.emplace_back(std::make_unique<detail::WindowSystem>(cfg));
		services.emplace_back(std::make_unique<detail::RenderSystem>(cfg));
	}
}
