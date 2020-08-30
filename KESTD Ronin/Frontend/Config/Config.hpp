// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Config.hpp
// 26.08.2020 00:14
// =============================================================

#pragma once

#include "AutoTecConfig.hpp"
#include "IoConfig.hpp"
#include "GraphicsConfig.hpp"

namespace kestd
{
	/// <summary>
	/// Contains the full engine boot configuration.
	/// </summary>
	class Config final
	{
		friend class AutoTec;
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <returns>The boot config for the AutoTec editor.</returns>
		[[nodiscard]]
		auto getConfigForAutoTec() const noexcept -> const AutoTecConfig&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The boot config for the AutoTec editor.</returns>
		[[nodiscard]]
		auto getConfigForAutoTec() noexcept -> AutoTecConfig&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The boot config for disk input output.</returns>
		[[nodiscard]]
		auto getConfigForIo() const noexcept -> const IoConfig&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The boot config for disk input output.</returns>
		[[nodiscard]]
		auto getConfigForIo() noexcept -> IoConfig&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The boot config for graphics and display.</returns>
		[[nodiscard]]
		auto getConfigForGraphics() const noexcept -> const GraphicsConfig&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The boot config for graphics and display.</returns>
		[[nodiscard]]
		auto getConfigForGraphics() noexcept -> GraphicsConfig&;

	private:
		AutoTecConfig autoTec = {};
		IoConfig io = {};
		GraphicsConfig graphics = {};
	};
}
