// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Sys.hpp
// 09.08.2020 10:43
// =============================================================

#pragma once

#include "Logger.hpp"
#include "Screen.hpp"
#include "OsInfo.hpp"
#include "Terminal.hpp"

namespace kestd
{
	/// <summary>
	/// Contains all app data of the engine.
	/// </summary>
	class Sys final
	{
	public:
		Sys();
		Sys(const Sys&) = delete;
		Sys(Sys&&) = delete;
		auto operator=(const Sys&) -> Sys& = delete;
		auto operator=(Sys&&) -> Sys& = delete;
		~Sys() = default;

		/// <summary>
		/// The logger of the system.
		/// </summary>
		Logger protocol = {};

		/// <summary>
		/// Contains platform info.
		/// </summary>
		PlatformInfo platform = {};

		/// <summary>
		/// Contains screen info.
		/// </summary>
		Screen screen = {};

		/// <summary>
		/// Represents the engine system terminal.
		/// </summary>
		Terminal terminal = {};
	};
}
