// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Environment.cpp
// 09.08.2020 07:24
// =============================================================

#include "Environment.hpp"

namespace kestd
{
	Environment::Environment() = default;
	Environment::~Environment() = default;

	auto Environment::getProtocol() noexcept -> BufLogger&
	{
		return this->logger;
	}

	auto Environment::getPlatformInfo() const noexcept -> const PlatformInfo&
	{
		return this->platform;
	}

	auto Environment::getScreenInfo() const noexcept -> const ScreenInfo&
	{
		return this->screen;
	}

	auto Environment::getTerminal() noexcept -> TerminalController&
	{
		return this->terminal;
	}

	auto Environment::getBootConfig() noexcept -> BootConfig&
	{
		return this->config;
	}
}
