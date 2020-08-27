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
	struct SystemDirs final
	{
		enum Enum
		{
			AppDataBase,
			SystemDataBase,
			Protocol,
			Config,
			Count,
		};
	};

	struct IOConfig final
	{
		std::filesystem::path systemDirs[SystemDirs::Count];
		std::vector<std::filesystem::path> additionalRequiredDirectories;
	};
}
