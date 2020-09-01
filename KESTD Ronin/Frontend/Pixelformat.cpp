// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Pixelformat.cpp
// 01.09.2020 05:53
// =============================================================

#include "Export/KESTD/Pixelformat.hpp"
#include <algorithm>
#include <cmath>

namespace kestd
{
	std::uint32_t toUnorm(float argvalue, float argscale) noexcept
	{
		return std::uint32_t(std::round(std::clamp(argvalue, 0.0f, 1.0f) * argscale));
	}

	float fromUnorm(std::uint32_t argvalue, float argscale) noexcept
	{
		return static_cast<float>(argvalue) / argscale;
	}

	std::int32_t toSnorm(float argvalue, float argscale) noexcept
	{
		return std::int32_t(std::round(
				std::clamp(argvalue, -1.0f, 1.0f) * argscale)
		);
	}

	float fromSnorm(std::int32_t argvalue, float argscale) noexcept
	{
		return std::max(-1.0f, static_cast<float>(argvalue) / argscale);
	}

	// A8
	void packA8(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint8_t* dst = static_cast<std::uint8_t *>(argdst);
		dst[0] = std::uint8_t(toUnorm(argsrc[3], 255.0f));
	}

	void unpackA8(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint8_t* src = static_cast<const std::uint8_t *>(argsrc);
		const float aa = fromUnorm(src[0], 255.0f);
		argdst[0] = aa;
		argdst[1] = aa;
		argdst[2] = aa;
		argdst[3] = aa;
	}

	// R8
	void packR8(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint8_t* dst = static_cast<std::uint8_t *>(argdst);
		dst[0] = std::uint8_t(toUnorm(argsrc[0], 255.0f));
	}

	void unpackR8(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint8_t* src = static_cast<const std::uint8_t *>(argsrc);
		argdst[0] = fromUnorm(src[0], 255.0f);
		argdst[1] = 0.0f;
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

	// R8S
	void packR8S(void* const argdst, const float* const argsrc) noexcept
	{
		std::int8_t* dst = static_cast<std::int8_t *>(argdst);
		dst[0] = std::int8_t(toSnorm(argsrc[0], 127.0f));
	}

	void unpackR8S(float* const argdst, const void* const argsrc) noexcept
	{
		const std::int8_t* src = static_cast<const std::int8_t *>(argsrc);
		argdst[0] = fromSnorm(src[0], 127.0f);
		argdst[1] = 0.0f;
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

	// R8I
	void packR8I(void* const argdst, const float* const argsrc) noexcept
	{
		std::int8_t* dst = static_cast<std::int8_t *>(argdst);
		dst[0] = std::int8_t(argsrc[0]);
	}

	void unpackR8I(float* const argdst, const void* const argsrc) noexcept
	{
		const std::int8_t* src = static_cast<const std::int8_t *>(argsrc);
		argdst[0] = static_cast<float>(src[0]);
		argdst[1] = 0.0f;
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

	// R8U
	void packR8U(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint8_t* dst = static_cast<std::uint8_t *>(argdst);
		dst[0] = std::uint8_t(argsrc[0]);
	}

	void unpackR8U(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint8_t* src = static_cast<const std::uint8_t *>(argsrc);
		argdst[0] = static_cast<float>(src[0]);
		argdst[1] = 0.0f;
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

	// RG8
	void packRg8(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint8_t* dst = static_cast<std::uint8_t *>(argdst);
		dst[0] = std::uint8_t(toUnorm(argsrc[0], 255.0f));
		dst[1] = std::uint8_t(toUnorm(argsrc[1], 255.0f));
	}

	void unpackRg8(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint8_t* src = static_cast<const std::uint8_t *>(argsrc);
		argdst[0] = fromUnorm(src[0], 255.0f);
		argdst[1] = fromUnorm(src[1], 255.0f);
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

	// RG8S
	void packRg8S(void* const argdst, const float* const argsrc) noexcept
	{
		std::int8_t* dst = static_cast<std::int8_t *>(argdst);
		dst[0] = std::int8_t(toSnorm(argsrc[0], 127.0f));
		dst[1] = std::int8_t(toSnorm(argsrc[1], 127.0f));
	}

	void unpackRg8S(float* const argdst, const void* const argsrc) noexcept
	{
		const std::int8_t* src = static_cast<const std::int8_t *>(argsrc);
		argdst[0] = fromSnorm(src[0], 127.0f);
		argdst[1] = fromSnorm(src[1], 127.0f);
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

	// RG8I
	void packRg8I(void* const argdst, const float* const argsrc) noexcept
	{
		std::int8_t* dst = static_cast<std::int8_t *>(argdst);
		dst[0] = std::int8_t(argsrc[0]);
		dst[1] = std::int8_t(argsrc[1]);
	}

	void unpackRg8I(float* const argdst, const void* const argsrc) noexcept
	{
		const std::int8_t* src = static_cast<const std::int8_t *>(argsrc);
		argdst[0] = static_cast<float>(src[0]);
		argdst[1] = static_cast<float>(src[1]);
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

	// RG8U
	void packRg8U(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint8_t* dst = static_cast<std::uint8_t *>(argdst);
		dst[0] = std::uint8_t(argsrc[0]);
		dst[1] = std::uint8_t(argsrc[1]);
	}

	void unpackRg8U(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint8_t* src = static_cast<const std::uint8_t *>(argsrc);
		argdst[0] = static_cast<float>(src[0]);
		argdst[1] = static_cast<float>(src[1]);
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

	// RGB8
	void packRgb8(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint8_t* dst = static_cast<std::uint8_t *>(argdst);
		dst[0] = std::uint8_t(toUnorm(argsrc[0], 255.0f));
		dst[1] = std::uint8_t(toUnorm(argsrc[1], 255.0f));
		dst[2] = std::uint8_t(toUnorm(argsrc[2], 255.0f));
	}

	void unpackRgb8(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint8_t* src = static_cast<const std::uint8_t *>(argsrc);
		argdst[0] = fromUnorm(src[0], 255.0f);
		argdst[1] = fromUnorm(src[1], 255.0f);
		argdst[2] = fromUnorm(src[2], 255.0f);
		argdst[3] = 1.0f;
	}

	// RGB8S
	void packRgb8S(void* const argdst, const float* const argsrc) noexcept
	{
		std::int8_t* dst = static_cast<std::int8_t *>(argdst);
		dst[0] = std::int8_t(toSnorm(argsrc[0], 127.0f));
		dst[1] = std::int8_t(toSnorm(argsrc[1], 127.0f));
		dst[2] = std::int8_t(toSnorm(argsrc[2], 127.0f));
	}

	void unpackRgb8S(float* const argdst, const void* const argsrc) noexcept
	{
		const std::int8_t* src = static_cast<const std::int8_t *>(argsrc);
		argdst[0] = fromSnorm(src[0], 127.0f);
		argdst[1] = fromSnorm(src[1], 127.0f);
		argdst[2] = fromSnorm(src[2], 127.0f);
		argdst[3] = 1.0f;
	}

	// RGB8I
	void packRgb8I(void* const argdst, const float* const argsrc) noexcept
	{
		std::int8_t* dst = static_cast<std::int8_t *>(argdst);
		dst[0] = std::int8_t(argsrc[0]);
		dst[1] = std::int8_t(argsrc[1]);
		dst[2] = std::int8_t(argsrc[2]);
	}

	void unpackRgb8I(float* const argdst, const void* const argsrc) noexcept
	{
		const std::int8_t* src = static_cast<const std::int8_t *>(argsrc);
		argdst[0] = static_cast<float>(src[0]);
		argdst[1] = static_cast<float>(src[1]);
		argdst[2] = static_cast<float>(src[2]);
		argdst[3] = 1.0f;
	}

	// RGB8U
	void packRgb8U(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint8_t* dst = static_cast<std::uint8_t *>(argdst);
		dst[0] = std::uint8_t(argsrc[0]);
		dst[1] = std::uint8_t(argsrc[1]);
		dst[2] = std::uint8_t(argsrc[2]);
	}

	void unpackRgb8U(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint8_t* src = static_cast<const std::uint8_t *>(argsrc);
		argdst[0] = static_cast<float>(src[0]);
		argdst[1] = static_cast<float>(src[1]);
		argdst[2] = static_cast<float>(src[2]);
		argdst[3] = 1.0f;
	}

	// BGRA8
	void packBgra8(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint8_t* dst = static_cast<std::uint8_t *>(argdst);
		dst[2] = std::uint8_t(toUnorm(argsrc[0], 255.0f));
		dst[1] = std::uint8_t(toUnorm(argsrc[1], 255.0f));
		dst[0] = std::uint8_t(toUnorm(argsrc[2], 255.0f));
		dst[3] = std::uint8_t(toUnorm(argsrc[3], 255.0f));
	}

	void unpackBgra8(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint8_t* src = static_cast<const std::uint8_t *>(argsrc);
		argdst[0] = fromUnorm(src[2], 255.0f);
		argdst[1] = fromUnorm(src[1], 255.0f);
		argdst[2] = fromUnorm(src[0], 255.0f);
		argdst[3] = fromUnorm(src[3], 255.0f);
	}

	// RGBA8
	void packRgba8(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint8_t* dst = static_cast<std::uint8_t *>(argdst);
		dst[0] = std::uint8_t(toUnorm(argsrc[0], 255.0f));
		dst[1] = std::uint8_t(toUnorm(argsrc[1], 255.0f));
		dst[2] = std::uint8_t(toUnorm(argsrc[2], 255.0f));
		dst[3] = std::uint8_t(toUnorm(argsrc[3], 255.0f));
	}

	void unpackRgba8(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint8_t* src = static_cast<const std::uint8_t *>(argsrc);
		argdst[0] = fromUnorm(src[0], 255.0f);
		argdst[1] = fromUnorm(src[1], 255.0f);
		argdst[2] = fromUnorm(src[2], 255.0f);
		argdst[3] = fromUnorm(src[3], 255.0f);
	}

	// RGBA8S
	void packRgba8S(void* const argdst, const float* const argsrc) noexcept
	{
		std::int8_t* dst = static_cast<std::int8_t *>(argdst);
		dst[0] = std::int8_t(toSnorm(argsrc[0], 127.0f));
		dst[1] = std::int8_t(toSnorm(argsrc[1], 127.0f));
		dst[2] = std::int8_t(toSnorm(argsrc[2], 127.0f));
		dst[3] = std::int8_t(toSnorm(argsrc[3], 127.0f));
	}

	void unpackRgba8S(float* const argdst, const void* const argsrc) noexcept
	{
		const std::int8_t* src = static_cast<const std::int8_t *>(argsrc);
		argdst[0] = fromSnorm(src[0], 127.0f);
		argdst[1] = fromSnorm(src[1], 127.0f);
		argdst[2] = fromSnorm(src[2], 127.0f);
		argdst[3] = fromSnorm(src[3], 127.0f);
	}

	// RGBA8I
	void packRgba8I(void* const argdst, const float* const argsrc) noexcept
	{
		std::int8_t* dst = static_cast<std::int8_t *>(argdst);
		dst[0] = std::int8_t(argsrc[0]);
		dst[1] = std::int8_t(argsrc[1]);
		dst[2] = std::int8_t(argsrc[2]);
		dst[3] = std::int8_t(argsrc[3]);
	}

	void unpackRgba8I(float* const argdst, const void* const argsrc) noexcept
	{
		const std::int8_t* src = static_cast<const std::int8_t *>(argsrc);
		argdst[0] = static_cast<float>(src[0]);
		argdst[1] = static_cast<float>(src[1]);
		argdst[2] = static_cast<float>(src[2]);
		argdst[3] = static_cast<float>(src[3]);
	}

	// RGBA8U
	void packRgba8U(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint8_t* dst = static_cast<std::uint8_t *>(argdst);
		dst[0] = std::uint8_t(argsrc[0]);
		dst[1] = std::uint8_t(argsrc[1]);
		dst[2] = std::uint8_t(argsrc[2]);
		dst[3] = std::uint8_t(argsrc[3]);
	}

	void unpackRgba8U(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint8_t* src = static_cast<const std::uint8_t *>(argsrc);
		argdst[0] = static_cast<float>(src[0]);
		argdst[1] = static_cast<float>(src[1]);
		argdst[2] = static_cast<float>(src[2]);
		argdst[3] = static_cast<float>(src[3]);
	}

	// R16
	void packR16(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint16_t* dst = static_cast<std::uint16_t *>(argdst);
		dst[0] = std::uint16_t(toUnorm(argsrc[0], 65535.0f));
	}

	void unpackR16(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint16_t* src = static_cast<const std::uint16_t *>(argsrc);
		argdst[0] = fromUnorm(src[0], 65535.0f);
		argdst[1] = 0.0f;
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

	// R16S
	void packR16S(void* const argdst, const float* const argsrc) noexcept
	{
		std::int16_t* dst = static_cast<std::int16_t *>(argdst);
		dst[0] = std::int16_t(toSnorm(argsrc[0], 32767.0f));
	}

	void unpackR16S(float* const argdst, const void* const argsrc) noexcept
	{
		const std::int16_t* src = static_cast<const std::int16_t *>(argsrc);
		argdst[0] = fromSnorm(src[0], 32767.0f);
		argdst[1] = 0.0f;
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

	// R16I
	void packR16I(void* const argdst, const float* const argsrc) noexcept
	{
		std::int16_t* dst = static_cast<std::int16_t *>(argdst);
		dst[0] = std::int16_t(argsrc[0]);
	}

	void unpackR16I(float* const argdst, const void* const argsrc) noexcept
	{
		const std::int16_t* src = static_cast<const std::int16_t *>(argsrc);
		argdst[0] = static_cast<float>(src[0]);
		argdst[1] = 0.0f;
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

	// R16U
	void packR16U(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint16_t* dst = static_cast<std::uint16_t *>(argdst);
		dst[0] = std::uint16_t(argsrc[0]);
	}

	void unpackR16U(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint16_t* src = static_cast<const std::uint16_t *>(argsrc);
		argdst[0] = static_cast<float>(src[0]);
	}

#if false
	// R16F
	 void packR16F(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint16_t* dst = (std::uint16_t*)argdst;
		dst[0] = halfFromFloat(argsrc[0]);
	}

	 void unpackR16F(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint16_t* src = (const std::uint16_t*)argsrc;
		argdst[0] = halfToFloat(src[0]);
		argdst[1] = 0.0f;
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}
#endif

	// RG16
	void packRg16(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint16_t* dst = static_cast<std::uint16_t *>(argdst);
		dst[0] = std::uint16_t(toUnorm(argsrc[0], 65535.0f));
		dst[1] = std::uint16_t(toUnorm(argsrc[1], 65535.0f));
	}

	void unpackRg16(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint16_t* src = static_cast<const std::uint16_t *>(argsrc);
		argdst[0] = fromUnorm(src[0], 65535.0f);
		argdst[1] = fromUnorm(src[1], 65535.0f);
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

	// RG16S
	void packRg16S(void* const argdst, const float* const argsrc) noexcept
	{
		std::int16_t* dst = static_cast<std::int16_t *>(argdst);
		dst[0] = std::int16_t(toSnorm(argsrc[0], 32767.0f));
		dst[1] = std::int16_t(toSnorm(argsrc[1], 32767.0f));
	}

	void unpackRg16S(float* const argdst, const void* const argsrc) noexcept
	{
		const std::int16_t* src = static_cast<const std::int16_t *>(argsrc);
		argdst[0] = fromSnorm(src[0], 32767.0f);
		argdst[1] = fromSnorm(src[1], 32767.0f);
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

	// RG16I
	void packRg16I(void* const argdst, const float* const argsrc) noexcept
	{
		std::int16_t* dst = static_cast<std::int16_t *>(argdst);
		dst[0] = std::int16_t(argsrc[0]);
		dst[1] = std::int16_t(argsrc[1]);
	}

	void unpackRg16I(float* const argdst, const void* const argsrc) noexcept
	{
		const std::int16_t* src = static_cast<const std::int16_t *>(argsrc);
		argdst[0] = static_cast<float>(src[0]);
		argdst[1] = static_cast<float>(src[1]);
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

	// RG16U
	void packRg16U(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint16_t* dst = static_cast<std::uint16_t *>(argdst);
		dst[0] = std::uint16_t(argsrc[0]);
		dst[1] = std::uint16_t(argsrc[1]);
	}

	void unpackRg16U(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint16_t* src = static_cast<const std::uint16_t *>(argsrc);
		argdst[0] = static_cast<float>(src[0]);
		argdst[1] = static_cast<float>(src[1]);
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

#if false
	// RG16F
	 void packRg16F(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint16_t* dst = (std::uint16_t*)argdst;
		dst[0] = halfFromFloat(argsrc[0]);
		dst[1] = halfFromFloat(argsrc[1]);
	}

	 void unpackRg16F(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint16_t* src = (const std::uint16_t*)argsrc;
		argdst[0] = halfToFloat(src[0]);
		argdst[1] = halfToFloat(src[1]);
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}
#endif

	// RGBA16
	void packRgba16(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint16_t* dst = static_cast<std::uint16_t *>(argdst);
		dst[0] = std::uint16_t(toUnorm(argsrc[0], 65535.0f));
		dst[1] = std::uint16_t(toUnorm(argsrc[1], 65535.0f));
		dst[2] = std::uint16_t(toUnorm(argsrc[2], 65535.0f));
		dst[3] = std::uint16_t(toUnorm(argsrc[3], 65535.0f));
	}

	void unpackRgba16(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint16_t* src = static_cast<const std::uint16_t *>(argsrc);
		argdst[0] = fromUnorm(src[0], 65535.0f);
		argdst[1] = fromUnorm(src[1], 65535.0f);
		argdst[2] = fromUnorm(src[2], 65535.0f);
		argdst[3] = fromUnorm(src[3], 65535.0f);
	}

	// RGBA16S
	void packRgba16S(void* const argdst, const float* const argsrc) noexcept
	{
		std::int16_t* dst = static_cast<std::int16_t *>(argdst);
		dst[0] = std::int16_t(toSnorm(argsrc[0], 32767.0f));
		dst[1] = std::int16_t(toSnorm(argsrc[1], 32767.0f));
		dst[2] = std::int16_t(toSnorm(argsrc[2], 32767.0f));
		dst[3] = std::int16_t(toSnorm(argsrc[3], 32767.0f));
	}

	void unpackRgba16S(float* const argdst, const void* const argsrc) noexcept
	{
		const std::int16_t* src = static_cast<const std::int16_t *>(argsrc);
		argdst[0] = fromSnorm(src[0], 32767.0f);
		argdst[1] = fromSnorm(src[1], 32767.0f);
		argdst[2] = fromSnorm(src[2], 32767.0f);
		argdst[3] = fromSnorm(src[3], 32767.0f);
	}

	// RGBA16I
	void packRgba16I(void* const argdst, const float* const argsrc) noexcept
	{
		std::int16_t* dst = static_cast<std::int16_t *>(argdst);
		dst[0] = std::int16_t(argsrc[0]);
		dst[1] = std::int16_t(argsrc[1]);
		dst[2] = std::int16_t(argsrc[2]);
		dst[3] = std::int16_t(argsrc[3]);
	}

	void unpackRgba16I(float* const argdst, const void* const argsrc) noexcept
	{
		const std::int16_t* src = static_cast<const std::int16_t *>(argsrc);
		argdst[0] = static_cast<float>(src[0]);
		argdst[1] = static_cast<float>(src[1]);
		argdst[2] = static_cast<float>(src[2]);
		argdst[3] = static_cast<float>(src[3]);
	}

	// RGBA16U
	void packRgba16U(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint16_t* dst = static_cast<std::uint16_t *>(argdst);
		dst[0] = std::uint16_t(argsrc[0]);
		dst[1] = std::uint16_t(argsrc[1]);
		dst[2] = std::uint16_t(argsrc[2]);
		dst[3] = std::uint16_t(argsrc[3]);
	}

	void unpackRgba16U(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint16_t* src = static_cast<const std::uint16_t *>(argsrc);
		argdst[0] = static_cast<float>(src[0]);
		argdst[1] = static_cast<float>(src[1]);
		argdst[2] = static_cast<float>(src[2]);
		argdst[3] = static_cast<float>(src[3]);
	}

#if false
	// RGBA16F
	 void packRgba16F(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint16_t* dst = (std::uint16_t*)argdst;
		dst[0] = halfFromFloat(argsrc[0]);
		dst[1] = halfFromFloat(argsrc[1]);
		dst[2] = halfFromFloat(argsrc[2]);
		dst[3] = halfFromFloat(argsrc[3]);
	}

	 void unpackRgba16F(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint16_t* src = (const std::uint16_t*)argsrc;
		argdst[0] = halfToFloat(src[0]);
		argdst[1] = halfToFloat(src[1]);
		argdst[2] = halfToFloat(src[2]);
		argdst[3] = halfToFloat(src[3]);
	}
#endif

	// R24
	void packR24(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint8_t* dst = static_cast<std::uint8_t *>(argdst);
		const std::uint32_t rr = std::uint32_t(toUnorm(argsrc[0], 16777216.0f));
		dst[0] = std::uint8_t(rr);
		dst[1] = std::uint8_t(rr >> 8);
		dst[2] = std::uint8_t(rr >> 16);
	}

	void unpackR24(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint8_t* src = static_cast<const std::uint8_t *>(argsrc);
		const std::uint32_t rr = 0
			| src[0]
			| src[1] << 8
			| src[2] << 16;

		argdst[0] = fromUnorm(rr, 16777216.0f);
		argdst[1] = 0.0f;
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

	// R24G8
	void packR24G8(void* const argdst, const float* const argsrc) noexcept
	{
		std::uint8_t* dst = static_cast<std::uint8_t *>(argdst);
		const std::uint32_t rr = std::uint32_t(toUnorm(argsrc[0], 16777216.0f));
		dst[0] = std::uint8_t(rr);
		dst[1] = std::uint8_t(rr >> 8);
		dst[2] = std::uint8_t(rr >> 16);
		dst[3] = std::uint8_t(toUnorm(argsrc[1], 255.0f));
	}

	void unpackR24G8(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint8_t* src = static_cast<const std::uint8_t *>(argsrc);
		const std::uint32_t rr = 0
			| src[0]
			| src[1] << 8
			| src[2] << 16;

		argdst[0] = fromUnorm(rr, 16777216.0f);
		argdst[1] = fromUnorm(src[3], 255.0f);
		argdst[2] = 0.0f;
		argdst[3] = 1.0f;
	}

	// R32I
	void packR32I(void* const argdst, const float* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 4);
	}

	void unpackR32I(float* const argdst, const void* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 4);
	}

	// R32U
	void packR32U(void* const argdst, const float* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 4);
	}

	void unpackR32U(float* const argdst, const void* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 4);
	}

	// R32F
	void packR32F(void* const argdst, const float* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 4);
	}

	void unpackR32F(float* const argdst, const void* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 4);
	}

	// RG32I
	void packRg32I(void* const argdst, const float* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 8);
	}

	void unpackRg32I(float* const argdst, const void* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 8);
	}

	// RG32U
	void packRg32U(void* const argdst, const float* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 8);
	}

	void unpackRg32U(float* const argdst, const void* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 8);
	}

	// RG32F
	void packRg32F(void* const argdst, const float* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 8);
	}

	void unpackRg32F(float* const argdst, const void* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 8);
	}

	template<std::int32_t MantissaBits, std::int32_t ExpBits>
	void encodeRgbE(float* const argdst, const float* const argsrc) noexcept
	{
		const std::int32_t expMax = (1 << ExpBits) - 1;
		const std::int32_t expBias = (1 << ExpBits - 1) - 1;
		const float sharedExpMax = static_cast<float>(expMax) / static_cast<float>(expMax + 1) * static_cast<float>(1 << expMax - expBias);

		const float rr = std::clamp(argsrc[0], 0.0f, sharedExpMax);
		const float gg = std::clamp(argsrc[1], 0.0f, sharedExpMax);
		const float bb = std::clamp(argsrc[2], 0.0f, sharedExpMax);
		const float mm = std::max(rr, std::max(gg, bb));
		union
		{
			float ff;
			std::uint32_t ui;
		} cast = {mm};
		std::int32_t expShared = std::int32_t(std::max(std::uint32_t(-expBias - 1), (((cast.ui >> 23) & 0xff) - 127))) + 1 + expBias;
		float denom = pow(2.0f, static_cast<float>(expShared - expBias - MantissaBits));

		if (1 << MantissaBits == std::int32_t(std::round(mm / denom)))
		{
			denom *= 2.0f;
			++expShared;
		}

		const float invDenom = 1.0f / denom;
		argdst[0] = std::round(rr * invDenom);
		argdst[1] = std::round(gg * invDenom);
		argdst[2] = std::round(bb * invDenom);
		argdst[3] = static_cast<float>(expShared);
	}

	template<std::int32_t MantissaBits, std::int32_t ExpBits>
	void decodeRgbE(float* const argdst, const float* const argsrc) noexcept
	{
		const std::int32_t expBias = (1 << ExpBits - 1) - 1;
		const float exponent = argsrc[3] - static_cast<float>(expBias - MantissaBits);
		const float scale = pow(2.0f, exponent);
		argdst[0] = argsrc[0] * scale;
		argdst[1] = argsrc[1] * scale;
		argdst[2] = argsrc[2] * scale;
	}

	// RGB9E5F
	void packRgb9E5F(void* const argdst, const float* const argsrc) noexcept
	{
		float tmp[4];
		encodeRgbE<9, 5>(tmp, argsrc);

		*static_cast<std::uint32_t *>(argdst) = 0
			| std::uint32_t(tmp[0])
			| std::uint32_t(tmp[1]) << 9
			| std::uint32_t(tmp[2]) << 18
			| std::uint32_t(tmp[3]) << 27;
	}

	void unpackRgb9E5F(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint32_t packed = *static_cast<const std::uint32_t *>(argsrc);

		float tmp[4];
		tmp[0] = static_cast<float>(packed & 0x1ff) / 511.0f;
		tmp[1] = static_cast<float>(packed >> 9 & 0x1ff) / 511.0f;
		tmp[2] = static_cast<float>(packed >> 18 & 0x1ff) / 511.0f;
		tmp[3] = static_cast<float>(packed >> 27 & 0x1f);

		decodeRgbE<9, 5>(argdst, tmp);
	}

	// RGBA32I
	void packRgba32I(void* const argdst, const float* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 16);
	}

	void unpackRgba32I(float* const argdst, const void* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 16);
	}

	// RGBA32U
	void packRgba32U(void* const argdst, const float* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 16);
	}

	void unpackRgba32U(float* const argdst, const void* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 16);
	}

	// RGBA32F
	void packRgba32F(void* const argdst, const float* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 16);
	}

	void unpackRgba32F(float* const argdst, const void* const argsrc) noexcept
	{
		std::memcpy(argdst, argsrc, 16);
	}

	// R5G6B5
	void packR5G6B5(void* const argdst, const float* const argsrc) noexcept
	{
		*static_cast<std::uint16_t *>(argdst) = 0
			| std::uint16_t(toUnorm(argsrc[0], 31.0f) << 11)
			| std::uint16_t(toUnorm(argsrc[1], 63.0f) << 5)
			| std::uint16_t(toUnorm(argsrc[2], 31.0f));
	}

	void unpackR5G6B5(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint16_t packed = *static_cast<const std::uint16_t *>(argsrc);
		argdst[0] = static_cast<float>(packed >> 11 & 0x1f) / 31.0f;
		argdst[1] = static_cast<float>(packed >> 5 & 0x3f) / 63.0f;
		argdst[2] = static_cast<float>(packed & 0x1f) / 31.0f;
		argdst[3] = 1.0f;
	}

	// RGBA4
	void packRgba4(void* const argdst, const float* const argsrc) noexcept
	{
		*static_cast<std::uint16_t *>(argdst) = 0
			| std::uint16_t(toUnorm(argsrc[0], 15.0f))
			| std::uint16_t(toUnorm(argsrc[1], 15.0f) << 4)
			| std::uint16_t(toUnorm(argsrc[2], 15.0f) << 8)
			| std::uint16_t(toUnorm(argsrc[3], 15.0f) << 12);
	}

	void unpackRgba4(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint16_t packed = *static_cast<const std::uint16_t *>(argsrc);
		argdst[0] = static_cast<float>(packed & 0xf) / 15.0f;
		argdst[1] = static_cast<float>(packed >> 4 & 0xf) / 15.0f;
		argdst[2] = static_cast<float>(packed >> 8 & 0xf) / 15.0f;
		argdst[3] = static_cast<float>(packed >> 12 & 0xf) / 15.0f;
	}

	// RGBA4
	void packBgra4(void* const argdst, const float* const argsrc) noexcept
	{
		*static_cast<std::uint16_t *>(argdst) = 0
			| std::uint16_t(toUnorm(argsrc[0], 15.0f) << 8)
			| std::uint16_t(toUnorm(argsrc[1], 15.0f) << 4)
			| std::uint16_t(toUnorm(argsrc[2], 15.0f))
			| std::uint16_t(toUnorm(argsrc[3], 15.0f) << 12);
	}

	void unpackBgra4(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint16_t packed = *static_cast<const std::uint16_t *>(argsrc);
		argdst[0] = static_cast<float>(packed >> 8 & 0xf) / 15.0f;
		argdst[1] = static_cast<float>(packed >> 4 & 0xf) / 15.0f;
		argdst[2] = static_cast<float>(packed & 0xf) / 15.0f;
		argdst[3] = static_cast<float>(packed >> 12 & 0xf) / 15.0f;
	}

	// RGB5A1
	void packRgb5a1(void* const argdst, const float* const argsrc) noexcept
	{
		*static_cast<std::uint16_t *>(argdst) = 0
			| std::uint16_t(toUnorm(argsrc[0], 31.0f))
			| std::uint16_t(toUnorm(argsrc[1], 31.0f) << 5)
			| std::uint16_t(toUnorm(argsrc[2], 31.0f) << 10)
			| std::uint16_t(toUnorm(argsrc[3], 1.0f) << 15);
	}

	void unpackRgb5a1(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint16_t packed = *static_cast<const std::uint16_t *>(argsrc);
		argdst[0] = static_cast<float>(packed & 0x1f) / 31.0f;
		argdst[1] = static_cast<float>(packed >> 5 & 0x1f) / 31.0f;
		argdst[2] = static_cast<float>(packed >> 10 & 0x1f) / 31.0f;
		argdst[3] = static_cast<float>(packed >> 14 & 0x1);
	}

	// BGR5A1
	void packBgr5a1(void* const argdst, const float* const argsrc) noexcept
	{
		*static_cast<std::uint16_t *>(argdst) = 0
			| std::uint16_t(toUnorm(argsrc[0], 31.0f) << 10)
			| std::uint16_t(toUnorm(argsrc[1], 31.0f) << 5)
			| std::uint16_t(toUnorm(argsrc[2], 31.0f))
			| std::uint16_t(toUnorm(argsrc[3], 1.0f) << 15);
	}

	void unpackBgr5a1(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint16_t packed = *static_cast<const std::uint16_t *>(argsrc);
		argdst[0] = static_cast<float>(packed >> 10 & 0x1f) / 31.0f;
		argdst[1] = static_cast<float>(packed >> 5 & 0x1f) / 31.0f;
		argdst[2] = static_cast<float>(packed & 0x1f) / 31.0f;
		argdst[3] = static_cast<float>(packed >> 14 & 0x1);
	}

	// RGB10A2
	void packRgb10A2(void* const argdst, const float* const argsrc) noexcept
	{
		*static_cast<std::uint32_t *>(argdst) = 0
			| toUnorm(argsrc[0], 1023.0f)
			| toUnorm(argsrc[1], 1023.0f) << 10
			| toUnorm(argsrc[2], 1023.0f) << 20
			| toUnorm(argsrc[3], 3.0f) << 30;
	}

	void unpackRgb10A2(float* const argdst, const void* const argsrc) noexcept
	{
		const std::uint32_t packed = *static_cast<const std::uint32_t *>(argsrc);
		argdst[0] = static_cast<float>(packed & 0x3ff) / 1023.0f;
		argdst[1] = static_cast<float>(packed >> 10 & 0x3ff) / 1023.0f;
		argdst[2] = static_cast<float>(packed >> 20 & 0x3ff) / 1023.0f;
		argdst[3] = static_cast<float>(packed >> 30 & 0x3) / 3.0f;
	}

#if false
	// RG11B10F
	 void packRG11B10F(void* const argdst, const float* const argsrc) noexcept
	{
		*((std::uint32_t*)argdst) = 0
			| ((halfFromFloat(argsrc[0]) >> 4) & 0x7ff)
			| ((halfFromFloat(argsrc[0]) << 7) & 0x3ff800)
			| ((halfFromFloat(argsrc[0]) << 17) & 0xffc00000)
			;
	}

	 void unpackRG11B10F(float* const argdst, const void* const argsrc) noexcept
	{
		std::uint32_t packed = *((const std::uint32_t*)argsrc);
		argdst[0] = halfToFloat((packed << 4) & 0x7ff0);
		argdst[1] = halfToFloat((packed >> 7) & 0x7ff0);
		argdst[2] = halfToFloat((packed >> 17) & 0x7fe0);
		argdst[3] = 1.0f;
	}
#endif
}
