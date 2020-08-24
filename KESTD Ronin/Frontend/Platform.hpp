// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Platform.hpp
// 09.08.2020 07:24
// =============================================================

#pragma once

/// <summary>
/// Are we on Linux?
/// </summary>
#define SYS_LINUX false

/// <summary>
/// Are we on Windows?
/// </summary>
#define SYS_WINDOWS false

/// <summary>
/// Are we on Mac?
/// </summary>
#define SYS_MAC false

/// <summary>
/// The name of the current system.
/// </summary>
#define SYS_NAME "Unknown"

/// <summary>
/// Are we compiling with GCC?
/// </summary>
#define COM_GCC false

/// <summary>
/// Are we compiling with MSVC?
/// </summary>
#define COM_MSVC false

/// <summary>
/// Are we compiling with Clang?
/// </summary>
#define COM_CLANG false

/// <summary>
/// The name of the current compiler.
/// </summary>
#define COM_NAME "Unknown"

#if defined(__linux__) &&! defined(__ANDROID__)
#	undef SYS_LINUX
#	define SYS_LINUX true
#	undef SYS_NAME
#	define SYS_NAME "Linux"
#elif defined(_WIN64)
#	undef SYS_WINDOWS
#	define SYS_WINDOWS true
#	undef SYS_NAME
#	define SYS_NAME "Windows"
#elif defined(__APPLE__)
#	undef SYS_MAC
#	define SYS_MAC true
#	undef SYS_NAME
#	define SYS_NAME "Mac"
#else
#error("(PlatformData.hpp) Unknown platform!")
#endif

#if defined(__GNUC__)
#	undef COM_GCC
#	define COM_GCC true
#	undef COM_NAME
#	define COM_NAME "GCC"
#elif defined(_MSC_VER)
#	undef COM_MSVC
#	define COM_MSVC true
#	undef COM_NAME
#	define COM_NAME "MSVC"
#elif defined(__clang__)
#undef COM_CLANG
#	define COM_CLANG true
#	undef COM_NAME
#	define COM_NAME "Clang"
#else
#error("(PlatformData.hpp) Unknown compiler!")
#endif
