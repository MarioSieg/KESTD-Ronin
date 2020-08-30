// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Platform.hpp
// 30.08.2020 12:40
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
	enum class CpuArchitecture
	{
		X64,
		Arm,
		Itanium,
		X86,
		Other,
		Count,
	};

	/// <summary>
	/// Contains all architecture names a string.
	/// </summary>
	constexpr std::string_view CpuArchitecureNames[static_cast<std::size_t>(CpuArchitecture::Count)]
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
	enum class CpuEndianness
	{
		Little,
		Big,
	};

	/// <summary>
	/// Represents an instruction set.
	/// </summary>
	enum class CpuInstructionSet
	{
		/// <summary>
		/// AMD 3D Now
		/// </summary>
		S3DNow,

		/// <summary>
		///  AMD 3D Now Extended
		/// </summary>
		S3DNowEx,

		/// <summary>
		/// Multi Media Extension
		/// </summary>
		Mmx,

		/// <summary>
		///  Multi Media Extension Extended
		/// </summary>
		MmxEx,

		/// <summary>
		/// Streaming SIMD Extensions
		/// </summary>
		Sse,

		/// <summary>
		/// Streaming SIMD Extensions 2
		/// </summary>
		Sse2,

		/// <summary>
		/// Streaming SIMD Extensions 3
		/// </summary>
		Sse3,

		/// <summary>
		/// Supplemental Streaming SIMD Extensions 3
		/// </summary>
		Ssse3,

		/// <summary>
		/// Streaming SIMD Extensions 4 A
		/// </summary>
		Sse4A,

		/// <summary>
		/// Streaming SIMD Extensions 4 1
		/// </summary>
		Sse41,

		/// <summary>
		/// Streaming SIMD Extensions 4 2
		/// </summary>
		Sse42,

		/// <summary>
		/// Advanced Encryption Standart
		/// </summary>
		Aes,

		/// <summary>
		/// Advancted Vector Extensions
		/// </summary>
		Avx,

		/// <summary>
		/// Advancted Vector Extensions
		/// </summary>
		Avx2,

		/// <summary>
		/// Advancted Vector Extensions 512-bit
		/// </summary>
		Avx512,

		/// <summary>
		/// Advancted Vector Extensions 512-bit
		/// </summary>
		Avx512F,

		/// <summary>
		/// Advancted Vector Extensions 512-bit
		/// </summary>
		Avx512Cd,

		/// <summary>
		/// 
		/// </summary>
		Avx512Pf,

		/// <summary>
		/// Advancted Vector Extensions 512-bit
		/// </summary>
		Avx512Er,

		/// <summary>
		/// Advancted Vector Extensions 512-bit
		/// </summary>
		Avx512Vl,

		/// <summary>
		/// Advancted Vector Extensions 512-bit
		/// </summary>
		Avx512Bw,

		/// <summary>
		/// Advancted Vector Extensions 512-bit
		/// </summary>
		Avx512Bq,

		/// <summary>
		/// Advancted Vector Extensions 512-bit
		/// </summary>
		Avx512Dq,

		/// <summary>
		/// Advancted Vector Extensions 512-bit
		/// </summary>
		Avx512Ifma,

		/// <summary>
		/// Advancted Vector Extensions 512-bit
		/// </summary>
		Avx512Vbmi,

		/// <summary>
		/// Hardware Lock Elision
		/// </summary>
		Hle,

		/// <summary>
		/// Bit Manipulation 1
		/// </summary>
		Bmi1,

		/// <summary>
		/// Bit Manipulation 2
		/// </summary>
		Bmi2,

		/// <summary>
		/// Add Carry Extensions
		/// </summary>
		Adx,

		/// <summary>
		/// Memory Protection Extensions
		/// </summary>
		Mpx,

		/// <summary>
		/// Secure Hash Algorithm
		/// </summary>
		Sha,

		/// <summary>
		/// Prefetch Vector Data Into Caches
		/// </summary>
		PrefetchWt1,

		/// <summary>
		/// Fused Multiply Add 3
		/// </summary>
		Fma3,

		/// <summary>
		/// Fused Multiply Add 4
		/// </summary>
		Fma4,

		/// <summary>
		/// Extended Operations
		/// </summary>
		Xop,

		/// <summary>
		/// RealRandomGenerator
		/// </summary>
		RdRand,

		/// <summary>
		/// x86_64
		/// </summary>
		X64,

		/// <summary>
		/// x87 Floating Point Unit
		/// </summary>
		X87Fpu,

		Count,
	};

	/// <summary>
	/// Contains all instrunction set names as string.
	/// </summary>
	constexpr std::string_view CpuInstructionSetNames[static_cast<std::size_t>(CpuInstructionSet::Count)]
	{
		"3DNow",
		"3DNow-Extended",
		"MMX-MultiMediaExtension",
		"MMX-MultiMediaExtensionExtended",
		"SSE-StreamingSIMDExtensions",
		"SSE2-StreamingSIMDExtensions",
		"SSE3-StreamingSIMDExtensions",
		"SSSE3-SupplementalStreamingSIMDExtensions",
		"SSE4A-StreamingSIMDExtensions",
		"SSE41-StreamingSIMDExtensions",
		"SSE42-StreamingSIMDExtensions",
		"AES-AdvancedEncryptionStandart",
		"AVX-AdvancedVectorExtensions",
		"AVX2-AdvancedVectorExtensions",
		"AVX512-AdvancedVectorExtensions",
		"AVX512F-AdvancedVectorExtensions",
		"AVX512CD-AdvancedVectorExtensions",
		"AVX512PF-AdvancedVectorExtensions",
		"AVX512ER-AdvancedVectorExtensions",
		"AVX512VL-AdvancedVectorExtensions",
		"AVX512BW-AdvancedVectorExtensions",
		"AVX512BQ-AdvancedVectorExtensions",
		"AVX512DQ-AdvancedVectorExtensions",
		"AVX512IFMA-AdvancedVectorExtensions",
		"AVX512VBMI-AdvancedVectorExtensions",
		"HLE-HardwareLockElisionExtensions",
		"BMI1-BitManipulationExtensions",
		"BMI2-BitManipulationExtensions",
		"ADX-AddCarryExtensions",
		"MPX-MemoryProtectionExtensions",
		"SHA-SecureHashAlgorithmExtensions",
		"PrefetchWT1-PrefetchVectorData2CacheExtensions",
		"FMA3-FusedMultiplyAddExtensions",
		"FMA4-FusedMultiplyAddExtensions",
		"XOP-ExtendedOperations",
		"RDRand-RealNumberGeneratorExtensions",
		"X64-64BitExtensionsForX86",
		"X87FPU-FloatingPointUnitExtensions"
	};

	/// <summary>
	/// Different cache types.
	/// </summary>
	enum class CpuCacheType
	{
		Unified,
		Instruction,
		Data,
		Trace,
		Count
	};

	/// <summary>
	/// Contains all cache type names as string.
	/// </summary>
	constexpr std::string_view CpuCacheNames[static_cast<std::size_t>(CpuCacheType::Count)]
	{
		"Unified",
		"Instruction",
		"Data",
		"Trace"
	};

	/// <summary>
	/// Represents a CPU cache.
	/// </summary>
	class CpuCache final
	{
		friend class CpuInfo;
	public:
		/// <summary>
		///
		/// </summary>
		/// <returns>The size in bytes.</returns>
		[[nodiscard]]
		auto getSize() const noexcept -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The line size in bytes.</returns>
		[[nodiscard]]
		auto getLineSize() const noexcept -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The associativity.</returns>
		[[nodiscard]]
		auto getAssociativity() const noexcept -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getType() const noexcept -> CpuCacheType;

	private:
		std::size_t size = 0;
		std::size_t lineSize = 0;
		std::size_t associativity = 0;
		CpuCacheType type = CpuCacheType::Data;
	};

	/// <summary>
	/// Contains CPU info.
	/// </summary>
	class CpuInfo final
	{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <returns>Number of logical cores.</returns>
		[[nodiscard]]
		auto getLogicalCores() const noexcept -> std::uint16_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Number of physical cores.</returns>
		[[nodiscard]]
		auto getPhysicalCores() const noexcept -> std::uint16_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Number of sockets.</returns>
		[[nodiscard]]
		auto getSockets() const noexcept -> std::uint16_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Base clock frequency in Herz.</returns>
		[[nodiscard]]
		auto getFrequency() const noexcept -> std::uint64_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>GpuVendor name.</returns>
		[[nodiscard]]
		auto getVendorName() const noexcept -> const std::string&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>GpuVendor ID name.</returns>
		[[nodiscard]]
		auto getVendorID() const noexcept -> const std::string&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Full model name.</returns>
		[[nodiscard]]
		auto getModelName() const noexcept -> const std::string&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>CpuArchitecture.</returns>
		[[nodiscard]]
		auto getArchitecture() const noexcept -> CpuArchitecture;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>All caches.</returns>
		[[nodiscard]]
		auto getCaches() const noexcept -> const CpuCache(&)[3];

		/// <summary>
		/// 
		/// </summary>
		/// <returns>CpuEndianness.</returns>
		[[nodiscard]]
		auto getEndianness() const noexcept -> CpuEndianness;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>All supported instrunction sets.</returns>
		[[nodiscard]]
		auto getSupportedInstructionSets() const noexcept -> const std::vector<CpuInstructionSet>&;

		/// <summary>
		/// Queries the data from the system.
		/// </summary>
		void query();

		/// <summary>
		/// 
		/// </summary>
		/// <returns>A formatted string, which contains all the data beautiful printed.</returns>
		[[nodiscard]]
		auto toStr() const -> std::string;

	private:
		std::uint16_t logical = 0;
		std::uint16_t physical = 0;
		std::uint16_t sockets = 0;
		std::uint64_t frequency = 0;
		std::string vendor = {};
		std::string vendorId = {};
		std::string modelName = {};
		CpuArchitecture architecture = CpuArchitecture::Other;
		CpuCache caches[3] = {};
		CpuEndianness endianness = CpuEndianness::Little;
		std::vector<CpuInstructionSet> supportedInstructionSets = {};
	};


	/// <summary>
	/// Represents a GPU vendor.
	/// </summary>
	enum class GpuVendor
	{
		Intel,
		Amd,
		Nvidia,
		Microsoft,
		Qualcomm,
		Other,
		Count
	};

	/// <summary>
	/// Contains all vendor names as string.
	/// </summary>
	constexpr std::string_view GpuVendorNames[static_cast<std::size_t>(GpuVendor::Count)]
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
	class GpuDevice final
	{
		friend class GpuInfoCollection;
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <returns>GPU vendor type.</returns>
		[[nodiscard]]
		auto getVendor() const noexcept -> GpuVendor;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Model name.</returns>
		[[nodiscard]]
		auto getModelName() const noexcept -> const std::string&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>VRAM memory size in bytes.</returns>
		[[nodiscard]]
		auto getMemorySize() const noexcept -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>CpuCache size in bytes.</returns>
		[[nodiscard]]
		auto getCacheSize() const noexcept -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Max frequency in Herz.</returns>
		[[nodiscard]]
		auto getMaxFrequency() const noexcept -> std::size_t;

	private:
		GpuVendor vendor = GpuVendor::Other;
		std::string name = {};
		std::size_t memorySize = 0;
		std::size_t cacheSize = 0;
		std::size_t maxFrequency = 0;
	};

	/// <summary>
	/// Contains info about the graphics API and limitations.
	/// </summary>
	class GpuAdapterLimits final
	{
		friend class GpuInfoCollection;
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of draw calls.</returns>
		[[nodiscard]]
		auto getMaxDrawCalls() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of blit calls.</returns>
		[[nodiscard]]
		auto getMaxBlitCalls() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum texture size.</returns>
		[[nodiscard]]
		auto getMaxTextureSize() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of texture layers.</returns>
		[[nodiscard]]
		auto getMaxTextureLayers() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of views.</returns>
		[[nodiscard]]
		auto getMaxViews() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of frame buffer handles.</returns>
		[[nodiscard]]
		auto getMaxFrameBuffers() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of frame buffer attachments.</returns>
		[[nodiscard]]
		auto getMaxFrameBufferAttachments() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of program handles.</returns>
		[[nodiscard]]
		auto getMaxPrograms() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of shader handles.</returns>
		[[nodiscard]]
		auto getMaxShaders() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of texture handles.</returns>
		[[nodiscard]]
		auto getMaxTextures() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of texture samplers.</returns>
		[[nodiscard]]
		auto getMaxTextureSamplers() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of compute bindings.</returns>
		[[nodiscard]]
		auto getMaxComputeBindings() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of vertex format layouts.</returns>
		[[nodiscard]]
		auto getMaxVertexLayouts() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of vertex streams.</returns>
		[[nodiscard]]
		auto getMaxVertexStreams() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of index buffer handles.</returns>
		[[nodiscard]]
		auto getMaxIndexBuffers() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of vertex buffer handles.</returns>
		[[nodiscard]]
		auto getMaxVertexBuffers() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of dynamic index buffer handles.</returns>
		[[nodiscard]]
		auto getMaxDynamicIndexBuffers() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of dynamic vertex buffer handles.</returns>
		[[nodiscard]]
		auto getMaxDynamicVertexBuffers() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of uniform handles.</returns>
		[[nodiscard]]
		auto getMaxUniforms() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of occlusion query handles.</returns>
		[[nodiscard]]
		auto getMaxOcclusionQueries() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum number of encoder threads.</returns>
		[[nodiscard]]
		auto getMaxEncoders() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Minimum resource command buffer size.</returns>
		[[nodiscard]]
		auto getMinResourceCommandBufferSize() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum transient vertex buffer size.</returns>
		[[nodiscard]]
		auto getMaxTransientVertexBufferSize() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Maximum transient index buffer size.</returns>
		[[nodiscard]]
		auto getMaxTransientIndexBufferSize() const noexcept -> std::uint32_t;

	private:
		std::uint32_t maxDrawCalls = 0;            // Maximum number of draw calls.
		std::uint32_t maxBlitCalls = 0;            // Maximum number of blit calls.
		std::uint32_t maxTextureSize = 0;          // Maximum texture size.
		std::uint32_t maxTextureLayers = 0;        // Maximum texture layers.
		std::uint32_t maxViews = 0;                // Maximum number of views.
		std::uint32_t maxFrameBuffers = 0;         // Maximum number of frame buffer handles.
		std::uint32_t maxFbAttachments = 0;        // Maximum number of frame buffer attachments.
		std::uint32_t maxPrograms = 0;             // Maximum number of program handles.
		std::uint32_t maxShaders = 0;              // Maximum number of shader handles.
		std::uint32_t maxTextures = 0;             // Maximum number of texture handles.
		std::uint32_t maxTextureSamplers = 0;      // Maximum number of texture samplers.
		std::uint32_t maxComputeBindings = 0;      // Maximum number of compute bindings.
		std::uint32_t maxVertexLayouts = 0;        // Maximum number of vertex format layouts.
		std::uint32_t maxVertexStreams = 0;        // Maximum number of vertex streams.
		std::uint32_t maxIndexBuffers = 0;         // Maximum number of index buffer handles.
		std::uint32_t maxVertexBuffers = 0;        // Maximum number of vertex buffer handles.
		std::uint32_t maxDynamicIndexBuffers = 0;  // Maximum number of dynamic index buffer handles.
		std::uint32_t maxDynamicVertexBuffers = 0; // Maximum number of dynamic vertex buffer handles.
		std::uint32_t maxUniforms = 0;             // Maximum number of uniform handles.
		std::uint32_t maxOcclusionQueries = 0;     // Maximum number of occlusion query handles.
		std::uint32_t maxEncoders = 0;             // Maximum number of encoder threads.
		std::uint32_t minResourceCbSize = 0;       // Minimum resource command buffer size.
		std::uint32_t maxTransientVbSize = 0;      // Maximum transient vertex buffer size.
		std::uint32_t maxTransientIbSize = 0;      // Maximum transient index buffer size.
	};

	/// <summary>
	/// Contains GPU info.
	/// TODO Add list with supported texture formats.
	/// </summary>
	class GpuInfoCollection final
	{
	public:
		/// <summary>
		///
		/// </summary>
		/// <returns>A list with all GPU devices the system has.</returns>
		[[nodiscard]]
		auto getDeviceList() const noexcept -> const std::vector<GpuDevice>&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The adapter limits of the main GPU used for rendering.</returns>
		[[nodiscard]]
		auto getAdapterLimits() const noexcept -> const GpuAdapterLimits&;

		/// <summary>
		/// Queries the data from the system.
		/// </summary>
		void query();

		/// <summary>
		/// 
		/// </summary>
		/// <returns>A formatted string, which contains all the data beautiful printed.</returns>
		[[nodiscard]]
		auto toStr() const -> std::string;

	private:
		std::vector<GpuDevice> allGpus;
		GpuAdapterLimits adapterLimits;
	};

	/// <summary>
	/// Contains info about the operating system and memory.
	/// </summary>
	class OsInfo final
	{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <returns>Available physical memory in Bytes.</returns>
		[[nodiscard]]
		auto getAvailablePhysicalMemory() const noexcept -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Total physical memory in Bytes.</returns>
		[[nodiscard]]
		auto getTotalPhysicalMemory() const noexcept -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Available virtual memory in bytes.</returns>
		[[nodiscard]]
		auto getAvailableVirtualMemory() const noexcept -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Total virtual memory in bytes.</returns>
		[[nodiscard]]
		auto getTotalVirtualMemory() const noexcept -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The version of the OS kernel.</returns>
		[[nodiscard]]
		auto getKernelVersion() const noexcept -> const std::uint32_t(&)[4];

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The short name of the OS.</returns>
		[[nodiscard]]
		auto getOsName() const noexcept -> const std::string&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The full name of the OS.</returns>
		[[nodiscard]]
		auto getOsNameFull() const noexcept -> const std::string&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The version of the OS.</returns>
		[[nodiscard]]
		auto getOsVersion() const noexcept -> const std::uint32_t(&)[4];

		/// <summary>
		/// Queries the data from the system.
		/// </summary>
		void query();

		/// <summary>
		/// 
		/// </summary>
		/// <returns>A formatted string, which contains all the data beautiful printed.</returns>
		[[nodiscard]]
		auto toStr() const -> std::string;

	private:
		std::size_t physicalAvailableMemory = 0;
		std::size_t physicalTotalMemory = 0;
		std::size_t virtualAvailableMemory = 0;
		std::size_t virtualTotalMemory = 0;
		std::uint32_t kernelVersion[4] = {};
		std::string osName = {};
		std::string osNameFull = {};
		std::uint32_t osVersion[4] = {};
	};

	/// <summary>
	/// Represents a monitor/TV/display.
	/// </summary>
	class DisplayInfo final
	{
		friend class PeripheryInfo;
	public:

		/// <summary>
		///
		/// </summary>
		/// <returns>Width in pixels.</returns>
		[[nodiscard]]
		auto getWidth() const noexcept -> std::uint16_t; //TODO Replace with Resolution

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Height in pixels.</returns>
		[[nodiscard]]
		auto getHeight() const noexcept -> std::uint16_t; //TODO Replace with Resolution

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Dots per inch.</returns>
		[[nodiscard]]
		auto getDpi() const noexcept -> std::uint16_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Bits per pixel (depth).</returns>
		[[nodiscard]]
		auto getBpp() const noexcept -> std::uint16_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Refresh rate in Herz.</returns>
		[[nodiscard]]
		auto getRefreshRate() const noexcept -> double;

	private:
		std::uint16_t width = 0;
		std::uint16_t height = 0;
		std::uint16_t dpi = 0;
		std::uint16_t bpp = 0;
		double refreshRate = .0;
	};

	class PeripheryInfo final
	{
	public:
		/// <summary>
		///
		/// </summary>
		/// <returns>A list with all displays connected.</returns>
		[[nodiscard]]
		auto getDisplayList() const noexcept -> const std::vector<DisplayInfo>&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The number of connected mice.</returns>
		[[nodiscard]]
		auto getMouseAmount() const noexcept -> std::uint8_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The number of connected keyboards. !! Will always return 0 on Linux - it canot be detected there !!</returns>
		[[nodiscard]]
		auto getKeyboardAmount() const noexcept -> std::uint8_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The number of other human interface devices. !! Will always return 0 on Linux - it canot be detected there !!</returns>
		[[nodiscard]]
		auto getOtherHidAmount() const noexcept -> std::uint8_t;

		/// <summary>
		/// Queries the data from the system.
		/// </summary>
		void query();

		/// <summary>
		/// 
		/// </summary>
		/// <returns>A formatted string, which contains all the data beautiful printed.</returns>
		[[nodiscard]]
		auto toStr() const -> std::string;

	private:
		std::vector<DisplayInfo> displays = {};
		std::uint8_t mouseAmount = 0;
		std::uint8_t keyboarsAmount = 0;
		std::uint8_t otherHidAmount = 0;
	};

	/// <summary>
	/// Contains information about the current platform, operating system and hardware.
	/// </summary>
	class PlatformDiagnostics final
	{
	public:
		/// <summary>
		///
		/// </summary>
		/// <returns>Information about the CPU (Central Processing Unit -> Processor).</returns>
		[[nodiscard]]
		auto getCpu() const noexcept -> const CpuInfo&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Information about the GPU (Graphics Processing Unit -> Graphics Card).</returns>
		[[nodiscard]]
		auto getGpu() const noexcept -> const GpuInfoCollection&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Information about the OS (Operating System).</returns>
		[[nodiscard]]
		auto getOs() const noexcept -> const OsInfo&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Information about periphery and HID (Human Interface Devices) like mouse and keyboard.</returns>
		[[nodiscard]]
		auto getPeriphery() const noexcept -> const PeripheryInfo&;

	private:
		CpuInfo cpuInfo;
		GpuInfoCollection gpuInfos;
		OsInfo osInfo;
		PeripheryInfo peripheryInfo;
	};
}
