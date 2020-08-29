// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Drivers.hpp
// 10.08.2020 13:41
// =============================================================

#pragma once

#include "../../Frontend/ConfigGraphics.hpp"

namespace kestd::detail::renderer
{
	class Drivers final
	{
	public:
		Drivers(const ConfigGraphics& cfg); //TODO: Replace with Resolution
		Drivers(const Drivers&) = delete;
		Drivers(Drivers&&) = delete;
		Drivers& operator=(const Drivers&) = delete;
		Drivers& operator=(Drivers&&) = delete;
		~Drivers();


		void beginFrame();
		void endFrame();
	};
}
