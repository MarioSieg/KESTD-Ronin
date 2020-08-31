// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// LuaHook.hpp
// 31.08.2020 15:09
// =============================================================

#pragma once

#include <lua.hpp>
#include <optional>
#include <filesystem>
#include <functional>

namespace kestd::detail::scripting
{
	class LuaHook final
	{
	public:
		LuaHook();
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

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Returns the number in the current stack.</returns>
		[[nodiscard]]
		auto getStackHeight() const noexcept -> int;

		/// <summary>
		/// Iterates over the stack and maps the callback procoedure to each element. i is the stack index.
		/// </summary>
		void traverseStack(const std::function<void(int)>& callback) const;

		/// <summary>
		/// Returns a string containg the formatted stack.
		/// </summary>
		[[nodiscard]]
		auto dumpStack() -> std::string;

		/// <summary>
		/// Returns a string containg all opcodes.
		/// </summary>
		[[nodiscard]]
		auto dumpOpcodes() -> std::string;

		/// <summary>
		/// Returns a short info avout opcode formats.
		/// </summary>
		[[nodiscard]]
		auto getOpcodeInfo() -> std::string;

	private:
		lua_State* state;
	};
}
