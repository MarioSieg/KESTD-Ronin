// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// ServiceSystem.hpp
// 27.08.2020 12:30
// =============================================================

#pragma once

#include "../../Frontend/BootConfig.hpp"
#include "../../Kernel/ISubsystem.hpp"

namespace kestd::detail::service
{
	class ServiceSystem final : public kernel::ISubsystem
	{
	public:
		ServiceSystem(const BootConfig& cfg);
		ServiceSystem(const ServiceSystem&) = delete;
		ServiceSystem(ServiceSystem&&) = delete;
		ServiceSystem& operator=(const ServiceSystem&) = delete;
		ServiceSystem& operator=(ServiceSystem&&) = delete;
		~ServiceSystem();

	private:
		auto onStartup(Environment&) -> bool override;
		auto onPrepare(Environment&) -> bool override;
		auto onTick(Environment&) -> bool override;
		void onShutdown(Environment&) override;
	};
}
