// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// LegacySubsystemBuilder.cpp
// 09.08.2020 07:25
// =============================================================

#include <memory>
#include <vector>
#include <fmt/core.h>
#include "LegacySubsystemBuilder.hpp"
#include "../Detail/Platform/WindowSystem.hpp"
#include "../Detail/Renderer/RenderSystem.hpp"
#include "../Detail/Service/ServiceSystem.hpp"

namespace kestd::kernel
{
	template<typename T> requires std::is_base_of_v<ISubsystem, T>
	void PushSubsystem(const BootConfig& cfg, Environment& env, std::vector<std::unique_ptr<ISubsystem>>& services)
	{
		// Begin stopwatch:
		const auto stopwatch = std::chrono::high_resolution_clock::now();

		// Construct subsystem:
		services.emplace_back(std::make_unique<T>(cfg, env));

		// Profile boot time:
		const auto bootTime = std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::high_resolution_clock::now() - stopwatch).count() / 1000.f;

		// Log boot time:
		env.getProtocol() % fmt::format("Subsystem[{}] BootTime: {}s", services.back()->name, bootTime);
	}

	void InitializeLegacySubsystens(const BootConfig& cfg,
	                                Environment& env,
	                                std::vector<std::unique_ptr<ISubsystem>>& services)
	{
		PushSubsystem<detail::service::ServiceSystem>(cfg, env, services);
		PushSubsystem<detail::WindowSystem>(cfg, env, services);
		PushSubsystem<detail::RenderSystem>(cfg, env, services);
	}
}
