// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// SS_Service.hpp
// 27.08.2020 12:30
// =============================================================

#pragma once

#include "../../Kernel/ISubsystem.hpp"

namespace kestd::detail::service
{
	class ServiceSystem final : public kernel::ISubsystem
	{
	public:
		ServiceSystem(Environment& env);
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
