// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Utils.cpp
// 31.08.2020 15:09
// =============================================================

#include "Utils.hpp"
#include <cstddef>
#include <cassert>
#include <bgfx/bgfx.h>
#include <bx/pixelformat.h>

namespace kestd::detail::renderer
{
	auto checkAvailTransientBuffers(
		const uint32_t numVertices,
		const bgfx::VertexLayout& layout,
		const uint16_t numIndices) -> bool
	{
		return numVertices == getAvailTransientVertexBuffer(numVertices, layout)
			&& (0 == numIndices || numIndices == bgfx::getAvailTransientIndexBuffer(numIndices));
	}

	auto encodeNormalRgba8(const float x, const float y, const float z, const float w) -> std::uint32_t
	{
		const float src[] =
		{
			x * 0.5f + 0.5f,
			y * 0.5f + 0.5f,
			z * 0.5f + 0.5f,
			w * 0.5f + 0.5f,
		};
		std::uint32_t dst;
		bx::packRgba8(&dst, src);
		return dst;
	}

	void calcTangents(
		void* const vertices,
		const std::uint16_t numVertices,
		const bgfx::VertexLayout layout,
		const std::uint16_t* const indices,
		const std::uint32_t numIndices
	)
	{
		assert(vertices);
		assert(indices);

		struct PosTexcoord final
		{
			float x;
			float y;
			float z;
			float pad0;
			float u;
			float v;
			float pad1;
			float pad2;
		};

		auto* tangents = new float[6 * static_cast<std::size_t>(numVertices)];
		bx::memSet(tangents, 0, 6 * static_cast<std::size_t>(numVertices) * sizeof(float));

		PosTexcoord v0 = {};
		PosTexcoord v1 = {};
		PosTexcoord v2 = {};

		for (uint32_t ii = 0, num = numIndices / 3; ii < num; ++ii)
		{
			const auto* const indices1 = &indices[ii * 3];
			const uint32_t i0 = indices1[0];
			const uint32_t i1 = indices1[1];
			const uint32_t i2 = indices1[2];

			vertexUnpack(&v0.x, bgfx::Attrib::Position, layout, vertices, i0);
			vertexUnpack(&v0.u, bgfx::Attrib::TexCoord0, layout, vertices, i0);

			vertexUnpack(&v1.x, bgfx::Attrib::Position, layout, vertices, i1);
			vertexUnpack(&v1.u, bgfx::Attrib::TexCoord0, layout, vertices, i1);

			vertexUnpack(&v2.x, bgfx::Attrib::Position, layout, vertices, i2);
			vertexUnpack(&v2.u, bgfx::Attrib::TexCoord0, layout, vertices, i2);

			const auto bax = v1.x - v0.x;
			const auto bay = v1.y - v0.y;
			const auto baz = v1.z - v0.z;
			const auto bau = v1.u - v0.u;
			const auto bav = v1.v - v0.v;

			const auto cax = v2.x - v0.x;
			const auto cay = v2.y - v0.y;
			const auto caz = v2.z - v0.z;
			const auto cau = v2.u - v0.u;
			const auto cav = v2.v - v0.v;

			const auto det = bau * cav - bav * cau;
			const auto invDet = 1.0f / det;

			const auto tx = (bax * cav - cax * bav) * invDet;
			const auto ty = (bay * cav - cay * bav) * invDet;
			const auto tz = (baz * cav - caz * bav) * invDet;

			const auto bx = (cax * bau - bax * cau) * invDet;
			const auto by = (cay * bau - bay * cau) * invDet;
			const auto bz = (caz * bau - baz * cau) * invDet;

			for (std::uint32_t jj = 0; jj < 3; ++jj)
			{
				auto* const tanu = &tangents[indices1[jj] * 6];
				auto* const tanv = &tanu[3];
				tanu[0] += tx;
				tanu[1] += ty;
				tanu[2] += tz;

				tanv[0] += bx;
				tanv[1] += by;
				tanv[2] += bz;
			}
		}

		for (std::uint32_t ii = 0; ii < numVertices; ++ii)
		{
			const auto tanu = bx::load<bx::Vec3>(&tangents[ii * 6]);
			const auto tanv = bx::load<bx::Vec3>(&tangents[ii * 6 + 3]);

			float nxyzw[4];
			vertexUnpack(nxyzw, bgfx::Attrib::Normal, layout, vertices, ii);

			const auto normal = bx::load<bx::Vec3>(nxyzw);
			const auto ndt = dot(normal, tanu);
			const auto nxt = cross(normal, tanu);
			const auto tmp = sub(tanu, mul(normal, ndt));

			float tangent[4];
			store(tangent, normalize(tmp));
			tangent[3] = dot(nxt, tanv) < 0.0f ? -1.0f : 1.0f;

			vertexPack(tangent, true, bgfx::Attrib::Tangent, layout, vertices, ii);
		}

		delete[] tangents;
	}
}
