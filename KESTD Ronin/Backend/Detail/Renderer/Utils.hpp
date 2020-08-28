// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Utils.hpp
// 09.08.2020 07:24
// =============================================================

#pragma once

#include <cstdint>

namespace bgfx
{
	struct VertexLayout;
}

namespace kestd::detail::renderer
{
	auto checkAvailTransientBuffers(
		const std::uint32_t numVertices,
		const bgfx::VertexLayout& layout,
		const std::uint16_t numIndices
	) -> bool;

	auto encodeNormalRgba8(const float x,
	                       const float y = .0f,
	                       const float z = .0f,
	                       const float w = .0f) -> std::uint32_t;

	void calcTangents(
		void* const vertices,
		std::uint16_t numVertices,
		bgfx::VertexLayout layout,
		const std::uint16_t* const indices,
		std::uint32_t numIndices
	);
}
