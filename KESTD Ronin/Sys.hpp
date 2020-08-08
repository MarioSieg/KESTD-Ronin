// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD Ronin
// Mario
// Sys.hpp
// 07.08.2020 14:04

#pragma once

#include "Logger.hpp"
#include "Screen.hpp"
#include "OsInfo.hpp"

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
		Logger Logger;

		/// <summary>
		/// Contains platform info.
		/// </summary>
		PlatformInfo Platform;

		/// <summary>
		/// Contains screen info;
		/// </summary>
		Screen Screen;
	};
}
