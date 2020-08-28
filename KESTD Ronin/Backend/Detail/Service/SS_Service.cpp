// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// SS_Service.cpp
// 27.08.2020 12:31
// =============================================================

#include "SS_Service.hpp"
#include "../../../Frontend/Environment.hpp"
#include <fmt/core.h>

namespace kestd::detail::service
{
	ServiceSystem::ServiceSystem(Environment& env) : ISubsystem("ServiceSystem",
	                                                            true,
	                                                            kernel::Event::Exhaustive)
	{
		auto& protocol = env.getProtocol();

		protocol.log(MessageType::Info, "Verifying working dir \"{}\"...", std::filesystem::current_path().string());

		// Verify all system directories:
		for (const auto& dir : env.getBootConfig().io.systemDirs)
		{
			if (is_directory(dir))
			{
				protocol.log(MessageType::Success, "[SysDir] {}", dir.string());
			}
			else
			{
				throw std::runtime_error("Required system directory not found: " + dir.string());
			}
		}

		// Verify all custom directories:
		for (const auto& dir : env.getBootConfig().io.additionalRequiredDirectories)
		{
			if (is_directory(dir))
			{
				protocol.log(MessageType::Success, "[UsrDir] {}", dir.string());
			}
			else
			{
				throw std::runtime_error("Additional user required directory not found: " + dir.string());
			}
		}

		// Perform system analysis and dump it into the protocol:
		protocol.log(MessageType::Info, "Performing system analysis...");
		auto& platformInfo = const_cast<PlatformInfo &>(env.getPlatformInfo());

		platformInfo.osInfo.query();
		protocol.logDump(platformInfo.osInfo.toStr());

		platformInfo.cpuInfo.query();
		protocol.logDump(platformInfo.cpuInfo.toStr());

		platformInfo.gpuInfos.query();
		protocol.logDump(platformInfo.gpuInfos.toStr());

		platformInfo.peripheryInfo.query();
		protocol.logDump(platformInfo.peripheryInfo.toStr());
	}

	ServiceSystem::~ServiceSystem() = default;

	auto ServiceSystem::onStartup(Environment& env) -> bool
	{
		return true;
	}

	auto ServiceSystem::onPrepare(Environment& env) -> bool
	{
		auto& proto = env.getProtocol();
		proto.log(MessageType::Trace, "Compressing protocol... Streamcapacity: {}, Length: {}",
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
