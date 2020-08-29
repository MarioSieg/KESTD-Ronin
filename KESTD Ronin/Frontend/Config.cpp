// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Config.cpp
// 29.08.2020 13:40
// =============================================================

#include "Config.hpp"

namespace kestd
{
	auto Config::getConfigForAutoTec() const noexcept -> const AutoTecConfig&
	{
		return autoTec;
	}

	auto Config::getConfigForAutoTec() noexcept -> AutoTecConfig&
	{
		return autoTec;
	}

	auto Config::getConfigForIo() const noexcept -> const ConfigIo&
	{
		return io;
	}

	auto Config::getConfigForIo() noexcept -> ConfigIo&
	{
		return io;
	}

	auto Config::getConfigForGraphics() const noexcept -> const ConfigGraphics&
	{
		return graphics;
	}

	auto Config::getConfigForGraphics() noexcept -> ConfigGraphics&
	{
		return graphics;
	}
}
