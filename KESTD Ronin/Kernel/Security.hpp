// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Security.hpp
// 07.08.2020 02:30
// =============================================================

#pragma once

#include <cstdint>
#include <string_view>

namespace kestd::kernel
{
	/// <summary>
	/// Represents a user.
	/// </summary>
	enum class User: std::uint8_t
	{
		/// <summary>
		/// Has no rights.
		/// </summary>
		Normal = 0,

		/// <summary>
		/// Has some rights.
		/// </summary>
		Service = 1 << 0,

		/// <summary>
		/// Has many server local rights.
		/// </summary>
		Admin = 1 << 1,

		/// <summary>
		/// Has all rights.
		/// </summary>
		Root = 1 << 2,
	};

	/// <summary>
	/// Returns true if a has more privileges than b!
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	constexpr auto isPrestigious(const User a, const User b) -> bool
	{
		return a > b;
	}

	/// <summary>
	/// Returns the privileges of the user as text.
	/// </summary>
	/// <param name="user"></param>
	/// <returns></returns>
	constexpr auto getUserPrivilegesName(const User user) -> std::string_view
	{
		switch (user)
		{
			default:
			case User::Normal: return "NoPrivileges";
			case User::Service: return "ServicePrivileges";
			case User::Admin: return "AdminPrivileges";
			case User::Root: return "RootDeveloperPrivileges";
		}
	}

	/// <summary>
	/// Represents a personal identification number.
	/// </summary>
	enum class Pin: std::uint64_t
	{
		Invalid = 0,
		Service = 0x19199a97,
		Admin = 0xa98233b3,
		Root = 0xca056363,
	};

	/// <summary>
	/// Returns the pin of the user specified.
	/// </summary>
	/// <param name="usr"></param>
	/// <returns></returns>
	constexpr auto getCorrespondingPin(const User usr) -> Pin
	{
		switch (usr)
		{
			default:
			case User::Normal: return Pin::Invalid;
			case User::Service: return Pin::Service;
			case User::Admin: return Pin::Admin;
			case User::Root: return Pin::Root;
		}
	}

	/// <summary>
	/// Maximum wrong pin attempts, before it locks down.
	/// </summary>
	constexpr uint64_t MAX_ATTEMPTS = 3;

	/// <summary>
	/// Represents lockable security manager.
	/// </summary>
	struct SecurityManager final
	{
		/// <summary>
		/// Number of succeeded login attempts.
		/// </summary>
		uint16_t succeededAttempts = 0;

		/// <summary>
		/// Number of succeeded failed attempts.
		/// </summary>
		uint16_t failedAttempts = 0;

		/// <summary>
		/// Number of user role or name changes.
		/// </summary>
		uint16_t userUpdates = 0;

		/// <summary>
		/// Is this manager currently locked?
		/// </summary>
		bool isLocked = false;

		/// <summary>
		/// Current user role.
		/// </summary>
		User current = User::Normal;

		/// <summary>
		/// Try to login into the system with higher user privileges.
		/// </summary>
		/// <param name="wanted"></param>
		/// <param name="pin"></param>
		/// <returns></returns>
		auto logIn(const User wanted, const Pin pin) noexcept -> bool;

		/// <summary>
		/// Log off into normal user mode.
		/// </summary>
		/// <returns></returns>
		auto logOff() noexcept;
	};
}
