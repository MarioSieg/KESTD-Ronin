// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// ConfigIO.cpp
// 28.08.2020 22:33
// =============================================================

#include "ConfigIO.hpp"

namespace kestd
{
	auto ConfigIo::getRequiredDirectories() noexcept -> std::vector<std::tuple<
		std::filesystem::path, DirectoryMissingAction>>&
	{
		return requiredDirectories;
	}

	auto ConfigIo::getRequiredDirectories() const noexcept -> const std::vector<std::tuple<
		std::filesystem::path, DirectoryMissingAction>>&
	{
		return requiredDirectories;
	}

	void ConfigIo::setRequiredDirectories(
		std::vector<std::tuple<std::filesystem::path, DirectoryMissingAction>>&& val) noexcept
	{
		requiredDirectories = std::move(val);
	}

	auto ConfigIo::getWorkingDir() const noexcept -> const std::filesystem::path&
	{
		return workingDir;
	}

	void ConfigIo::setWorkingDir(std::filesystem::path&& val) noexcept
	{
		workingDir = std::move(val);
	}
}
