// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Environment.hpp
// 31.08.2020 15:10
// =============================================================

#pragma once

#include "Logger.hpp"
#include "TerminalController.hpp"
#include "Config.hpp"
#include "Platform.hpp"

namespace kestd
{
	/// <summary>
	/// Contains all app data of the engine.
	/// </summary>
	class Environment final
	{
	public:
		Environment();
		Environment(const Environment&) = delete;
		Environment(Environment&&) = delete;
		auto operator=(const Environment&) -> Environment& = delete;
		auto operator=(Environment&&) -> Environment& = delete;
		~Environment();

		/// <summary>
		/// Returns the current log protocol.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getProtocol() noexcept -> Logger&;

		/// <summary>
		/// Returns the current log protocol.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getProtocol() const noexcept -> const Logger&;

		/// <summary>
		/// Returns info about the current getBootConfig, machine and system.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getPlatformDiagnostics() const noexcept -> const PlatformDiagnostics&;

		/// <summary>
		/// Returns the terminal controller.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getTerminal() noexcept -> TerminalController&;

		/// <summary>
		/// Returns the terminal controller.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getTerminal() const noexcept -> const TerminalController&;

		/// <summary>
		/// Returns the boot config.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getBootConfig() noexcept -> Config&;

		/// <summary>
		/// Returns the boot config.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getBootConfig() const noexcept -> const Config&;

	private:
		Logger bufLogger;
		PlatformDiagnostics platformDiagnostics;
		TerminalController terminalController;
		Config bootConfig;
	};
}
