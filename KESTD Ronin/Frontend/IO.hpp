// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// IO.hpp
// 27.08.2020 12:44
// =============================================================

#pragma once

#include <filesystem>

namespace kestd
{
	class SystemDirs final
	{
	public:
		enum Enum
		{
			SystemDataBase,
			Protocol,
			Config,
			Count,
		};
	};

	class IOConfig final
	{
	public:
		std::filesystem::path systemDirs[SystemDirs::Count]
		{
			"../DB",
			"../Proto",
			"../Config",
		};
		std::vector<std::filesystem::path> additionalRequiredDirectories;
	};
}
