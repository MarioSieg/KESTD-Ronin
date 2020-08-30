// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// ConfigIO.cpp
// 28.08.2020 22:33
// =============================================================

#include "IoConfig.hpp"

namespace kestd
{
	auto IoConfig::getRequiredDirectories() noexcept -> std::vector<std::tuple<
		std::filesystem::path, DirectoryMissingAction>>&
	{
		return requiredDirectories;
	}

	auto IoConfig::getRequiredDirectories() const noexcept -> const std::vector<std::tuple<
		std::filesystem::path, DirectoryMissingAction>>&
	{
		return requiredDirectories;
	}

	void IoConfig::setRequiredDirectories(
		std::vector<std::tuple<std::filesystem::path, DirectoryMissingAction>>&& val) noexcept
	{
		requiredDirectories = std::move(val);
	}

	auto IoConfig::getWorkingDir() const noexcept -> const std::filesystem::path&
	{
		return workingDir;
	}

	void IoConfig::setWorkingDir(std::filesystem::path&& val) noexcept
	{
		workingDir = std::move(val);
	}
}
