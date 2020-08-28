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
	template<typename T, typename... Args> requires std::is_base_of_v<ISubsystem, T>
	void PushSubsystem(LegacySubsystemBuildDescriptor desc, Args&&... args)
	{
		// Begin stopwatch:
		const auto stopwatch = std::chrono::high_resolution_clock::now();

		// Construct subsystem:
		desc.sysref.emplace_back(std::make_unique<T>(desc.cfg, desc.env, args...));

		// Profile boot time:
		const auto bootTime = std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::high_resolution_clock::now() - stopwatch).count() / 1000.f;

		// Log boot time:
		desc.env.getProtocol() % fmt::format("Subsystem[{}] BootTime: {}s", desc.sysref.back()->name, bootTime);
	}

	void InitializeLegacySubsystens(LegacySubsystemBuildDescriptor desc)
	{
		PushSubsystem<detail::service::ServiceSystem>(desc);
		PushSubsystem<detail::platform::WindowSystem>(desc);
		PushSubsystem<detail::renderer::RenderSystem>(desc);
	}
}
