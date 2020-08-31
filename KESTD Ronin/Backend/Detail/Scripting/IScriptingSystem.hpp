// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// IScriptingSystem.hpp
// 31.08.2020 15:09
// =============================================================

#pragma once

#include "../../Kernel/ISubsystem.hpp"
#include "LuaHook.hpp"

namespace kestd::detail::scripting
{
	class IScriptingSystem : public kernel::ISubsystem
	{
	public:
		IScriptingSystem(Environment& env);
		IScriptingSystem(const IScriptingSystem&) = delete;
		IScriptingSystem(IScriptingSystem&&) = delete;
		IScriptingSystem& operator=(const IScriptingSystem&) = delete;
		IScriptingSystem& operator=(IScriptingSystem&&) = delete;
		~IScriptingSystem() = default;

	private:
		LuaHook luaHook;
	};
}
