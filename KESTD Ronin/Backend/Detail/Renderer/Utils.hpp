// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Utils.hpp
// 31.08.2020 15:09
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
