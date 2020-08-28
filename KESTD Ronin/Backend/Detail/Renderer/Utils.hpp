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
		std::uint32_t numVertices,
		const bgfx::VertexLayout& layout,
		std::uint16_t numIndices
	) -> bool;

	auto encodeNormalRgba8(float x,
	                       float y = .0f,
	                       float z = .0f,
	                       float w = .0f) -> std::uint32_t;

	void calcTangents(
		void* vertices,
		std::uint16_t numVertices,
		bgfx::VertexLayout layout,
		const std::uint16_t* indices,
		std::uint32_t numIndices
	);
}
