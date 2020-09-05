// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Memory.cpp
// 01.09.2020 05:02
// =============================================================

#include "Export/KESTD/Memory.hpp"
#include "Export/KESTD/Platform.hpp"

#ifdef COM_MSVC
#	define WIN32_LEAN_AND_MEAN
#	include <malloc.h>
#	include <Windows.h>
#else
#	include <unistd.h>
#endif

namespace kestd::mem
{
	auto AlignedMalloc(void*& mem, std::size_t size, std::size_t alignment) noexcept -> bool
	{
#if COM_MSVC
		return mem = _aligned_malloc(size, alignment);
#else
		return !posix_memalign(mem, alignment, size)
#endif
	}

	void AlignedFree(void*& mem)
	{
#if COM_MSVC
		_aligned_free(mem);
#else
		free(mem);
#endif
		mem = nullptr;
	}

	auto GetPageSize() noexcept -> std::size_t
	{
#if COM_MSVC
		static DWORD Size = 0;
		if (!Size)
		{
			SYSTEM_INFO si;
			GetSystemInfo(&si);
			Size = si.dwPageSize;
		}

		return static_cast<std::size_t>(Size);
#else
		static const long size = sysconf(_SC_PAGESIZE);
		return size > 0 ? static_cast<std::size_t>(size) : 4096;
#endif
	}

#if COM_MSVC
	extern "C" void _ReadBarrier();
#pragma intrinsic(_ReadBarrier)

	extern "C" void _WriteBarrier();
#pragma intrinsic(_WriteBarrier)

	extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)
#endif

	void ReadBarrier() noexcept
	{
#if COM_MSVC
		_ReadBarrier();
#else
		asm volatile("":::"memory");
#endif
	}

	void WriteBarrier() noexcept
	{
#if COM_MSVC
		_WriteBarrier();
#else
		asm volatile("":::"memory");
#endif
	}

	void ReadWriteBarrier() noexcept
	{
#if COM_MSVC
		_ReadWriteBarrier();
#else
		asm volatile("":::"memory");
#endif
	}
}
