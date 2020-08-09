// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Entry.cpp
// 07.08.2020 02:30
// =============================================================

#include "Kernel/Kernel.hpp"

using namespace kestd::kernel;

auto main() -> int
{
	const Kernel kernel = Kernel("TestGame", "KerboGames");
	kernel.Startup();
	kernel.Execute();
	return 0;
}
