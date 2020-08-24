// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// AutoTecSystem.hpp
// 09.08.2020 10:43
// =============================================================

#pragma once

#include "../../Frontend/Logger.hpp"
#include "../../Frontend/Terminal.hpp"
#include "../../Frontend/Sys.hpp"

namespace kestd::detail
{
	class AutoTec final
	{
	public:
		void update(Sys& sys);
		void menu() const;
	};
}
