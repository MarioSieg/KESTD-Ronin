// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// TerminalController.hpp
// 09.08.2020 07:38
// =============================================================

#pragma once

#include "BufferedProtocolLogger.hpp"

namespace kestd
{
	/// <summary>
	/// Allows to control the terminal.
	/// </summary>
	struct TerminalController final
	{
		/// <summary>
		/// Length of the internal command buffer.
		/// </summary>
		static constexpr std::size_t MAX_COMMAND_LEN = 64;

		/// <summary>
		/// ABGR colors of the message types.
		/// </summary>
		static constexpr std::uint32_t COLORS[5] = {
			0xFF'FF'FF'FF,
			// Info
			0xFF'8C'8C'8C,
			// Trace
			0xFF'36'36'C9,
			// Error
			0xFF'36'6F'C9,
			// Warning
			0xFF'4C'C9'36 // Success
		};

		/// <summary>
		/// Display the terminal currently?
		/// </summary>
		bool displayTerminal = true;

		/// <summary>
		/// Enable Auto scroll to bottom?
		/// </summary>
		bool autoScroll = true;

		/// <summary>
		/// Enable autofocus after command enter?
		/// </summary>
		bool autoFocus = true;
	};
}
