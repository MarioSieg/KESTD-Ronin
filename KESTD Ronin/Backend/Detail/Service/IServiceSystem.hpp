// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// IServiceSystem.hpp
// 31.08.2020 15:09
// =============================================================

#pragma once

#include "../../Kernel/Export/KESTD/ISubsystem.hpp"

namespace kestd::detail::service
{
	class IServiceSystem final : public kernel::ISubsystem
	{
	public:
		IServiceSystem(Environment& env);
		IServiceSystem(const IServiceSystem&) = delete;
		IServiceSystem(IServiceSystem&&) = delete;
		IServiceSystem& operator=(const IServiceSystem&) = delete;
		IServiceSystem& operator=(IServiceSystem&&) = delete;
		~IServiceSystem();

	private:
		auto onStartup(Environment&) -> bool override;
		auto onPrepare(Environment&) -> bool override;
		auto onTick(Environment&) -> bool override;
		void onShutdown(Environment&) override;
	};
}
