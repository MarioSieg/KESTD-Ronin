// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Subsystem.hpp
// 07.08.2020 02:30
// =============================================================

#pragma once

#include <cstdint>
#include <string>

namespace kestd
{
	class Sys;

	namespace kernel
	{
		struct Event final
		{
			enum Enum : std::uint8_t
			{
				None = 0,
				OnPreStartup = 1 << 0,
				OnPostStartup = 1 << 1,
				OnPreTick = 1 << 2,
				OnPostTick = 1 << 3,
				OnPreShutdown = 1 << 4,
				OnPostShutdown = 1 << 5,
			};
		};

		class ISubsystem
		{
			friend class Kernel;

		public:
			ISubsystem(const ISubsystem&) = delete;
			ISubsystem(ISubsystem&&) = delete;
			auto operator =(const ISubsystem&) -> ISubsystem& = delete;
			auto operator =(ISubsystem&&) -> ISubsystem& = delete;
			virtual ~ISubsystem() = default;

			const std::string Name;
			const std::underlying_type<Event::Enum>::type SubscribedEvents;
			const bool IsLegacy;

		protected:
			explicit ISubsystem(std::string name,
			                    const std::underlying_type<Event::Enum>::type events,
			                    const bool is_legacy) noexcept;

			virtual auto OnPreStartup(Sys&) -> bool;
			virtual auto OnPostStartup(Sys&) -> bool;
			virtual auto OnPreTick(Sys&) -> bool;
			virtual auto OnPostTick(Sys&) -> bool;
			virtual void OnPreShutdown(Sys&);
			virtual void OnPostShutdown(Sys&);
		};
	}
}
