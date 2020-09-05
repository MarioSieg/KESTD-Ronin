// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// ISubsystem.hpp
// 31.08.2020 15:09
// =============================================================

#pragma once

#include "../../Frontend/Export/KESTD/Environment.hpp"
#include <cstdint>
#include <limits>
#include <type_traits>
#include <string_view>

namespace kestd
{	
	namespace kernel
	{
		struct Event final
		{
			enum Enum : std::uint_fast8_t
			{
				None = 0,
				OnStartup = 1 << 0,
				OnPrepare = 1 << 1,
				OnTick = 1 << 2,
				OnShutdown = 1 << 3,
				Exhaustive = std::numeric_limits<std::uint_fast8_t>::max()
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
			ISubsystem& operator =(const ISubsystem&) = delete;
			ISubsystem& operator =(ISubsystem&&) = delete;
			virtual ~ISubsystem() = default;

			using EventFlags = std::underlying_type<Event::Enum>::type;

			/// <summary>
			/// 
			/// </summary>
			/// <returns>The name of this subsystem.</returns>
			[[nodiscard]]
			auto getName() const noexcept -> std::string_view;

			/// <summary>
			/// 
			/// </summary>
			/// <returns>True if this subsystem is a legacy (buildin) system, else false.</returns>
			[[nodiscard]]
			auto isLegacy() const noexcept -> bool;

			/// <summary>
			/// 
			/// </summary>
			/// <returns>A bitmask containing subscribed events.</returns>
			[[nodiscard]]
			auto getEventFlags() const noexcept -> EventFlags;

			/// <summary>
			/// 
			/// </summary>
			/// <returns>Returns the index of this subsystem in the kernel subsystem list.</returns>
			auto getIndex() const noexcept -> std::size_t;

		protected:
			explicit ISubsystem(std::string_view name, bool isLegacy, EventFlags events = Event::None) noexcept;

			/// <summary>
			/// Early kernel startup.
			/// </summary>
			/// <param name=""></param>
			/// <returns></returns>
			virtual auto onStartup(Environment&) -> bool;

			/// <summary>
			/// Late kernel startup.
			/// </summary>
			/// <param name="">Current runtime environment.</param>
			/// <returns></returns>
			virtual auto onPrepare(Environment&) -> bool;

			/// <summary>
			/// Frame tick.
			/// </summary>
			/// <param name="">Current runtime environment.</param>
			/// <returns></returns>
			virtual auto onTick(Environment&) -> bool;

			/// <summary>
			/// Early kernel shutdown.
			/// </summary>
			/// <param name="">Current runtime environment.</param>
			virtual void onShutdown(Environment&);

		private:
			std::string_view name = {};
			bool legacy = true;
			EventFlags events = Event::None;
			std::size_t index = 0;
		};
	}
}
