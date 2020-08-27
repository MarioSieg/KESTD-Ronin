// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// ISubsystem.hpp
// 09.08.2020 10:43
// =============================================================

#pragma once

#include <string>
#include "../../Frontend/Environment.hpp"

namespace kestd::kernel
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
		const std::underlying_type<Event::Enum>::type events;

	protected:
		explicit ISubsystem(std::string&& name,
		                    const bool isLegacy,
		                    const std::underlying_type<Event::Enum>::type events = Event::None) noexcept;

		/// <summary>
		/// Called on startup.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		virtual auto onStartup(Environment&) -> bool;

		/// <summary>
		/// Called before entering the runtime loop.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		virtual auto onPrepare(Environment&) -> bool;

		/// <summary>
		/// Frame tick.
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		virtual auto onTick(Environment&) -> bool;

		/// <summary>
		/// Early kernel shutdown.
		/// </summary>
		/// <param name=""></param>
		virtual void onShutdown(Environment&);
	};
}
