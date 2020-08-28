// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Environment.hpp
// 09.08.2020 10:43
// =============================================================

#pragma once

#include "BufferedProtocolLogger.hpp"
#include "ScreenInfo.hpp"
#include "TerminalController.hpp"
#include "BootConfig.hpp"
#include "PlatformInfo.hpp"

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
		[[nodiscard]] auto getProtocol() noexcept -> BufferedProtocolLogger&;

		/// <summary>
		/// Returns info about the current getBootConfig, machine and system.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] auto getPlatformInfo() const noexcept -> const PlatformInfo&;

		/// <summary>
		/// Returns info about the screen.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] auto getScreenInfo() const noexcept -> const ScreenInfo&;

		/// <summary>
		/// Returns the terminal controller.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] auto getTerminal() noexcept -> TerminalController&;

		/// <summary>
		/// Returns the boot config.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] auto getBootConfig() noexcept -> BootConfig&;

	private:
		BufferedProtocolLogger logger;
		PlatformInfo platform;
		ScreenInfo screen;
		TerminalController terminal;
		BootConfig config;
	};


	inline auto Environment::getProtocol() noexcept -> BufferedProtocolLogger&
	{
		return this->logger;
	}

	inline auto Environment::getPlatformInfo() const noexcept -> const PlatformInfo&
	{
		return this->platform;
	}

	inline auto Environment::getScreenInfo() const noexcept -> const ScreenInfo&
	{
		return this->screen;
	}

	inline auto Environment::getTerminal() noexcept -> TerminalController&
	{
		return this->terminal;
	}

	inline auto Environment::getBootConfig() noexcept -> BootConfig&
	{
		return this->config;
	}
}
