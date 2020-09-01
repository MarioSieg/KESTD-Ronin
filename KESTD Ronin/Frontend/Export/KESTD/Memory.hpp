// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Memory.hpp
// 01.09.2020 04:56
// =============================================================

#pragma once

#include <cstddef>

namespace kestd::memory
{
	/// <summary>
	/// Align up size.
	/// </summary>
	/// <param name="size"></param>
	/// <param name="alignment"></param>
	/// <returns></returns>
	constexpr auto alignUp(const std::size_t size, const std::size_t alignment) noexcept -> std::size_t
	{
		return size + alignment - 1 & ~(alignment - 1);
	}

	/// <summary>
	/// Malloc with alignment.
	/// </summary>
	/// <param name="mem"></param>
	/// <returns></returns>
	[[nodiscard]]
	extern auto alignedMalloc(void*& mem, std::size_t size, std::size_t alignment) noexcept -> bool;

	/// <summary>
	/// Free memory allocated with 'AlignedMalloc'.
	/// </summary>
	extern void alignedFree(void*& mem);

	/// <summary>
	/// Returns the page size.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	extern auto getPageSize() noexcept -> std::size_t;

	/// <summary>
	/// Insert read barrier.
	/// </summary>
	/// <returns></returns>
	extern void readBarrier() noexcept;

	/// <summary>
	/// Insert write barrier.
	/// </summary>
	/// <returns></returns>
	extern void writeBarrier() noexcept;

	/// <summary>
	/// Insert read write barrier.
	/// </summary>
	/// <returns></returns>
	extern void readWriteBarrier() noexcept;
}
