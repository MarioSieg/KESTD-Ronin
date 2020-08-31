// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Drivers.hpp
// 31.08.2020 15:09
// =============================================================

#pragma once

#include "../../Frontend/Export/KESTD/Config.hpp"

namespace kestd::detail::renderer
{
	class Drivers final
	{
	public:
		Drivers(const GraphicsConfig& cfg); //TODO: Replace with Resolution
		Drivers(const Drivers&) = delete;
		Drivers(Drivers&&) = delete;
		Drivers& operator=(const Drivers&) = delete;
		Drivers& operator=(Drivers&&) = delete;
		~Drivers();


		void beginFrame();
		void endFrame();
	};
}
