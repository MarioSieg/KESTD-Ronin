// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD Ronin
// Mario
// OsInfo.hpp
// 07.08.2020 12:52

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace kestd
{
	class Logger;

	/// <summary>
	/// Represents an architecture.
	/// </summary>
	enum class Architecture
	{
		X64,
		Arm,
		Itanium,
		X86,
		Other,
	};

	/// <summary>
	/// Represents CPU endianness.
	/// </summary>
	enum class Endianness
	{
		Little,
		Big,
	};

	/// <summary>
	/// Represents an instruction set.
	/// </summary>
	enum class InstructionSet
	{
		S3DNow,
		S3DNowEx,
		Mmx,
		MmxEx,
		Sse,
		Sse2,
		Sse3,
		Ssse3,
		Sse4a,
		Sse41,
		Sse42,
		Aes,
		Avx,
		Avx2,
		Avx512,
		Avx512_F,
		Avx512_Cd,
		Avx512_Pf,
		Avx512_Er,
		Avx512_Vl,
		Avx512_Bw,
		Avx512_Bq,
		Avx512_Dq,
		Avx512_Ifma,
		Avx512_Vbmi,
		Hle,
		Bmi1,
		Bmi2,
		Adx,
		Mpx,
		Sha,
		PrefetchWt1,
		Fma3,
		Fma4,
		Xop,
		RdRand,
		x64,
		x87Fpu,
	};

	/// <summary>
	/// Different cache types.
	/// </summary>
	enum class CacheType
	{
		Unified,
		Instruction,
		Data,
		Trace,
	};

	/// <summary>
	/// Contains cache info.
	/// </summary>
	struct Cache final
	{
		std::size_t Size = 0;
		std::size_t LineSize = 0;
		std::size_t Associativity = 0;
		CacheType Type = CacheType::Data;
	};

	/// <summary>
	/// Contains CPU info.
	/// </summary>
	struct CpuInfo final
	{
		std::uint16_t Logical = 0;
		std::uint16_t Physical = 0;
		std::uint16_t Sockets = 0;
		std::uint64_t Frequency = 0;
		std::string Vendor = {};
		std::string VendorId = {};
		std::string ModelName = {};
		Architecture Architecture = Architecture::Other;
		Cache Caches[3] = {};
		Endianness Endianness = Endianness::Little;
		std::vector<InstructionSet> SupportedInstructionSets = {};

		void query();
	};

	auto operator <<(Logger& out, const CpuInfo& info) -> Logger&;


	/// <summary>
	/// Represents a GPU vendor.
	/// </summary>
	enum class Vendor
	{
		Intel,
		Amd,
		Nvidia,
		Microsoft,
		Qualcomm,
		Other,
	};


	/// <summary>
	/// Contains GPU info.
	/// </summary>
	struct GpuInfo final
	{
		Vendor Vendor = Vendor::Other;
		std::string Name = {};
		std::size_t MemorySize = 0;
		std::size_t CacheSize = 0;
		std::size_t MaxFrequency = 0;
	};

	/// <summary>
	/// Contains GPU info.
	/// </summary>
	struct GpuInfoCollection final
	{
		std::vector<GpuInfo> AllGpus = {};
		void query();
	};

	auto operator <<(Logger& out, const GpuInfoCollection& info) -> Logger&;

	struct OsInfo final
	{
		struct
		{
			std::uint64_t PhysicalAvailable = 0;
			std::uint64_t PhysicalTotal = 0;
			std::uint64_t VirtualAvailable = 0;
			std::uint64_t VirtualTotal = 0;
		} Memory;

		struct
		{
			std::uint32_t Major = 0;
			std::uint32_t Minor = 0;
			std::uint32_t Patch = 0;
			std::uint32_t Build = 0;
		} Kernel;

		struct
		{
			std::string Name = {};
			std::string FullName = {};
			std::uint32_t Major = 0;
			std::uint32_t Minor = 0;
			std::uint32_t Patch = 0;
			std::uint32_t Build = 0;
		} Os;

		void query();
	};

	auto operator <<(Logger& out, const OsInfo& info) -> Logger&;

	struct PlatformInfo final
	{
		CpuInfo CpuInfo;
		GpuInfoCollection GpuInfos;
		OsInfo OsInfo;
	};
}
