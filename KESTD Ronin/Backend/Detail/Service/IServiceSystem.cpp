// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// IServiceSystem.cpp
// 31.08.2020 15:09
// =============================================================

#include "IServiceSystem.hpp"
#include "../../../Frontend/Export/KESTD/Environment.hpp"

#define STR "[Service] "

namespace kestd::detail::service
{
	IServiceSystem::IServiceSystem(Environment& env) : ISubsystem("IServiceSystem",
	                                                              true,
	                                                              kernel::Event::Exhaustive)
	{
		auto& proto = env.getProtocol();

		proto.info(
			STR R"(Switching working dir from "{}" to "{}")",
			std::filesystem::current_path().string(),
			env.getBootConfig().getConfigForIo().getWorkingDir().string());
		current_path(env.getBootConfig().getConfigForIo().getWorkingDir());

		proto.info(STR "Verifying working dir...");

		// Verify all system directories:
		for (const auto& dir : env.getBootConfig().getConfigForIo().getRequiredDirectories())
		{
			if (is_directory(std::get<0>(dir)))
			{
				proto.info(STR "[DirOk] {}", std::get<0>(dir).string());
			}
			else
			{
				if (std::get<1>(dir) == DirectoryMissingAction::Create)
				{
					const auto ok = create_directory(std::get<0>(dir));
					proto.warning(STR "Missing directory {}, created it? {}", ok, std::get<0>(dir).string>());
				}
				else
				{
					throw std::runtime_error(STR "Required directory not found: " + std::get<0>(dir).string());
				}
			}
		}

		// Perform system analysis and dump it into the protocol:
		proto.info(STR "Performing system diagnostic...");
		const auto& platformInfo = env.getPlatformDiagnostics();

		const_cast<OsInfo &>(platformInfo.getOs()).query();
		proto.logDump(platformInfo.getOs().toStr());

		const_cast<CpuInfo &>(platformInfo.getCpu()).query();
		proto.logDump(platformInfo.getCpu().toStr());

		const_cast<GpuInfoCollection &>(platformInfo.getGpu()).query();
		proto.logDump(platformInfo.getGpu().toStr());

		const_cast<PeripheryInfo &>(platformInfo.getPeriphery()).query();
		proto.logDump(platformInfo.getPeriphery().toStr());
	}

	IServiceSystem::~IServiceSystem() = default;

	auto IServiceSystem::onStartup(Environment& env) -> bool
	{
		return true;
	}

	auto IServiceSystem::onPrepare(Environment& env) -> bool
	{
		auto& proto = env.getProtocol();
		proto.info(
			STR "Compressing protocol... Streamcapacity: {}, Length: {}",
			proto.getBuffer().capacity(),
			proto.getBuffer().size());
		// Compress all logged messages to minimize memory usage:
		proto.compressMessages();
		return true;
	}

	auto IServiceSystem::onTick(Environment& env) -> bool
	{
		return true;
	}

	void IServiceSystem::onShutdown(Environment& env)
	{
		auto& proto = env.getProtocol();
		proto.flush();
	}
}
