// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Utils.hpp
// 08.08.2020 20:46
// =============================================================

#pragma once

#include <bgfx/bgfx.h>
#include <cstdint>

inline auto checkAvailTransientBuffers(const uint32_t numVertices,
                                       const bgfx::VertexLayout& layout,
                                       const uint32_t numIndices)
-> bool
{
	return numVertices == getAvailTransientVertexBuffer(numVertices, layout)
		&& (0 == numIndices || numIndices == bgfx::getAvailTransientIndexBuffer(numIndices));
}
