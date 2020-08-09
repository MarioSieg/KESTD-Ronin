// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// OsInfo.cpp
// 07.08.2020 12:53
// =============================================================

#include "OsInfo.hpp"
#include "Logger.hpp"
#include <infoware/infoware.hpp>

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
		architecture = static_cast<enum class Architecture>(iware::cpu::architecture());
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
		endianness = static_cast<enum class Endianness>(iware::cpu::endianness());
		const auto instr = iware::cpu::supported_instruction_sets();
		supportedInstructionSets.reserve(instr.size());
		for (const auto set : instr)
		{
			supportedInstructionSets.push_back(static_cast<InstructionSet>(set));
		}
	}

	auto operator <<(Logger& out, const CpuInfo& info) -> Logger&
	{
		out << "Logical: " + std::to_string(info.logical);
		out << "Physical: " + std::to_string(info.physical);
		out << "Sockets: " + std::to_string(info.sockets);
		out << "Freq: " + std::to_string(info.frequency);
		out << "Vendor: " + info.vendor;
		out << "VendorID: " + info.vendorId;
		out << "ModelName: " + info.modelName;
		out << "Arch: " + std::to_string(static_cast<int>(info.architecture));
		for (auto i = 0; i < 3; ++i)
		{
			const auto& cache = info.caches[i];
			out << "L" + std::to_string(i) + " Cache";
			out << "Size: " + std::to_string(cache.size);
			out << "LineSize: " + std::to_string(cache.lineSize);
			out << "Associativity: " + std::to_string(cache.associativity);
			out << "Type: " + std::to_string(static_cast<int>(cache.type));
		}
		out << "Endianness: " + std::to_string(static_cast<int>(info.endianness));
		return out;
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

	auto operator <<(Logger& out, const GpuInfoCollection& info) -> Logger&
	{
		out << "GPUs: " + std::to_string(info.allGpus.size());
		for (std::size_t i = 0; i < info.allGpus.size(); ++i)
		{
			const auto& gpu = info.allGpus[i];
			out << "GPU: " + std::to_string(i);
			out << "Vendor: " + std::to_string(static_cast<int>(gpu.vendor));
			out << "Name: " + gpu.name;
			out << "MemorySize: " + std::to_string(gpu.memorySize);
			out << "CacheSize: " + std::to_string(gpu.cacheSize);
			out << "MaxFrequency: " + std::to_string(gpu.maxFrequency);
		}
		return out;
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

	auto operator <<(Logger& out, const OsInfo& info) -> Logger&
	{
		out << "Name: " + info.os.name;
		out << "PhysicalAvailableMemory: " + std::to_string(info.memory.physicalAvailable);
		out << "PhysicalTotalMemory: " + std::to_string(info.memory.physicalTotal);
		out << "VirtualAvailableMemory: " + std::to_string(info.memory.virtualAvailable);
		out << "VirtualTotalMemory: " + std::to_string(info.memory.virtualTotal);
		out << "KernelMajor: " + std::to_string(info.kernel.major);
		out << "KernelMinor: " + std::to_string(info.kernel.minor);
		out << "KernelPatch: " + std::to_string(info.kernel.patch);
		out << "KernelBuild: " + std::to_string(info.kernel.build);
		out << "OSMajor: " + std::to_string(info.os.major);
		out << "OSMinor: " + std::to_string(info.os.minor);
		out << "OSPatch: " + std::to_string(info.os.patch);
		out << "OSBuild: " + std::to_string(info.os.build);
		return out;
	}
}
