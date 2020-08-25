// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// OsInfo.cpp
// 09.08.2020 07:24
// =============================================================

#include "OsInfo.hpp"
#include "Logger.hpp"
#include <infoware/infoware.hpp>
#include <fmt/core.h>

namespace kestd
{
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
		architecture = static_cast<enum Architecture>(iware::cpu::architecture());
		const auto l1 = iware::cpu::cache(1);
		const auto l2 = iware::cpu::cache(2);
		const auto l3 = iware::cpu::cache(3);
		caches[0] =
		{
			l1.size,
			l1.line_size,
			l1.associativity,
			static_cast<CacheType>(l1.type)
		};
		caches[1] =
		{
			l2.size,
			l2.line_size,
			l2.associativity,
			static_cast<CacheType>(l2.type)
		};
		caches[2] =
		{
			l3.size,
			l3.line_size,
			l3.associativity,
			static_cast<CacheType>(l3.type)
		};
		endianness = static_cast<enum Endianness>(iware::cpu::endianness());
		const auto instr = iware::cpu::supported_instruction_sets();
		supportedInstructionSets.reserve(instr.size());
		for (const auto set : instr)
		{
			supportedInstructionSets.push_back(static_cast<InstructionSet>(set));
		}
	}

	auto CpuInfo::toStr() -> std::string
	{
		constexpr auto HZ2GHZ = 1000.f * 1000.f * 1000.f;
		constexpr auto B2MB = 1000.f * 1000.f;
		
		return fmt::format
		(
			"--------CPU--------\n"
			"LogicalCores: {}\n"
			"PhysicalCores: {}\n"
			"Sockets: {}\n"
			"BaseFreqeuncy: {}Hz -> {}Ghz\n"
			"Vendor: {}\n"
			"VendorID: {}\n"
			"ModelName: {}\n"
			"Architecture: {}\n"
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
			"\tSize: {}B -> {}MB\n",
			logical,
			physical,
			sockets,
			frequency,
			frequency / HZ2GHZ,
			vendor,
			vendorId,
			modelName,
			architecture,
			caches[0].type,
			caches[0].associativity,
			caches[0].lineSize,
			caches[0].size,
			caches[0].size / B2MB,
			caches[1].type,
			caches[1].associativity,
			caches[1].lineSize,
			caches[1].size,
			caches[1].size / B2MB,
			caches[2].type,
			caches[2].associativity,
			caches[2].lineSize,
			caches[2].size,
			caches[2].size / B2MB
		);
	}

	void GpuInfoCollection::query()
	{
		const auto info = iware::gpu::device_properties();
		allGpus.reserve(info.size());
		for (const auto& gpu : info)
		{
			allGpus.emplace_back(
				GpuInfo
				{
					static_cast<Vendor>(gpu.vendor),
					gpu.name,
					gpu.memory_size,
					gpu.cache_size,
					gpu.max_frequency,
				});
		}
	}

	auto GpuInfoCollection::toStr() -> std::string
	{
		constexpr auto B2MB = 1024.f * 1024.f;
		constexpr auto B2GB = 1024.f * 1024.f * 1024.f;
		constexpr auto HZ2GHZ = 1000.f * 1000.f * 1000.f;
		
		std::string ret = {};
		for (std::size_t i = 0; i < allGpus.size(); ++i)
		{
			const auto& gpu = allGpus[i];
			ret += fmt::format
			(
				"--------GPU{}--------\n"
				"Vendor: {}\n"
				"Name: {}\n"
				"MemorySize(VRAM): {}B -> {}MB -> {}GB\n"
				"CacheSize: {}B -> {}MB -> {}GB\n"
				"MaxFrequency: {}Hz -> {}Ghz\n",
				i,
				gpu.vendor,
				gpu.name,
				gpu.memorySize,
				gpu.memorySize / B2MB,
				gpu.memorySize / B2GB,
				gpu.cacheSize,
				gpu.cacheSize / B2MB,
				gpu.cacheSize / B2GB,
				gpu.maxFrequency,
				gpu.maxFrequency / HZ2GHZ
			);
		}
		return ret;
	}

	void OsInfo::query()
	{
		const auto mem = iware::system::memory();
		memory.physicalAvailable = mem.physical_available;
		memory.physicalTotal = mem.physical_total;
		memory.virtualAvailable = mem.virtual_available;
		memory.virtualTotal = mem.virtual_total;

		const auto ker = iware::system::kernel_info();
		kernel.major = ker.major;
		kernel.minor = ker.minor;
		kernel.build = ker.build_number;
		kernel.patch = ker.patch;

		auto osi = iware::system::OS_info();
		os.name = std::move(osi.name);
		os.fullName = std::move(osi.full_name);
		os.major = osi.major;
		os.minor = osi.minor;
		os.build = osi.build_number;
		os.patch = osi.patch;
	}

	auto OsInfo::toStr() -> std::string
	{
		constexpr auto B2MB = 1024.f * 1024.f;
		constexpr auto B2GB = 1024.f * 1024.f * 1024.f;
		
		return fmt::format
		(
			"--------OS--------\n"
			"Name: {}\n"
			"AvailablePhysicalMemory(RAM):\n\t{}B\n\t{}MB\n\t{}GB\n"
			"TotalPhysicalMemory(RAM):\n\t{}B\n\t{}MB\n\t{}GB\n"
			"AvailableVirtualMemory(RAM):\n\t{}B\n\t{}MB\n\t{}GB\n"
			"TotalVirtualMemory(RAM):\n\t{}B\n\t{}MB\n\t{}GB\n"
			"KernelVersion: {}.{}.{}.{}\n"
			"SystemVersion: {}.{}.{}.{}\n",
			os.fullName,
			memory.physicalAvailable,
			memory.physicalAvailable / B2MB,
			memory.physicalAvailable / B2GB,
			memory.physicalTotal,
			memory.physicalTotal / B2MB,
			memory.physicalTotal / B2GB,
			memory.virtualAvailable,
			memory.virtualAvailable / B2MB,
			memory.virtualAvailable / B2GB,
			memory.virtualTotal,
			memory.virtualAvailable / B2MB,
			memory.virtualAvailable / B2GB,
			kernel.major,
			kernel.minor,
			kernel.patch,
			kernel.build,
			os.major,
			os.minor,
			os.patch,
			os.build
		);
	}
}
