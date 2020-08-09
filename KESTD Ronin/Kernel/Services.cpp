// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Services.cpp
// 07.08.2020 15:46
// =============================================================

#include "../Drivers/Platform/Winput.hpp"
#include "../Drivers/Renderer/Renderer.hpp"
#include "../Drivers/AutoTec/AutoTec.hpp"

namespace kestd::kernel
{
	void QueryLegacySubsystems(std::vector<std::unique_ptr<ISubsystem>>& services)
	{
		services.reserve(3);
		services.emplace_back(std::make_unique<drivers::Winput>());
		services.emplace_back(std::make_unique<drivers::Renderer>());
		services.emplace_back(std::make_unique<drivers::AutoTec>());
	}
}
