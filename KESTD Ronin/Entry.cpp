// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Entry.cpp
// 09.08.2020 07:24
// =============================================================

#include "Kernel/Kernel.hpp"

using namespace kestd::kernel;

auto main() -> int
{
	const Kernel kernel = Kernel("TestGame", "KerboGames");
	kernel.execute();
	return 0;
}
