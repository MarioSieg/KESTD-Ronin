// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// SS_Service.cpp
// 27.08.2020 12:31
// =============================================================

#include "SS_Service.hpp"
#include "../../../Frontend/Environment.hpp"

namespace kestd::detail::service
{
	ServiceSystem::ServiceSystem(Environment& env) : ISubsystem("ServiceSystem",
	                                                            true,
	                                                            kernel::Event::Exhaustive)
	{
		auto& protocol = env.getProtocol();

		protocol.log(MessageType::Trace,
		             R"(Switching working dir from "{}" to "{}")",
		             std::filesystem::current_path().string(),
		             env.getBootConfig().getConfigForIo().getWorkingDir().string());
		current_path(env.getBootConfig().getConfigForIo().getWorkingDir());

		protocol.log(MessageType::Trace, "Verifying working dir...");

		// Verify all system directories:
		for (const auto& dir : env.getBootConfig().getConfigForIo().getRequiredDirectories())
		{
			if (is_directory(std::get<0>(dir)))
			{
				protocol.log(MessageType::Trace, "[DirOk] {}", std::get<0>(dir).string());
			}
			else
			{
				if (std::get<1>(dir) == DirectoryMissingAction::Create)
				{
					const auto ok = create_directory(std::get<0>(dir));
					protocol.log(MessageType::Warning, "Missing directory {}, created it? {}", ok);
				}
				else
				{
					throw std::runtime_error("Required directory not found: " + std::get<0>(dir).string());
				}
			}
		}

		// Perform system analysis and dump it into the protocol:
		protocol.log(MessageType::Trace, "Performing system analysis...");
		const auto& platformInfo = env.getPlatformDiagnostics();

		const_cast<OsInfo &>(platformInfo.getOs()).query();
		protocol.logDump(platformInfo.getOs().toStr());

		const_cast<CpuInfo &>(platformInfo.getCpu()).query();
		protocol.logDump(platformInfo.getCpu().toStr());

		const_cast<GpuInfoCollection &>(platformInfo.getGpu()).query();
		protocol.logDump(platformInfo.getGpu().toStr());

		const_cast<PeripheryInfo &>(platformInfo.getPeriphery()).query();
		protocol.logDump(platformInfo.getPeriphery().toStr());
	}

	ServiceSystem::~ServiceSystem() = default;

	auto ServiceSystem::onStartup(Environment& env) -> bool
	{
		return true;
	}

	auto ServiceSystem::onPrepare(Environment& env) -> bool
	{
		auto& proto = env.getProtocol();
		proto.log(MessageType::Trace,
		          "Compressing protocol... Streamcapacity: {}, Length: {}",
		          proto.getBuffer().capacity(),
		          proto.getBuffer().size());
		// Compress all logged messages to minimize memory usage:
		proto.compressMessages();
		return true;
	}

	auto ServiceSystem::onTick(Environment& env) -> bool
	{
		return true;
	}

	void ServiceSystem::onShutdown(Environment& env)
	{
		auto& proto = env.getProtocol();
		proto.flush();
	}
}
