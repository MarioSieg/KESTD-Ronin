#pragma once

#include <string>

namespace kestd
{
	/// <summary>
	/// Represents a script which can be opened in the script editor.
	/// </summary>
	class Script final
	{
	public:
		Script() = default;
		explicit Script(std::string&& file);
		Script(std::string&& content, std::string&& file);
		Script(const Script&) = default;
		Script(Script&&) noexcept = default;
		Script& operator=(const Script&) = default;
		Script& operator=(Script&&) = default;
		~Script() = default;

		[[nodiscard]]
		auto getContent() const noexcept -> const std::string&;

		[[nodiscard]]
		auto getFilePath() const noexcept -> const std::string&;

		[[nodiscard]]
		auto getFileName() const noexcept -> const std::string&;

		[[nodiscard]]
		auto saveToDisk() -> bool;

	private:
		std::string content = {};
		std::string filePath = {};
		std::string fileName = {};
	};
}
