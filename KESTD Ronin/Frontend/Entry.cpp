// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Entry.cpp
// 31.08.2020 15:10
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
