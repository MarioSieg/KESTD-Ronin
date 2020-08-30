// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// ConfigIO.hpp
// 27.08.2020 12:44
// =============================================================

#pragma once

#include <filesystem>
#include <tuple>

namespace kestd
{
	enum class SystemDirs
	{
		SystemDataBase,
		Protocol,
		Config,
		Count,
	};

	enum class DirectoryMissingAction
	{
		Create,
		Throw
	};

	class IoConfig final
	{
	public:
		static constexpr std::string_view DataBaseDir = "DB";
		static constexpr std::string_view ConfigurationDir = "Config";
		static constexpr std::string_view ProtocolDir = "Proto";

		/// <summary>
		/// Returns all required directories. These directories must exist in the working directory!
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getRequiredDirectories() noexcept -> std::vector<std::tuple<std::filesystem::path, DirectoryMissingAction>
		>&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>All required directories. These directories must exist in the working directory!</returns>
		[[nodiscard]]
		auto getRequiredDirectories() const noexcept -> const std::vector<std::tuple<
			std::filesystem::path, DirectoryMissingAction>>&;

		/// <summary>
		/// Sets all required directories. These directories must exist in the working directory!
		/// </summary>
		/// <returns></returns>
		void setRequiredDirectories(
			std::vector<std::tuple<std::filesystem::path, DirectoryMissingAction>>&& val) noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Working directory which will be entered on boot.</returns>
		[[nodiscard]]
		auto getWorkingDir() const noexcept -> const std::filesystem::path&;

		/// <summary>
		/// Sets working directory which will be entered on boot.
		/// </summary>
		/// <returns></returns>
		void setWorkingDir(std::filesystem::path&& val) noexcept;

	private:
		std::filesystem::path workingDir = "../";
		std::vector<std::tuple<std::filesystem::path, DirectoryMissingAction>> requiredDirectories
		{
			{DataBaseDir, DirectoryMissingAction::Throw},
			{ConfigurationDir, DirectoryMissingAction::Create},
			{ProtocolDir, DirectoryMissingAction::Create},
		};
	};
}
