// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Drivers.hpp
// 10.08.2020 13:41
// =============================================================

#pragma once

namespace kestd::detail
{
	class Drivers final
	{
	public:
		Drivers();
		Drivers(const Drivers&) = delete;
		Drivers(Drivers&&) = delete;
		Drivers& operator=(const Drivers&) = delete;
		Drivers& operator=(Drivers&&) = delete;
		~Drivers();


		void beginFrame();
		void endFrame();
	};
}
