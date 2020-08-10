// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Services.cpp
// 09.08.2020 07:25
// =============================================================

#include "../Drivers/Platform/WindowSystem.hpp"
#include "../Drivers/Renderer/RenderSystem.hpp"
#include "../Drivers/AutoTec/AutoTecSystem.hpp"

namespace kestd::kernel
{
	void queryLegacySubsystems(std::vector<std::unique_ptr<ISubsystem>>& services)
	{
		services.reserve(3);
		services.emplace_back(std::make_unique<drivers::WindowSystem>());
		services.emplace_back(std::make_unique<drivers::RenderSystem>());
		services.emplace_back(std::make_unique<drivers::AutoTecSystem>());
	}
}
