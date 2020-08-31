// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// IScriptingSystem.cpp
// 31.08.2020 02:38
// =============================================================

#include "IScriptingSystem.hpp"

namespace kestd::detail::scripting
{
	IScriptingSystem::IScriptingSystem(Environment& env) : ISubsystem("ScriptingSystem", true),
	                                                       luaHook(env.getProtocol())
	{
		luaHook.executeScript("a = 3 * 3");
		env.getProtocol().info("Value of a is: {}", luaHook.fetchScalar("a").value_or(.0f));
	}
}
