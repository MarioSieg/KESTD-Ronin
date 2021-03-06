// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Environment.cpp
// 31.08.2020 15:10
// =============================================================

#include "Export/KESTD/Environment.hpp"

namespace kestd
{
	Environment::Environment() = default;
	Environment::~Environment() = default;

	auto Environment::getProtocol() noexcept -> Logger&
	{
		return bufLogger;
	}

	auto Environment::getProtocol() const noexcept -> const Logger&
	{
		return bufLogger;
	}

	auto Environment::getPlatformDiagnostics() const noexcept -> const PlatformDiagnostics&
	{
		return platformDiagnostics;
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
