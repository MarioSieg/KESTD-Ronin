// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Pixelformat.hpp
// 01.09.2020 05:50
// =============================================================

#pragma once

#include <cstdint>

namespace kestd::pixelformat
{
	///
	auto toUnorm(float argvalue, float argscale) noexcept -> std::uint32_t;

	///
	auto fromUnorm(std::uint32_t argvalue, float argscale) noexcept -> float;

	///
	auto toSnorm(float argvalue, float argscale) noexcept -> std::int32_t;

	///
	auto fromSnorm(std::int32_t argvalue, float argscale) noexcept -> float;

	// A8
	void packA8(void* argdst, const float* argsrc) noexcept;
	void unpackA8(float* argdst, const void* argsrc) noexcept;

	// R8
	void packR8(void* argdst, const float* argsrc) noexcept;
	void unpackR8(float* argdst, const void* argsrc) noexcept;

	// R8S
	void packR8S(void* argdst, const float* argsrc) noexcept;
	void unpackR8S(float* argdst, const void* argsrc) noexcept;

	// R8I
	void packR8I(void* argdst, const float* argsrc) noexcept;
	void unpackR8I(float* argdst, const void* argsrc) noexcept;

	// R8U
	void packR8U(void* argdst, const float* argsrc) noexcept;
	void unpackR8U(float* argdst, const void* argsrc) noexcept;

	// RG8
	void packRg8(void* argdst, const float* argsrc) noexcept;
	void unpackRg8(float* argdst, const void* argsrc) noexcept;

	// RG8S
	void packRg8S(void* argdst, const float* argsrc) noexcept;
	void unpackRg8S(float* argdst, const void* argsrc) noexcept;

	// RG8I
	void packRg8I(void* argdst, const float* argsrc) noexcept;
	void unpackRg8I(float* argdst, const void* argsrc) noexcept;

	// RG8U
	void packRg8U(void* argdst, const float* argsrc) noexcept;
	void unpackRg8U(float* argdst, const void* argsrc) noexcept;

	// RGB8
	void packRgb8(void* argdst, const float* argsrc) noexcept;
	void unpackRgb8(float* argdst, const void* argsrc) noexcept;

	// RGB8S
	void packRgb8S(void* argdst, const float* argsrc) noexcept;
	void unpackRgb8S(float* argdst, const void* argsrc) noexcept;

	// RGB8I
	void packRgb8I(void* argdst, const float* argsrc) noexcept;
	void unpackRgb8I(float* argdst, const void* argsrc) noexcept;

	// RGB8U
	void packRgb8U(void* argdst, const float* argsrc) noexcept;
	void unpackRgb8U(float* argdst, const void* argsrc) noexcept;

	// RGBA8
	void packRgba8(void* argdst, const float* argsrc) noexcept;
	void unpackRgba8(float* argdst, const void* argsrc) noexcept;

	// BGRA8
	void packBgra8(void* argdst, const float* argsrc) noexcept;
	void unpackBgra8(float* argdst, const void* argsrc) noexcept;

	// RGBA8S
	void packRgba8S(void* argdst, const float* argsrc) noexcept;
	void unpackRgba8S(float* argdst, const void* argsrc) noexcept;

	// RGBA8I
	void packRgba8I(void* argdst, const float* argsrc) noexcept;
	void unpackRgba8I(float* argdst, const void* argsrc) noexcept;

	// RGBA8U
	void packRgba8U(void* argdst, const float* argsrc) noexcept;
	void unpackRgba8U(float* argdst, const void* argsrc) noexcept;

	// R16
	void packR16(void* argdst, const float* argsrc) noexcept;
	void unpackR16(float* argdst, const void* argsrc) noexcept;

	// R16S
	void packR16S(void* argdst, const float* argsrc) noexcept;
	void unpackR16S(float* argdst, const void* argsrc) noexcept;

	// R16I
	void packR16I(void* argdst, const float* argsrc) noexcept;
	void unpackR16I(float* argdst, const void* argsrc) noexcept;

	// R16U
	void packR16U(void* argdst, const float* argsrc) noexcept;
	void unpackR16U(float* argdst, const void* argsrc) noexcept;

	// R16F
	void packR16F(void* argdst, const float* argsrc) noexcept;
	void unpackR16F(float* argdst, const void* argsrc) noexcept;

	// RG16
	void packRg16(void* argdst, const float* argsrc) noexcept;
	void unpackRg16(float* argdst, const void* argsrc) noexcept;

	// RG16S
	void packRg16S(void* argdst, const float* argsrc) noexcept;
	void unpackRg16S(float* argdst, const void* argsrc) noexcept;

	// RG16I
	void packRg16I(void* argdst, const float* argsrc) noexcept;
	void unpackRg16I(float* argdst, const void* argsrc) noexcept;

	// RG16U
	void packRg16U(void* argdst, const float* argsrc) noexcept;
	void unpackRg16U(float* argdst, const void* argsrc) noexcept;

	// RG16F
	void packRg16F(void* argdst, const float* argsrc) noexcept;
	void unpackRg16F(float* argdst, const void* argsrc) noexcept;

	// RGBA16
	void packRgba16(void* argdst, const float* argsrc) noexcept;
	void unpackRgba16(float* argdst, const void* argsrc) noexcept;

	// RGBA16S
	void packRgba16S(void* argdst, const float* argsrc) noexcept;
	void unpackRgba16S(float* argdst, const void* argsrc) noexcept;

	// RGBA16I
	void packRgba16I(void* argdst, const float* argsrc) noexcept;
	void unpackRgba16I(float* argdst, const void* argsrc) noexcept;

	// RGBA16U
	void packRgba16U(void* argdst, const float* argsrc) noexcept;
	void unpackRgba16U(float* argdst, const void* argsrc) noexcept;

	// RGBA16F
	void packRgba16F(void* argdst, const float* argsrc) noexcept;
	void unpackRgba16F(float* argdst, const void* argsrc) noexcept;

	// R32I
	void packR32I(void* argdst, const float* argsrc) noexcept;
	void unpackR32I(float* argdst, const void* argsrc) noexcept;

	// R32U
	void packR32U(void* argdst, const float* argsrc) noexcept;
	void unpackR32U(float* argdst, const void* argsrc) noexcept;

	// R32F
	void packR32F(void* argdst, const float* argsrc) noexcept;
	void unpackR32F(float* argdst, const void* argsrc) noexcept;

	// RG32I
	void packRg32I(void* argdst, const float* argsrc) noexcept;
	void unpackRg32I(float* argdst, const void* argsrc) noexcept;

	// RG32U
	void packRg32U(void* argdst, const float* argsrc) noexcept;
	void unpackRg32U(float* argdst, const void* argsrc) noexcept;

	// RGB9E5F
	void packRgb9E5F(void* argdst, const float* argsrc) noexcept;
	void unpackRgb9E5F(float* argdst, const void* argsrc) noexcept;

	// RGBA32I
	void packRgba32I(void* argdst, const float* argsrc) noexcept;
	void unpackRgba32I(float* argdst, const void* argsrc) noexcept;

	// RGBA32U
	void packRgba32U(void* argdst, const float* argsrc) noexcept;
	void unpackRgba32U(float* argdst, const void* argsrc) noexcept;

	// RGBA32F
	void packRgba32F(void* argdst, const float* argsrc) noexcept;
	void unpackRgba32F(float* argdst, const void* argsrc) noexcept;

	// R5G6B5
	void packR5G6B5(void* argdst, const float* argsrc) noexcept;
	void unpackR5G6B5(float* argdst, const void* argsrc) noexcept;

	// RGBA4
	void packRgba4(void* argdst, const float* argsrc) noexcept;
	void unpackRgba4(float* argdst, const void* argsrc) noexcept;

	// RGBA4
	void packBgra4(void* argdst, const float* argsrc) noexcept;
	void unpackBgra4(float* argdst, const void* argsrc) noexcept;

	// RGB5A1
	void packRgb5a1(void* argdst, const float* argsrc) noexcept;
	void unpackRgb5a1(float* argdst, const void* argsrc) noexcept;

	// BGR5A1
	void packBgr5a1(void* argdst, const float* argsrc) noexcept;
	void unpackBgr5a1(float* argdst, const void* argsrc) noexcept;

	// RGB10A2
	void packRgb10A2(void* argdst, const float* argsrc) noexcept;
	void unpackRgb10A2(float* argdst, const void* argsrc) noexcept;

	// RG11B10F
	void packRG11B10F(void* argdst, const float* argsrc) noexcept;
	void unpackRG11B10F(float* argdst, const void* argsrc) noexcept;

	// RG32F
	void packRg32F(void* argdst, const float* argsrc) noexcept;
	void unpackRg32F(float* argdst, const void* argsrc) noexcept;
}
