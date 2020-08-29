// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
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
		return bufLogger;
	}

	auto Environment::getProtocol() const noexcept -> const BufLogger&
	{
		return bufLogger;
	}

	auto Environment::getPlatformInfo() const noexcept -> const PlatformInfo&
	{
		return platformInfo;
	}

	auto Environment::getTerminal() noexcept -> TerminalController&
	{
		return terminalController;
	}

	auto Environment::getTerminal() const noexcept -> const TerminalController&
	{
		return terminalController;
	}

	auto Environment::getBootConfig() noexcept -> Config&
	{
		return bootConfig;
	}

	auto Environment::getBootConfig() const noexcept -> const Config&
	{
		return bootConfig;
	}
}
