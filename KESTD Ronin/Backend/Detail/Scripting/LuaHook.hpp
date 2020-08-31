// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// LuaHook.hpp
// 31.08.2020 03:29
// =============================================================

#pragma once

#include "../../Frontend/Export/KESTD/Logger.hpp"
#include <lua.hpp>
#include <optional>
#include <filesystem>

namespace kestd::detail::scripting
{
	class LuaHook final
	{
	public:
		LuaHook(Logger& logger);
		LuaHook(const LuaHook&) = delete;
		LuaHook(LuaHook&&) = delete;
		LuaHook& operator=(const LuaHook&) = delete;
		LuaHook& operator=(LuaHook&&) = delete;
		~LuaHook();

		/// <summary>
		/// Executes a script from string.
		/// </summary>
		[[nodiscard]]
		auto executeScript(std::string_view script) const -> bool;

		/// <summary>
		/// Executes a script file.
		/// </summary>
		[[nodiscard]]
		auto executeScriptFile(const std::filesystem::path& file) const -> bool;

		/// <summary>
		/// Fetch a single scalar float from the lua stack.
		/// </summary>
		/// <param name="identifier"></param>
		/// <returns>The scalar if present.</returns>
		[[nodiscard]]
		auto fetchScalar(std::string_view identifier) const -> std::optional<float>;

	private:
		Logger& proto;
		lua_State* luaState;
	};
}
