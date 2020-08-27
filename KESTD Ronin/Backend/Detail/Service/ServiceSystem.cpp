// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// ServiceSystem.cpp
// 27.08.2020 12:31
// =============================================================

#include "ServiceSystem.hpp"
#include "../../../Frontend/Environment.hpp"
#include <fmt/core.h>

namespace kestd::detail::service
{
	ServiceSystem::ServiceSystem(const BootConfig& cfg) : ISubsystem("ServiceSystem",
	                                                                 true,
	                                                                 kernel::Event::OnStartup | kernel::Event::OnTick |
	                                                                 kernel::Event::OnShutdown)
	{
	}

	ServiceSystem::~ServiceSystem() = default;

	auto ServiceSystem::onStartup(Environment& env) -> bool
	{
		auto& protocol = env.getProtocol();
		auto& platformInfo = const_cast<PlatformInfo &>(env.getPlatformInfo());

		// Perform system analysis and dump it into the protocol:
		protocol << "Performing system analysis...";

		platformInfo.osInfo.query();
		protocol ^ platformInfo.osInfo.toStr();

		platformInfo.cpuInfo.query();
		protocol ^ platformInfo.cpuInfo.toStr();

		platformInfo.gpuInfos.query();
		protocol ^ platformInfo.gpuInfos.toStr();

		platformInfo.peripheryInfo.query();
		protocol ^ platformInfo.peripheryInfo.toStr();

		return true;
	}

	auto ServiceSystem::onPrepare(Environment& env) -> bool
	{
		auto& proto = env.getProtocol();
		proto >> fmt::format("Compressing protocol... Streamcapacity: {}, Length: {}",
		                     proto.getBuffer().capacity(),
		                     proto.getBuffer().size());
		// Compress all logged messages to minimize memory usage:
		proto.compressMessages();
		return true;
	}

	auto ServiceSystem::onTick(Environment&) -> bool
	{
		return true;
	}

	void ServiceSystem::onShutdown(Environment& env)
	{
		auto& proto = env.getProtocol();
		proto.flush();
		proto.clear();
	}
}
