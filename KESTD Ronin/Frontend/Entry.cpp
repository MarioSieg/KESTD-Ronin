// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Entry.cpp
// 09.08.2020 07:24
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
