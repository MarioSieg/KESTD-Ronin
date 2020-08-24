// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// ISubsystem.hpp
// 09.08.2020 10:43
// =============================================================

#pragma once

#include <string>

namespace kestd
{
	class Sys;

	namespace kernel
	{
		struct Event final
		{
			enum Enum : std::uint_fast8_t
			{
				None = 0,
				Startup = 1 << 0,
				Tick = 1 << 1,
				Shutdown = 1 << 2,
			};
		};
		
		/// <summary>
		/// Base interface for all engine kernel subystems.
		/// </summary>
		class ISubsystem
		{
			friend class Kernel;

		public:
			ISubsystem(const ISubsystem&) = delete;
			ISubsystem(ISubsystem&&) = delete;
			auto operator =(const ISubsystem&) -> ISubsystem& = delete;
			auto operator =(ISubsystem&&) -> ISubsystem& = delete;
			virtual ~ISubsystem() = default;

			/// <summary>
			/// The name of this subsystem.
			/// </summary>
			const std::string name;

			/// <summary>
			/// Is this a legacy or a buildin subsystem?
			/// </summary>
			const bool isLegacy;

			/// <summary>
			/// Subscribed events.
			/// </summary>
			const Event::Enum events;
			
		protected:
			explicit ISubsystem(std::string&& name, const bool isLegacy, const Event::Enum events) noexcept;

			/// <summary>
			/// Late kernel startup.
			/// </summary>
			/// <param name=""></param>
			/// <returns></returns>
			virtual auto onStartup(Sys&) -> bool;

			/// <summary>
			/// Frame tick.
			/// </summary>
			/// <param name=""></param>
			/// <returns></returns>
			virtual auto onTick(Sys&) -> bool;

			/// <summary>
			/// Early kernel shutdown.
			/// </summary>
			/// <param name=""></param>
			virtual void onShutdown(Sys&);
		};
	}
}
