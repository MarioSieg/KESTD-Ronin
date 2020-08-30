// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// KernelStats.hpp
// 30.08.2020 12:40
// =============================================================

#pragma once

#include <vector>

namespace kestd
{
	/// <summary>
	/// Contains stats about a kernel subsystem.
	/// </summary>
	class SubsystemStats final
	{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <returns>The Ctor() call time in ms.</returns>
		[[nodiscard]]
		auto getInitializeTime() const noexcept -> float;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The onPrepare() call time in ms. </returns>
		[[nodiscard]]
		auto getPrepareTime() const noexcept -> float;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The onTick() call time in ms.</returns>
		[[nodiscard]]
		auto getTickTime() const noexcept -> float;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The shutdown() call time in ms.</returns>
		[[nodiscard]]
		auto getShutdownTime() const noexcept -> float;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The Dtor() call time in ms.</returns>
		[[nodiscard]]
		auto getDeinitializeTime() const noexcept -> float;

	private:
		float initializeTime = .0;
		float prepareTime = .0;
		float tickTime = .0;
		float shutdownTime = .0;
		float deinitializeTime = .0;
	};

	class StatsKernel final
	{
	public:

	private:
		std::vector<SubsystemStats> subsystemStats = {};
		float initializeTime = .0f;
		float prepareTime = .0f;
		float fullBootTime = .0f;
		float tickTime = .0f;
		float shutdownTime = .0f;
		float deinitializeTime = .0f;
		std::uint32_t cycles = 0;
	};
}
