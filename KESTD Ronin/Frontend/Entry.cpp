// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Entry.cpp
// 30.08.2020 12:40
// =============================================================

#include "../Backend/Kernel/Kernel.hpp"

using namespace kestd::kernel;

auto main() -> int
{
	KernelDescriptor desc;
	const auto kernel = Kernel(std::move(desc));
	kernel.execute();
	return 0;
}
