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

		protected:
			struct
			{
				bool onPreStartup : 1;
				bool onPostStartup : 1;
				bool onPreTick : 1;
				bool onPostTick : 1;
				bool onPreShutdown : 1;
				bool onPostShutdown : 1;
			} callbacks = {};
			
			explicit ISubsystem(std::string &&name, const bool isLegacy) noexcept;

			/// <summary>
			/// Eary kernel startup.
			/// </summary>
			/// <param name=""></param>
			/// <returns></returns>
			virtual auto onPreStartup(Sys&) -> bool;

			/// <summary>
			/// Late kernel startup.
			/// </summary>
			/// <param name=""></param>
			/// <returns></returns>
			virtual auto onPostStartup(Sys&) -> bool;

			/// <summary>
			/// Early frame tick.
			/// </summary>
			/// <param name=""></param>
			/// <returns></returns>
			virtual auto onPreTick(Sys&) -> bool;

			/// <summary>
			/// Late frame tick.
			/// </summary>
			/// <param name=""></param>
			/// <returns></returns>
			virtual auto onPostTick(Sys&) -> bool;

			/// <summary>
			/// Early kernel shutdown.
			/// </summary>
			/// <param name=""></param>
			virtual void onPreShutdown(Sys&);

			/// <summary>
			/// Late kernel shutdown.
			/// </summary>
			/// <param name=""></param>
			virtual void onPostShutdown(Sys&);
		};
	}
}
