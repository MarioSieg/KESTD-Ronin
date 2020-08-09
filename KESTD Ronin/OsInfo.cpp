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
		Logical = quantities.logical;
		Physical = quantities.physical;
		Sockets = quantities.packages;
		Frequency = iware::cpu::frequency();
		Vendor = iware::cpu::vendor();
		VendorId = iware::cpu::vendor_id();
		ModelName = iware::cpu::model_name();
		Architecture = static_cast<enum class Architecture>(iware::cpu::architecture());
		const auto l1 = iware::cpu::cache(1);
		const auto l2 = iware::cpu::cache(2);
		const auto l3 = iware::cpu::cache(3);
		Caches[0] =
		{
			l1.size,
			l1.line_size,
			l1.associativity,
			static_cast<CacheType>(l1.type)
		};
		Caches[1] =
		{
			l2.size,
			l2.line_size,
			l2.associativity,
			static_cast<CacheType>(l2.type)
		};
		Caches[2] =
		{
			l3.size,
			l3.line_size,
			l3.associativity,
			static_cast<CacheType>(l3.type)
		};
		Endianness = static_cast<enum class Endianness>(iware::cpu::endianness());
		const auto instr = iware::cpu::supported_instruction_sets();
		SupportedInstructionSets.reserve(instr.size());
		for (const auto set : instr)
		{
			SupportedInstructionSets.push_back(static_cast<InstructionSet>(set));
		}
	}

	auto operator <<(Logger& out, const CpuInfo& info) -> Logger&
	{
		out << "Logical: " + std::to_string(info.Logical);
		out << "Physical: " + std::to_string(info.Physical);
		out << "Sockets: " + std::to_string(info.Sockets);
		out << "Freq: " + std::to_string(info.Frequency);
		out << "Vendor: " + info.Vendor;
		out << "VendorID: " + info.VendorId;
		out << "ModelName: " + info.ModelName;
		out << "Arch: " + std::to_string(static_cast<int>(info.Architecture));
		for (auto i = 0; i < 3; ++i)
		{
			const auto& cache = info.Caches[i];
			out << "L" + std::to_string(i) + " Cache";
			out << "Size: " + std::to_string(cache.Size);
			out << "LineSize: " + std::to_string(cache.LineSize);
			out << "Associativity: " + std::to_string(cache.Associativity);
			out << "Type: " + std::to_string(static_cast<int>(cache.Type));
		}
		out << "Endianness: " + std::to_string(static_cast<int>(info.Endianness));
		return out;
	}

	void GpuInfoCollection::query()
	{
		const auto info = iware::gpu::device_properties();
		AllGpus.reserve(info.size());
		for (const auto& gpu : info)
		{
			AllGpus.emplace_back(
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
		out << "GPUs: " + std::to_string(info.AllGpus.size());
		for (std::size_t i = 0; i < info.AllGpus.size(); ++i)
		{
			const auto& gpu = info.AllGpus[i];
			out << "GPU: " + std::to_string(i);
			out << "Vendor: " + std::to_string(static_cast<int>(gpu.Vendor));
			out << "Name: " + gpu.Name;
			out << "MemorySize: " + std::to_string(gpu.MemorySize);
			out << "CacheSize: " + std::to_string(gpu.CacheSize);
			out << "MaxFrequency: " + std::to_string(gpu.MaxFrequency);
		}
		return out;
	}

	void OsInfo::query()
	{
		const auto mem = iware::system::memory();
		Memory.PhysicalAvailable = mem.physical_available;
		Memory.PhysicalTotal = mem.physical_total;
		Memory.VirtualAvailable = mem.virtual_available;
		Memory.VirtualTotal = mem.virtual_total;

		const auto kernel = iware::system::kernel_info();
		Kernel.Major = kernel.major;
		Kernel.Minor = kernel.minor;
		Kernel.Build = kernel.build_number;
		Kernel.Patch = kernel.patch;

		auto os = iware::system::OS_info();
		Os.Name = std::move(os.name);
		Os.FullName = std::move(os.name);
		Os.Major = os.major;
		Os.Minor = os.minor;
		Os.Build = os.build_number;
		Os.Patch = os.patch;
	}

	auto operator <<(Logger& out, const OsInfo& info) -> Logger&
	{
		out << "Name: " + info.Os.Name;
		out << "PhysicalAvailableMemory: " + std::to_string(info.Memory.PhysicalAvailable);
		out << "PhysicalTotalMemory: " + std::to_string(info.Memory.PhysicalTotal);
		out << "VirtualAvailableMemory: " + std::to_string(info.Memory.VirtualAvailable);
		out << "VirtualTotalMemory: " + std::to_string(info.Memory.VirtualTotal);
		out << "KernelMajor: " + std::to_string(info.Kernel.Major);
		out << "KernelMinor: " + std::to_string(info.Kernel.Minor);
		out << "KernelPatch: " + std::to_string(info.Kernel.Patch);
		out << "KernelBuild: " + std::to_string(info.Kernel.Build);
		out << "OSMajor: " + std::to_string(info.Os.Major);
		out << "OSMinor: " + std::to_string(info.Os.Minor);
		out << "OSPatch: " + std::to_string(info.Os.Patch);
		out << "OSBuild: " + std::to_string(info.Os.Build);
		return out;
	}
}
