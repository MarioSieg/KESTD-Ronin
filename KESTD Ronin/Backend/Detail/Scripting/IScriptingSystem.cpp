// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// IScriptingSystem.cpp
// 31.08.2020 15:09
// =============================================================

#include "IScriptingSystem.hpp"

namespace kestd::detail::scripting
{
	IScriptingSystem::IScriptingSystem(Environment& env) : ISubsystem("IScriptingSystem", true)
	{
		auto& proto = env.getProtocol();
		proto.info("Initializing ScriptHook & LuaVM...");
		proto.separator();
		proto.logDump(luaHook.getOpcodeInfo());
		proto.separator();
		proto.logDump(luaHook.dumpOpcodes());
		proto.separator();
	}
}
