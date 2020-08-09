// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// OsInfo.hpp
// 07.08.2020 12:52
// =============================================================

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
		Sse4A,
		Sse41,
		Sse42,
		Aes,
		Avx,
		Avx2,
		Avx512,
		Avx512F,
		Avx512Cd,
		Avx512Pf,
		Avx512Er,
		Avx512Vl,
		Avx512Bw,
		Avx512Bq,
		Avx512Dq,
		Avx512Ifma,
		Avx512Vbmi,
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
		X64,
		X87Fpu,
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
		std::size_t size = 0;
		std::size_t lineSize = 0;
		std::size_t associativity = 0;
		CacheType type = CacheType::Data;
	};

	/// <summary>
	/// Contains CPU info.
	/// </summary>
	struct CpuInfo final
	{
		std::uint16_t logical = 0;
		std::uint16_t physical = 0;
		std::uint16_t sockets = 0;
		std::uint64_t frequency = 0;
		std::string vendor = {};
		std::string vendorId = {};
		std::string modelName = {};
		Architecture architecture = Architecture::Other;
		Cache caches[3] = {};
		Endianness endianness = Endianness::Little;
		std::vector<InstructionSet> supportedInstructionSets = {};

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
		Vendor vendor = Vendor::Other;
		std::string name = {};
		std::size_t memorySize = 0;
		std::size_t cacheSize = 0;
		std::size_t maxFrequency = 0;
	};

	/// <summary>
	/// Contains GPU info.
	/// </summary>
	struct GpuInfoCollection final
	{
		std::vector<GpuInfo> allGpus = {};
		void query();
	};

	auto operator <<(Logger& out, const GpuInfoCollection& info) -> Logger&;

	struct OsInfo final
	{
		struct
		{
			std::uint64_t physicalAvailable = 0;
			std::uint64_t physicalTotal = 0;
			std::uint64_t virtualAvailable = 0;
			std::uint64_t virtualTotal = 0;
		} memory;

		struct
		{
			std::uint32_t major = 0;
			std::uint32_t minor = 0;
			std::uint32_t patch = 0;
			std::uint32_t build = 0;
		} kernel;

		struct
		{
			std::string name = {};
			std::string fullName = {};
			std::uint32_t major = 0;
			std::uint32_t minor = 0;
			std::uint32_t patch = 0;
			std::uint32_t build = 0;
		} os;

		void query();
	};

	auto operator <<(Logger& out, const OsInfo& info) -> Logger&;

	struct PlatformInfo final
	{
		CpuInfo cpuInfo;
		GpuInfoCollection gpuInfos;
		OsInfo osInfo;
	};
}
