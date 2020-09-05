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
	/// <summary>
	/// 
	/// </summary>
	/// <param name="argvalue"></param>
	/// <param name="argscale"></param>
	/// <returns></returns>
	auto toUnorm(float argvalue, float argscale) noexcept -> std::uint32_t;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argvalue"></param>
	/// <param name="argscale"></param>
	/// <returns></returns>
	auto fromUnorm(std::uint32_t argvalue, float argscale) noexcept -> float;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argvalue"></param>
	/// <param name="argscale"></param>
	/// <returns></returns>
	auto toSnorm(float argvalue, float argscale) noexcept -> std::int32_t;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argvalue"></param>
	/// <param name="argscale"></param>
	/// <returns></returns>
	auto fromSnorm(std::int32_t argvalue, float argscale) noexcept -> float;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packA8(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackA8(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packR8(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackR8(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packR8S(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackR8S(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packR8I(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackR8I(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packR8U(void* argdst, const float* argsrc) noexcept;
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackR8U(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRg8(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRg8(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRg8S(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRg8S(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRg8I(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRg8I(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRg8U(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRg8U(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgb8(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgb8(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgb8S(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgb8S(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgb8I(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgb8I(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgb8U(void* argdst, const float* argsrc) noexcept;
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgb8U(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgba8(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgba8(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packBgra8(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackBgra8(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgba8S(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgba8S(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgba8I(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgba8I(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgba8U(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgba8U(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packR16(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackR16(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packR16S(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackR16S(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packR16I(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackR16I(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packR16U(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackR16U(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packR16F(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackR16F(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRg16(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRg16(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRg16S(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRg16S(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRg16I(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRg16I(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRg16U(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRg16U(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRg16F(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRg16F(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgba16(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgba16(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgba16S(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgba16S(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgba16I(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgba16I(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgba16U(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgba16U(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgba16F(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgba16F(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packR32I(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackR32I(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packR32U(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackR32U(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packR32F(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackR32F(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRg32I(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRg32I(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRg32U(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRg32U(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgb9E5F(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgb9E5F(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgba32I(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgba32I(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgba32U(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgba32U(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// /
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgba32F(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// /
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgba32F(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packR5G6B5(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackR5G6B5(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgba4(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgba4(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packBgra4(void* argdst, const float* argsrc) noexcept;
	
	/// <summary>
	/// /
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackBgra4(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgb5a1(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgb5a1(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packBgr5a1(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackBgr5a1(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRgb10A2(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRgb10A2(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRG11B10F(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRG11B10F(float* argdst, const void* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void packRg32F(void* argdst, const float* argsrc) noexcept;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="argdst"></param>
	/// <param name="argsrc"></param>
	/// <returns></returns>
	void unpackRg32F(float* argdst, const void* argsrc) noexcept;
}
