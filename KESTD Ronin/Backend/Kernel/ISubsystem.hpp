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
				bool onStartup : 1;
				bool onPreTick : 1;
				bool onPostTick : 1;
				bool onShutdown : 1;
			} callbacks;

			explicit ISubsystem(std::string&& name, const bool isLegacy) noexcept;

			/// <summary>
			/// Late kernel startup.
			/// </summary>
			/// <param name=""></param>
			/// <returns></returns>
			virtual auto onStartup(Sys&) -> bool;

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
			virtual void onShutdown(Sys&);
		};
	}
}
