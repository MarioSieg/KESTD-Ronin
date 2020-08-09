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

			const std::string name;
			const std::underlying_type<Event::Enum>::type subscribedEvents;
			const bool isLegacy;

		protected:
			explicit ISubsystem(std::string name,
			                    const std::underlying_type<Event::Enum>::type events,
			                    const bool isLegacy) noexcept;

			virtual auto onPreStartup(Sys&) -> bool;
			virtual auto onPostStartup(Sys&) -> bool;
			virtual auto onPreTick(Sys&) -> bool;
			virtual auto onPostTick(Sys&) -> bool;
			virtual void onPreShutdown(Sys&);
			virtual void onPostShutdown(Sys&);
		};
	}
}
