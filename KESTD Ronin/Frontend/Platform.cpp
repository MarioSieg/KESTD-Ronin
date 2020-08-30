// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Platform.cpp
// 09.08.2020 07:24
// =============================================================

#include "Platform.hpp"
#include "BufLogger.hpp"
#include <infoware/infoware.hpp>
#include <fmt/core.h>
#include <bgfx/bgfx.h>

namespace kestd
{
	auto CpuCache::getSize() const noexcept -> std::size_t
	{
		return size;
	}

	auto CpuCache::getLineSize() const noexcept -> std::size_t
	{
		return lineSize;
	}

	auto CpuCache::getAssociativity() const noexcept -> std::size_t
	{
		return associativity;
	}

	auto CpuCache::getType() const noexcept -> CpuCacheType
	{
		return type;
	}

	auto CpuInfo::getLogicalCores() const noexcept -> std::uint16_t
	{
		return logical;
	}

	auto CpuInfo::getPhysicalCores() const noexcept -> std::uint16_t
	{
		return physical;
	}

	auto CpuInfo::getSockets() const noexcept -> std::uint16_t
	{
		return sockets;
	}

	auto CpuInfo::getFrequency() const noexcept -> std::uint64_t
	{
		return frequency;
	}

	auto CpuInfo::getVendorName() const noexcept -> const std::string&
	{
		return vendor;
	}

	auto CpuInfo::getVendorID() const noexcept -> const std::string&
	{
		return vendorId;
	}

	auto CpuInfo::getModelName() const noexcept -> const std::string&
	{
		return modelName;
	}

	auto CpuInfo::getArchitecture() const noexcept -> CpuArchitecture
	{
		return architecture;
	}

	auto CpuInfo::getCaches() const noexcept -> const CpuCache(&)[3]
	{
		return caches;
	}

	auto CpuInfo::getEndianness() const noexcept -> CpuEndianness
	{
		return endianness;
	}

	auto CpuInfo::getSupportedInstructionSets() const noexcept -> const std::vector<CpuInstructionSet>&
	{
		return supportedInstructionSets;
	}

	void CpuInfo::query()
	{
		const auto quantities = iware::cpu::quantities();
		logical = quantities.logical;
		physical = quantities.physical;
		sockets = quantities.packages;
		frequency = iware::cpu::frequency();
		vendor = iware::cpu::vendor();
		vendorId = iware::cpu::vendor_id();
		modelName = iware::cpu::model_name();
		architecture = static_cast<enum CpuArchitecture>(iware::cpu::architecture());
		const iware::cpu::cache_t ncaches[3] = {iware::cpu::cache(1), iware::cpu::cache(2), iware::cpu::cache(3)};
		static_assert(sizeof ncaches / sizeof *ncaches == sizeof caches / sizeof*caches);
		for (std::size_t i = 0; i < sizeof ncaches / sizeof*ncaches; ++i)
		{
			caches[i].size = ncaches[i].size;
			caches[i].lineSize = ncaches[i].line_size;
			caches[i].associativity = ncaches[i].associativity;
			caches[i].type = static_cast<CpuCacheType>(ncaches[i].type);
		}
		endianness = static_cast<enum CpuEndianness>(iware::cpu::endianness());
		const auto instr = iware::cpu::supported_instruction_sets();
		supportedInstructionSets.reserve(instr.size());
		for (const auto set : instr)
		{
			supportedInstructionSets.push_back(static_cast<CpuInstructionSet>(set));
		}
	}

	auto CpuInfo::toStr() const -> std::string
	{
		constexpr auto HZ2GHZ = 1000.f * 1000.f * 1000.f;
		constexpr auto B2MB = 1000.f * 1000.f;
		auto ret = fmt::format(
			"--------CPU--------\n"
			"LogicalCores: {}\n"
			"PhysicalCores: {}\n"
			"Sockets: {}\n"
			"BaseFreqeuncy: {}Hz -> {}Ghz\n"
			"GpuVendor: {}\n"
			"VendorID: {}\n"
			"ModelName: {}\n"
			"CpuArchitecture: {}\n"
			"CpuEndianness: {}\n"
			"L0Cache:\n"
			"\tType: {}\n"
			"\tAssociativity: {}\n"
			"\tLineSize: {}B\n"
			"\tSize: {}B -> {}MB\n"
			"L1Cache:\n"
			"\tType: {}\n"
			"\tAssociativity: {}\n"
			"\tLineSize: {}B\n"
			"\tSize: {}B -> {}MB\n"
			"L2Cache:\n"
			"\tType: {}\n"
			"\tAssociativity: {}\n"
			"\tLineSize: {}B\n"
			"\tSize: {}B -> {}MB\n"
			"SupportedInstructionSets:\n",
			logical,
			physical,
			sockets,
			frequency,
			frequency / HZ2GHZ,
			vendor,
			vendorId,
			modelName,
			CpuArchitecureNames[static_cast<std::size_t>(architecture)],
			endianness == CpuEndianness::Big ? "Big" : "Little",
			CpuCacheNames[static_cast<std::size_t>(caches[0].type)],
			caches[0].associativity,
			caches[0].lineSize,
			caches[0].size,
			caches[0].size / B2MB,
			CpuCacheNames[static_cast<std::size_t>(caches[1].type)],
			caches[1].associativity,
			caches[1].lineSize,
			caches[1].size,
			caches[1].size / B2MB,
			CpuCacheNames[static_cast<std::size_t>(caches[2].type)],
			caches[2].associativity,
			caches[2].lineSize,
			caches[2].size,
			caches[2].size / B2MB
		);

		for (std::size_t i = 0; i < sizeof CpuInstructionSetNames / sizeof *CpuInstructionSetNames; ++i)
		{
			const auto arch = CpuInstructionSetNames[i];
			ret += fmt::format("\t{}: {}\n",
			                   arch,
			                   std::find(supportedInstructionSets.begin(),
			                             supportedInstructionSets.end(),
			                             static_cast<CpuInstructionSet>(i)) != supportedInstructionSets.end());
		}

		return ret;
	}

	auto GpuDevice::getVendor() const noexcept -> GpuVendor
	{
		return vendor;
	}

	auto GpuDevice::getModelName() const noexcept -> const std::string&
	{
		return name;
	}

	auto GpuDevice::getMemorySize() const noexcept -> std::size_t
	{
		return memorySize;
	}

	auto GpuDevice::getCacheSize() const noexcept -> std::size_t
	{
		return cacheSize;
	}

	auto GpuDevice::getMaxFrequency() const noexcept -> std::size_t
	{
		return maxFrequency;
	}

	auto GpuAdapterLimits::getMaxDrawCalls() const noexcept -> std::uint32_t
	{
		return maxDrawCalls;
	}

	auto GpuAdapterLimits::getMaxBlitCalls() const noexcept -> std::uint32_t
	{
		return maxBlitCalls;
	}

	auto GpuAdapterLimits::getMaxTextureSize() const noexcept -> std::uint32_t
	{
		return maxTextureSize;
	}

	auto GpuAdapterLimits::getMaxTextureLayers() const noexcept -> std::uint32_t
	{
		return maxTextureLayers;
	}

	auto GpuAdapterLimits::getMaxViews() const noexcept -> std::uint32_t
	{
		return maxViews;
	}

	auto GpuAdapterLimits::getMaxFrameBuffers() const noexcept -> std::uint32_t
	{
		return maxFrameBuffers;
	}

	auto GpuAdapterLimits::getMaxFrameBufferAttachments() const noexcept -> std::uint32_t
	{
		return maxFbAttachments;
	}

	auto GpuAdapterLimits::getMaxPrograms() const noexcept -> std::uint32_t
	{
		return maxPrograms;
	}

	auto GpuAdapterLimits::getMaxShaders() const noexcept -> std::uint32_t
	{
		return maxShaders;
	}

	auto GpuAdapterLimits::getMaxTextures() const noexcept -> std::uint32_t
	{
		return maxTextures;
	}

	auto GpuAdapterLimits::getMaxTextureSamplers() const noexcept -> std::uint32_t
	{
		return maxTextureSamplers;
	}

	auto GpuAdapterLimits::getMaxComputeBindings() const noexcept -> std::uint32_t
	{
		return maxComputeBindings;
	}

	auto GpuAdapterLimits::getMaxVertexLayouts() const noexcept -> std::uint32_t
	{
		return maxVertexLayouts;
	}

	auto GpuAdapterLimits::getMaxVertexStreams() const noexcept -> std::uint32_t
	{
		return maxVertexStreams;
	}

	auto GpuAdapterLimits::getMaxIndexBuffers() const noexcept -> std::uint32_t
	{
		return maxIndexBuffers;
	}

	auto GpuAdapterLimits::getMaxVertexBuffers() const noexcept -> std::uint32_t
	{
		return maxVertexBuffers;
	}

	auto GpuAdapterLimits::getMaxDynamicIndexBuffers() const noexcept -> std::uint32_t
	{
		return maxDynamicIndexBuffers;
	}

	auto GpuAdapterLimits::getMaxDynamicVertexBuffers() const noexcept -> std::uint32_t
	{
		return maxDynamicVertexBuffers;
	}

	auto GpuAdapterLimits::getMaxUniforms() const noexcept -> std::uint32_t
	{
		return maxUniforms;
	}

	auto GpuAdapterLimits::getMaxOcclusionQueries() const noexcept -> std::uint32_t
	{
		return maxOcclusionQueries;
	}

	auto GpuAdapterLimits::getMaxEncoders() const noexcept -> std::uint32_t
	{
		return maxEncoders;
	}

	auto GpuAdapterLimits::getMinResourceCommandBufferSize() const noexcept -> std::uint32_t
	{
		return minResourceCbSize;
	}

	auto GpuAdapterLimits::getMaxTransientVertexBufferSize() const noexcept -> std::uint32_t
	{
		return getMaxTransientVertexBufferSize();
	}

	auto GpuAdapterLimits::getMaxTransientIndexBufferSize() const noexcept -> std::uint32_t
	{
		return maxTransientIbSize;
	}

	auto GpuInfoCollection::getDeviceList() const noexcept -> const std::vector<GpuDevice>&
	{
		return allGpus;
	}

	auto GpuInfoCollection::getAdapterLimits() const noexcept -> const GpuAdapterLimits&
	{
		return adapterLimits;
	}

	void GpuInfoCollection::query()
	{
		const auto info = iware::gpu::device_properties();
		const auto* adapter = bgfx::getCaps();

		static_assert(sizeof(GpuAdapterLimits) == sizeof(bgfx::Caps::Limits));

		memcpy(&adapterLimits, &adapter->limits, sizeof(GpuAdapterLimits));

		allGpus.reserve(info.size());
		for (auto& gpu : info)
		{
			GpuDevice ginfo;
			ginfo.vendor = static_cast<GpuVendor>(gpu.vendor);
			ginfo.name = std::move(gpu.name);
			ginfo.memorySize = gpu.memory_size;
			ginfo.cacheSize = gpu.cache_size;
			ginfo.maxFrequency = gpu.max_frequency;
			allGpus.emplace_back(std::move(ginfo));
		}
	}

	auto GpuInfoCollection::toStr() const -> std::string
	{
		constexpr auto B2MB = 1024.f * 1024.f;
		constexpr auto B2GB = 1024.f * 1024.f * 1024.f;
		constexpr auto HZ2GHZ = 1000.f * 1000.f * 1000.f;

		std::string ret;
		ret.reserve(128);
		for (std::size_t i = 0; i < allGpus.size(); ++i)
		{
			const auto& gpu = allGpus[i];
			ret += fmt::format(
				"--------GPU{}--------\n"
				"GpuVendor: {}\n"
				"Name: {}\n"
				"MemorySize(VRAM): {}B -> {}MB ~ {}GB\n"
				"CacheSize: {}B -> {}MB ~ {}GB\n"
				"MaxFrequency: {}Hz -> {}Ghz\n",
				i,
				GpuVendorNames[static_cast<std::size_t>(gpu.vendor)],
				gpu.name,
				gpu.memorySize,
				gpu.memorySize / B2MB,
				std::ceil(gpu.memorySize / B2GB),
				gpu.cacheSize,
				gpu.cacheSize / B2MB,
				std::ceil(gpu.cacheSize / B2GB),
				gpu.maxFrequency,
				gpu.maxFrequency / HZ2GHZ
			);
		}
		ret += fmt::format(
			"--------GPU Adapter--------\n"
			"MaxDrawCalls: {}\n"
			"MaxBlitCalls: {}\n"
			"MaxTextureSize: {}\n"
			"MaxTextureLayers: {}\n"
			"MaxViews: {}\n"
			"MaxFrameBuffers: {}\n"
			"MaxFrameBufferAttachments: {}\n"
			"MaxPrograms: {}\n"
			"MaxShaders: {}\n"
			"MaxTextures: {}\n"
			"MaxTextureSamplers: {}\n"
			"MaxComputeBindings: {}\n"
			"MaxVerteyLayouts: {}\n"
			"MaxVertexStreams: {}\n"
			"MaxIndexBuffers: {}\n"
			"MaxVertexBuffers: {}\n"
			"MaxDynamicIndexBuffers: {}\n"
			"MaxDynamicVertexBuffers: {}\n"
			"MaxUniforms: {}\n"
			"MaxOcclusionQueries: {}\n"
			"MaxEncoders: {}\n"
			"MinResourceCommandBufferSize: {}\n"
			"MaxTransientVertexBufferSize: {}\n"
			"MaxTransientIndexBufferSize: {}\n",
			adapterLimits.maxDrawCalls,
			adapterLimits.maxBlitCalls,
			adapterLimits.maxTextureSize,
			adapterLimits.maxTextureLayers,
			adapterLimits.maxViews,
			adapterLimits.maxFrameBuffers,
			adapterLimits.maxFbAttachments,
			adapterLimits.maxPrograms,
			adapterLimits.maxShaders,
			adapterLimits.maxTextures,
			adapterLimits.maxTextureSamplers,
			adapterLimits.maxComputeBindings,
			adapterLimits.maxVertexLayouts,
			adapterLimits.maxVertexStreams,
			adapterLimits.maxIndexBuffers,
			adapterLimits.maxVertexBuffers,
			adapterLimits.maxDynamicIndexBuffers,
			adapterLimits.maxDynamicVertexBuffers,
			adapterLimits.maxUniforms,
			adapterLimits.maxOcclusionQueries,
			adapterLimits.maxEncoders,
			adapterLimits.minResourceCbSize,
			adapterLimits.maxTransientVbSize,
			adapterLimits.maxTransientIbSize
		);
		return ret;
	}

	auto OsInfo::getAvailablePhysicalMemory() const noexcept -> std::size_t
	{
		return physicalAvailableMemory;
	}

	auto OsInfo::getTotalPhysicalMemory() const noexcept -> std::size_t
	{
		return physicalTotalMemory;
	}

	auto OsInfo::getAvailableVirtualMemory() const noexcept -> std::size_t
	{
		return virtualAvailableMemory;
	}

	auto OsInfo::getTotalVirtualMemory() const noexcept -> std::size_t
	{
		return virtualTotalMemory;
	}

	auto OsInfo::getKernelVersion() const noexcept -> const std::uint32_t(&)[4]
	{
		return kernelVersion;
	}

	auto OsInfo::getOsName() const noexcept -> const std::string&
	{
		return osName;
	}

	auto OsInfo::getOsNameFull() const noexcept -> const std::string&
	{
		return osNameFull;
	}

	auto OsInfo::getOsVersion() const noexcept -> const std::uint32_t(&)[4]
	{
		return osVersion;
	}

	auto DisplayInfo::getWidth() const noexcept -> std::uint16_t
	{
		return width;
	}

	auto DisplayInfo::getHeight() const noexcept -> std::uint16_t
	{
		return height;
	}

	auto DisplayInfo::getDpi() const noexcept -> std::uint16_t
	{
		return dpi;
	}

	auto DisplayInfo::getBpp() const noexcept -> std::uint16_t
	{
		return bpp;
	}

	auto DisplayInfo::getRefreshRate() const noexcept -> double
	{
		return refreshRate;
	}

	void OsInfo::query()
	{
		const auto mem = iware::system::memory();
		physicalAvailableMemory = mem.physical_available;
		physicalTotalMemory = mem.physical_total;
		virtualAvailableMemory = mem.virtual_available;
		virtualTotalMemory = mem.virtual_total;

		const auto ker = iware::system::kernel_info();
		kernelVersion[0] = ker.major;
		kernelVersion[1] = ker.minor;
		kernelVersion[2] = ker.build_number;
		kernelVersion[3] = ker.patch;

		auto osi = iware::system::OS_info();
		osName = std::move(osi.name);
		osNameFull = std::move(osi.full_name);
		osVersion[0] = osi.major;
		osVersion[1] = osi.minor;
		osVersion[2] = osi.build_number;
		osVersion[3] = osi.patch;
	}

	auto OsInfo::toStr() const -> std::string
	{
		constexpr auto B2MB = 1024.f * 1024.f;
		constexpr auto B2GB = 1024.f * 1024.f * 1024.f;

		return fmt::format(
			"--------OS--------\n"
			"Name: {}\n"
			"AvailablePhysicalMemory(RAM):\n\t{}B\n\t{}MB\n\t~{}GB\n"
			"TotalPhysicalMemory(RAM):\n\t{}B\n\t{}MB\n\t~{}GB\n"
			"AvailableVirtualMemory(RAM):\n\t{}B\n\t{}MB\n\t~{}GB\n"
			"TotalVirtualMemory(RAM):\n\t{}B\n\t{}MB\n\t~{}GB\n"
			"KernelVersion: {}.{}.{}.{}\n"
			"SystemVersion: {}.{}.{}.{}\n",
			osNameFull,
			physicalAvailableMemory,
			physicalAvailableMemory / B2MB,
			std::ceil(physicalAvailableMemory / B2GB),
			physicalTotalMemory,
			physicalTotalMemory / B2MB,
			std::ceil(physicalTotalMemory / B2GB),
			virtualAvailableMemory,
			virtualAvailableMemory / B2MB,
			std::ceil(virtualAvailableMemory / B2GB),
			virtualTotalMemory,
			virtualAvailableMemory / B2MB,
			std::ceil(virtualAvailableMemory / B2GB),
			kernelVersion[0],
			kernelVersion[1],
			kernelVersion[2],
			kernelVersion[3],
			osVersion[0],
			osVersion[1],
			osVersion[2],
			osVersion[3]
		);
	}

	auto PeripheryInfo::getDisplayList() const noexcept -> const std::vector<DisplayInfo>&
	{
		return displays;
	}

	auto PeripheryInfo::getMouseAmount() const noexcept -> std::uint8_t
	{
		return mouseAmount;
	}

	auto PeripheryInfo::getKeyboardAmount() const noexcept -> std::uint8_t
	{
		return keyboarsAmount;
	}

	auto PeripheryInfo::getOtherHidAmount() const noexcept -> std::uint8_t
	{
		return otherHidAmount;
	}

	void PeripheryInfo::query()
	{
		const auto dis = iware::system::displays();

		for (const auto& d : dis)
		{
			DisplayInfo di;
			di.width = static_cast<std::uint16_t>(d.width);
			di.height = static_cast<std::uint16_t>(d.height);
			di.dpi = static_cast<std::uint16_t>(d.dpi);
			di.bpp = static_cast<std::uint16_t>(d.bpp);
			di.refreshRate = d.refresh_rate;
			displays.emplace_back(di);
		}

		mouseAmount = iware::system::mouse_amount();
		keyboarsAmount = iware::system::keyboard_amount();
		otherHidAmount = iware::system::other_HID_amount();
	}

	auto PeripheryInfo::toStr() const -> std::string
	{
		std::string ret;
		ret.reserve(128);
		for (std::size_t i = 0; i < displays.size(); ++i)
		{
			const auto& dis = displays[i];
			ret += fmt::format(
				"--------DISPLAY{}--------\n"
				"Width: {}\n"
				"Height: {}\n"
				"DPI: {}\n"
				"BPP: {}\n"
				"RefreshRate: {}\n",
				i,
				dis.width,
				dis.height,
				dis.dpi,
				dis.bpp,
				dis.refreshRate
			);
		}
		return ret;
	}

	auto PlatformDiagnostics::getCpu() const noexcept -> const CpuInfo&
	{
		return cpuInfo;
	}

	auto PlatformDiagnostics::getGpu() const noexcept -> const GpuInfoCollection&
	{
		return gpuInfos;
	}

	auto PlatformDiagnostics::getOs() const noexcept -> const OsInfo&
	{
		return osInfo;
	}

	auto PlatformDiagnostics::getPeriphery() const noexcept -> const PeripheryInfo&
	{
		return peripheryInfo;
	}
}
