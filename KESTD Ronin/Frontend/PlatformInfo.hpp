// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// PlatformInfo.hpp
// 09.08.2020 07:24
// =============================================================

#pragma once


/// <summary>
/// Are we on Linux?
/// </summary>
#define SYS_LINUX false

/// <summary>
/// Are we on Windows?
/// </summary>
#define SYS_WINDOWS false

/// <summary>
/// Are we on Mac?
/// </summary>
#define SYS_MAC false

/// <summary>
/// The name of the current system.
/// </summary>
#define SYS_NAME "Unknown"

/// <summary>
/// Are we compiling with GCC?
/// </summary>
#define COM_GCC false

/// <summary>
/// Are we compiling with MSVC?
/// </summary>
#define COM_MSVC false

/// <summary>
/// Are we compiling with Clang?
/// </summary>
#define COM_CLANG false

/// <summary>
/// The name of the current compiler.
/// </summary>
#define COM_NAME "Unknown"

#if defined(__linux__) &&! defined(__ANDROID__)
#	undef SYS_LINUX
#	define SYS_LINUX true
#	undef SYS_NAME
#	define SYS_NAME "Linux"
#elif defined(_WIN64)
#	undef SYS_WINDOWS
#	define SYS_WINDOWS true
#	undef SYS_NAME
#	define SYS_NAME "Windows"
#elif defined(__APPLE__)
#	undef SYS_MAC
#	define SYS_MAC true
#	undef SYS_NAME
#	define SYS_NAME "Mac"
#else
#error("(PlatformData.hpp) Unknown platform!")
#endif

#if defined(__GNUC__)
#	undef COM_GCC
#	define COM_GCC true
#	undef COM_NAME
#	define COM_NAME "GCC"
#elif defined(_MSC_VER)
#	undef COM_MSVC
#	define COM_MSVC true
#	undef COM_NAME
#	define COM_NAME "MSVC"
#elif defined(__clang__)
#undef COM_CLANG
#	define COM_CLANG true
#	undef COM_NAME
#	define COM_NAME "Clang"
#else
#error("(PlatformData.hpp) Unknown compiler!")
#endif


#include <cstdint>
#include <string>
#include <vector>

namespace kestd
{
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
		Count,
	};

	constexpr std::string_view ArchitecureNames[static_cast<std::size_t>(Architecture::Count)]
	{
		"X86_64",
		"ARM",
		"Itanium",
		"X86",
		"Other"
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
		Count,
	};

	constexpr std::string_view InstructionSetNames[static_cast<std::size_t>(InstructionSet::Count)]
	{
		"3DNow",
		"3DNow EX",
		"MMX",
		"MMX EX",
		"SSE",
		"SSE2",
		"SSE3",
		"SSSE3",
		"SSE4 A",
		"SSE4 1",
		"SSE4 2",
		"AES",
		"AVX",
		"AVX2",
		"AVX512",
		"AVX512 F",
		"AVX512 CD",
		"AVX512 PF",
		"AVX512 ER",
		"AVX512 VL",
		"AVX512 BW",
		"AVX512 BQ",
		"AVX512 DQ",
		"AVX512 IFMA",
		"AVX512 VBMI",
		"HLE",
		"BMI1",
		"BMI2",
		"ADX",
		"MPX",
		"SHA",
		"Prefetch WT1",
		"FMA3",
		"FMA4",
		"XOP",
		"RD Rand",
		"X64",
		"X87 FPU"
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
		Count
	};

	constexpr std::string_view CacheNames[static_cast<std::size_t>(CacheType::Count)]
	{
		"Unified",
		"Instruction",
		"Data",
		"Trace"
	};

	/// <summary>
	/// Contains cache info.
	/// </summary>
	class Cache final
	{
	public:
		std::size_t size;
		std::size_t lineSize;
		std::size_t associativity;
		CacheType type;
	};

	/// <summary>
	/// Contains CPU info.
	/// </summary>
	class CpuInfo final
	{
	public:
		std::uint16_t logical;
		std::uint16_t physical;
		std::uint16_t sockets;
		std::uint64_t frequency;
		std::string vendor;
		std::string vendorId;
		std::string modelName;
		Architecture architecture;
		Cache caches[3];
		Endianness endianness;
		std::vector<InstructionSet> supportedInstructionSets;

		void query();
		auto toStr() const -> std::string;
	};


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
		Count
	};

	constexpr std::string_view VendorNames[static_cast<std::size_t>(Vendor::Count)]
	{
		"Intel",
		"AMD",
		"Nvidia",
		"Microsoft",
		"Qualcomm",
		"Other",
	};


	/// <summary>
	/// Contains GPU info.
	/// </summary>
	class GpuInfo final
	{
	public:
		Vendor vendor = Vendor::Other;
		std::string name;
		std::size_t memorySize;
		std::size_t cacheSize;
		std::size_t maxFrequency;
	};

	/// <summary>
	/// Contains info about the graphics API and limitations.
	/// </summary>
	class GpuAdapterLimits final
	{
	public:
		std::uint32_t maxDrawCalls;            // Maximum number of draw calls.
		std::uint32_t maxBlits;                // Maximum number of blit calls.
		std::uint32_t maxTextureSize;          // Maximum texture size.
		std::uint32_t maxTextureLayers;        // Maximum texture layers.
		std::uint32_t maxViews;                // Maximum number of views.
		std::uint32_t maxFrameBuffers;         // Maximum number of frame buffer handles.
		std::uint32_t maxFBAttachments;        // Maximum number of frame buffer attachments.
		std::uint32_t maxPrograms;             // Maximum number of program handles.
		std::uint32_t maxShaders;              // Maximum number of shader handles.
		std::uint32_t maxTextures;             // Maximum number of texture handles.
		std::uint32_t maxTextureSamplers;      // Maximum number of texture samplers.
		std::uint32_t maxComputeBindings;      // Maximum number of compute bindings.
		std::uint32_t maxVertexLayouts;        // Maximum number of vertex format layouts.
		std::uint32_t maxVertexStreams;        // Maximum number of vertex streams.
		std::uint32_t maxIndexBuffers;         // Maximum number of index buffer handles.
		std::uint32_t maxVertexBuffers;        // Maximum number of vertex buffer handles.
		std::uint32_t maxDynamicIndexBuffers;  // Maximum number of dynamic index buffer handles.
		std::uint32_t maxDynamicVertexBuffers; // Maximum number of dynamic vertex buffer handles.
		std::uint32_t maxUniforms;             // Maximum number of uniform handles.
		std::uint32_t maxOcclusionQueries;     // Maximum number of occlusion query handles.
		std::uint32_t maxEncoders;             // Maximum number of encoder threads.
		std::uint32_t minResourceCbSize;       // Minimum resource command buffer size.
		std::uint32_t transientVbSize;         // Maximum transient vertex buffer size.
		std::uint32_t transientIbSize;         // Maximum transient index buffer size.
	};

	/// <summary>
	/// Contains GPU info.
	/// TODO Add list with supported texture formats.
	/// </summary>
	class GpuInfoCollection final
	{
	public:
		std::vector<GpuInfo> allGpus;
		GpuAdapterLimits adapterLimits;
		void query();
		auto toStr() const -> std::string;
	};

	/// <summary>
	/// Represents a monitor/TV/display.
	/// </summary>
	class DisplayInfo final
	{
	public:
		std::uint16_t width;
		std::uint16_t height;
		std::uint16_t dpi;
		std::uint16_t bpp;
		double refreshRate;
	};

	class OsInfo final
	{
	public:
		struct
		{
			std::uint64_t physicalAvailable;
			std::uint64_t physicalTotal;
			std::uint64_t virtualAvailable;
			std::uint64_t virtualTotal;
		} memory;

		struct
		{
			std::uint32_t major;
			std::uint32_t minor;
			std::uint32_t patch;
			std::uint32_t build;
		} kernel;

		struct
		{
			std::string name;
			std::string fullName;
			std::uint32_t major;
			std::uint32_t minor;
			std::uint32_t patch;
			std::uint32_t build;
		} os;

		void query();
		auto toStr() const -> std::string;
	};

	class PeripheryInfo final
	{
	public:
		std::vector<DisplayInfo> displays;

		void query();
		auto toStr() const -> std::string;
	};

	class PlatformInfo final
	{
	public:
		CpuInfo cpuInfo;
		GpuInfoCollection gpuInfos;
		OsInfo osInfo;
		PeripheryInfo peripheryInfo;
	};
}
