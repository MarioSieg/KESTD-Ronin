// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Script.cpp
// 31.08.2020 23:01
// =============================================================

#include "Script.hpp"
#include <fstream>
#include <filesystem>

namespace kestd
{
	Script::Script(std::string&& file) : filePath(std::move(file))
	{
		std::ifstream t(filePath);
		if (t)
		{
			content = std::string(std::istreambuf_iterator<char>(t), std::istreambuf_iterator<char>());
			const std::filesystem::path path(filePath);
			fileName = path.filename().string();
		}
	}

	Script::Script(std::string&& content, std::string&& file) : content(std::move(content)), filePath(std::move(file))
	{
		const std::filesystem::path path(filePath);
		fileName = path.filename().string();
	}

	auto Script::getContent() const noexcept -> const std::string&
	{
		return content;
	}

	auto Script::getFilePath() const noexcept -> const std::string&
	{
		return filePath;
	}

	auto Script::getFileName() const noexcept -> const std::string&
	{
		return fileName;
	}

	auto Script::saveToDisk() -> bool
	{
		return true;
	}
}
