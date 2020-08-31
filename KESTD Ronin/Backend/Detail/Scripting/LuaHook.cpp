// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// LuaHook.cpp
// 31.08.2020 03:29
// =============================================================

#include "LuaHook.hpp"

#define STR "[ScriptHook] "

namespace kestd::detail::scripting
{
	LuaHook::LuaHook(Logger& logger) : proto(logger)
	{
		proto.info(STR "Initializing Script Hook & LuaVM...");
		luaState = luaL_newstate();
		luaL_openlibs(luaState);
	}

	LuaHook::~LuaHook()
	{
		lua_close(luaState);
	}

	auto LuaHook::executeScript(const std::string_view script) const -> bool
	{
		const int result = luaL_dostring(luaState, script.data());
		if (result != LUA_OK)
		{
			proto.error(STR "ScriptExecutionError: {}", lua_tostring(luaState, -1));
			return false;
		}
		return false;
	}

	auto LuaHook::executeScriptFile(const std::filesystem::path& file) const -> bool
	{
		const int result = luaL_dofile(luaState, file.string().c_str());
		if (result != LUA_OK)
		{
			proto.error(STR "ScriptExecutionError: {}", lua_tostring(luaState, -1));
			return false;
		}
		return false;
	}

	auto LuaHook::fetchScalar(const std::string_view identifier) const -> std::optional<float>
	{
		int result = lua_getglobal(luaState, identifier.data());
		if (result != LUA_OK)
		{
			proto.error(STR "GetGlobalError: {}", lua_tostring(luaState, -1));
			return std::nullopt;
		}
		result = lua_isnumber(luaState, -1);
		if (result != LUA_OK)
		{
			proto.error(STR "IsNumberError: {}", lua_tostring(luaState, -1));
			return std::nullopt;
		}
		return static_cast<float>(lua_tonumber(luaState, -1));
	}
}
