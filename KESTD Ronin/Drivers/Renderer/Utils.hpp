#include <bgfx/bgfx.h>
#include <cstdint>

inline auto CheckAvailTransientBuffers(const uint32_t numVertices,
                                       const bgfx::VertexLayout& layout,
                                       const uint32_t numIndices)
	-> bool
{
	return numVertices == getAvailTransientVertexBuffer(numVertices, layout)
		&& (0 == numIndices || numIndices == bgfx::getAvailTransientIndexBuffer(numIndices));
}
