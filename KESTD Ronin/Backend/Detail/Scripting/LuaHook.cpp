// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// LuaHook.cpp
// 31.08.2020 15:09
// =============================================================

#include "LuaHook.hpp"
#include <sstream>
#include <fmt/core.h>

namespace kestd::detail::scripting
{
	LuaHook::LuaHook()
	{
		state = luaL_newstate();
		luaL_openlibs(state);
	}

	LuaHook::~LuaHook()
	{
		lua_close(state);
	}

	auto LuaHook::executeScript(const std::string_view script) const -> bool
	{
		return (luaL_loadstring(state, script.data()) || lua_pcallk(state, 0, -1, 0, 0, nullptr)) == LUA_OK;
	}

	auto LuaHook::executeScriptFile(const std::filesystem::path& file) const -> bool
	{
		return (luaL_loadfilex(state, file.string().c_str(), nullptr) || lua_pcallk(state, 0, -1, 0, 0, nullptr)) == LUA_OK;
	}

	auto LuaHook::fetchScalar(const std::string_view identifier) const -> std::optional<float>
	{
		auto result = lua_getglobal(state, identifier.data());
		if (result != LUA_OK)
		{
			return std::nullopt;
		}
		result = lua_isnumber(state, -1);
		if (result != LUA_OK)
		{
			return std::nullopt;
		}
		return static_cast<float>(lua_tonumberx(state, -1, nullptr));
	}

	auto LuaHook::getStackHeight() const noexcept -> int
	{
		return lua_gettop(state);
	}

	auto LuaHook::dumpStack() -> std::string
	{
		std::stringstream ss;
		auto callback = [this, &ss](const auto i)
		{
			const auto type = lua_type(state, i);
			const auto* const ltypename = lua_typename(state, type);
			switch (type)
			{
				case LUA_TSTRING:
					ss << lua_tostring(state, i);
					break;
				case LUA_TBOOLEAN:
					ss << (lua_toboolean(state, i) ? "true" : "false");
					break;
				case LUA_TNUMBER:
					ss << lua_tonumber(state, i);
					break;
				case LUA_TNIL:
					ss << "nil";
					break;
				default:
					ss << lua_topointer(state, i);
					break;
			}
		};
		traverseStack(callback);
		return ss.str();
	}

	void LuaHook::traverseStack(const std::function<void(int)>& callback) const
	{
		auto i = lua_gettop(state);
		while (i)
		{
			callback(i);
			--i;
		}
	}

	auto LuaHook::dumpOpcodes() -> std::string
	{
		// Copied from lopcodes.h:
		return
			"OP_MOVE A B R[A] := R[B]\n"
			"OP_LOADI A sBx	R[A] := sBx\n"
			"OP_LOADF A sBx	R[A] := (lua_Number)sBx\n"
			"OP_LOADK A Bx	R[A] := K[Bx]\n"
			"OP_LOADKX A	R[A] := K[extra arg]\n"
			"OP_LOADFALSE A	R[A] := false\n"
			"OP_LFALSESKIP A R[A] := false; pc++\n"
			"OP_LOADTRUE A R[A] := true\n"
			"OP_LOADNIL	A B	R[A] R[A+1] ... R[A+B] := nil\n"
			"OP_GETUPVAL A B R[A] := UpValue[B]\n"
			"OP_SETUPVAL A BUpValue[B] := R[A]\n\n"
			"OP_GETTABU	 A B C	R[A] := UpValue[B][K[C]:string]\n"
			"OP_GETTABLE A B C	R[A] := R[B][R[C]]\n"
			"OP_GETI A B C	R[A] := R[B][C]\n"
			"OP_GETFIELD A B C	R[A] := R[B][K[C]:string]\n\n"
			"OP_SETTABUP A B C	UpValue[A][K[B]:string] := RK(C)\n"
			"OP_SETTABLE A B C	R[A][R[B]] := RK(C)\n"
			"OP_SETI A B C	R[A][B] := RK(C)\n"
			"OP_SETFIELD A B C	R[A][K[B]:string] := RK(C)\n\n"
			"OP_NEWTABLE A B C k	R[A] := {}\n\n"
			"OP_SELF A B C	R[A+1] := R[B]; R[A] := R[B][RK(C):string]\n\n"
			"OP_ADDI A B sC	R[A] := R[B] + sC\n\n"
			"OP_ADDK A B C	R[A] := R[B] + K[C]\n"
			"OP_SUBK A B C	R[A] := R[B] - K[C]\n"
			"OP_MULK A B C	R[A] := R[B] * K[C]\n"
			"OP_MODK A B C	R[A] := R[B] % K[C]\n"
			"OP_POWK A B C	R[A] := R[B] ^ K[C]\n"
			"OP_DIVK A B C	R[A] := R[B] / K[C]\n"
			"OP_IDIVK A B C	R[A] := R[B] // K[C]\n\n"
			"OP_BANDK A B C	R[A] := R[B] & K[C]:integer\n"
			"OP_BORK A B C	R[A] := R[B] | K[C]:integer\n"
			"OP_BXORK A B C	R[A] := R[B] ~ K[C]:integer\n\n"
			"OP_SHRI A B sC	R[A] := R[B] >> sC\n"
			"OP_SHLI A B sC	R[A] := sC << R[B]\n\n"
			"OP_ADD	A B C R[A] := R[B] + R[C]\n"
			"OP_SUB	A B C R[A] := R[B] - R[C]\n"
			"OP_MUL	A B C R[A] := R[B] * R[C]\n"
			"OP_MOD	A B C R[A] := R[B] % R[C]\n"
			"OP_POW	A B C R[A] := R[B] ^ R[C]\n"
			"OP_DIV	A B C R[A] := R[B] / R[C]\n"
			"OP_IDIV A B C R[A] := R[B] // R[C]\n\n"
			"OP_BAND A B C R[A] := R[B] & R[C]\n"
			"OP_BOR	A B C R[A] := R[B] | R[C]\n"
			"OP_BXOR A B C R[A] := R[B] ~ R[C]\n"
			"OP_SHL	A B C R[A] := R[B] << R[C]\n"
			"OP_SHR	A B C R[A] := R[B] >> R[C]\n\n"
			"OP_MMBIN A B C	call C metamethod over R[A] and R[B]\n"
			"OP_MMBINI A sB C k	call C metamethod over R[A] and sB\n"
			"OP_MMBINK A B C k	call C metamethod over R[A] and K[B]\n\n"
			"OP_UNM	A B	R[A] := -R[B]\n"
			"OP_BNOT A B R[A] := ~R[B]\n"
			"OP_NOT	 A B R[A] := not R[B]\n"
			"OP_LEN	A B	R[A] := length of R[B]\n\n"
			"OP_CONCAT A B R[A] := R[A].. ... ..R[A + B - 1]\n\n"
			"OP_CLOSE A	close all upvalues >= R[A]\n"
			"OP_TBC	A mark variable A \"to be closed\"\n"
			"OP_JMP	sJ pc += sJ\n"
			"OP_EQ A B k if ((R[A] == R[B]) ~= k) then pc++\n"
			"OP_LT A B k if ((R[A] <  R[B]) ~= k) then pc++\n"
			"OP_LE A B k if ((R[A] <= R[B]) ~= k) then pc++\n\n"
			"OP_EQK	A B k if ((R[A] == K[B]) ~= k) then pc++\n"
			"OP_EQI	A sB k if ((R[A] == sB) ~= k) then pc++\n"
			"OP_LTI	A sB k if ((R[A] < sB) ~= k) then pc++\n"
			"OP_LEI	A sB k if ((R[A] <= sB) ~= k) then pc++\n"
			"OP_GTI	A sB k if ((R[A] > sB) ~= k) then pc++\n"
			"OP_GEI	A sB k if ((R[A] >= sB) ~= k) then pc++\n\n"
			"OP_TEST A k if (not R[A] == k) then pc++\n"
			"OP_TESTSET	A B k	if (not R[B] == k) then pc++ else R[A] := R[B]\n\n"
			"OP_CALL A B C R[A] ... R[A+C-2] := R[A](R[A+1] ... R[A+B-1])\n"
			"OP_TAILCALL A B C k return R[A](R[A+1] ... R[A+B-1])\n\n"
			"OP_RETURN A B C k	return R[A] ... R[A+B-2]	(see note)\n"
			"OP_RETURN0 return\n"
			"OP_RETURN1	A return R[A]\n\n"
			"OP_FORLOOP A Bx update counters; if loop continues then pc-=Bx;\n"
			"OP_FORPREP	A Bx <check values and prepare counters>; if not to run then pc+=Bx+1;\n\n"
			"OP_TFORPREP A Bx create upvalue for R[A + 3]; pc+=Bx\n"
			"OP_TFORCALL A C R[A+4] ... R[A+3+C] := R[A](R[A+1] R[A+2]);\n"
			"OP_TFORLOOP A Bx if R[A+2] ~= nil then { R[A]=R[A+2]; pc -= Bx }\n\n"
			"OP_SETLIST	A B C k	R[A][(C-1)*FPF+i] := R[A+i] 1 <= i <= B\n\n"
			"OP_CLOSURE	A Bx R[A] := closure(KPROTO[Bx])\n\n"
			"OP_VARARG	A C	R[A] R[A+1] ... R[A+C-2] = vararg\n\n"
			"OP_VARARGPREP A (adjust vararg parameters)\n\n"
			"OP_EXTRAARG Ax	extra larger argument for previous opcode	)";
	}

	auto LuaHook::getOpcodeInfo() -> std::string
	{
		// Copied from lopcodes.h:
		return
			R"(
  We assume that instructions are unsigned 32-bit integers.
  All instructions have an opcode in the first 7 bits.
  Instructions can have the following formats:

        3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
        1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
iABC          C(8)     |      B(8)     |k|     A(8)      |   Op(7)     |
iABx                Bx(17)               |     A(8)      |   Op(7)     |
iAsBx              sBx (signed)(17)      |     A(8)      |   Op(7)     |
iAx                           Ax(25)                     |   Op(7)     |
isJ                           sJ(25)                     |   Op(7)     |

  A signed argument is represented in excess K: the represented value is
  the written unsigned value minus K, where K is half the maximum for the
  corresponding unsigned argument.)";
	}
}
