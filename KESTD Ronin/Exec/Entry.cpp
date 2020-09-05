// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Entry.cpp
// 31.08.2020 15:10
// =============================================================

#include "../Kernel/Export/KESTD/Kernel.hpp"
#include "../Backend/LegacySubsystemBuilder.hpp"

using namespace kestd::kernel;

auto main() -> int
{
	KernelDescriptor desc;
	auto kernel = Kernel(std::move(desc));
	PushLegacySubsystens(kernel);
	kernel.execute();
	return 0;
}
