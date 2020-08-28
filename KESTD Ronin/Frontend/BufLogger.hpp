// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// BufLogger.hpp
// 09.08.2020 07:24
// =============================================================

#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include <optional>
#include <fmt/core.h>

namespace kestd
{
	/// <summary>
	/// Represents the type of a log message.
	/// </summary>
	enum class MessageType
	{
		/// <summary>
		/// (Grey) Just info logging.
		/// </summary>
		Info,

		/// <summary>
		/// (Grey) Just tracer logging.
		/// </summary>
		Trace,

		/// <summary>
		/// (Red) Fatal error!
		/// </summary>
		Error,

		/// <summary>
		/// (Orange) Warning - could lean to an error!
		/// </summary>
		Warning,

		/// <summary>
		/// (Green) Log a success message.
		/// </summary>
		Success,

		Count
	};

	/// <summary>
	/// Represents a single log message.
	/// </summary>
	class Message final
	{
	public:
		/// <summary>
		/// The message string.
		/// </summary>
		std::string msg = {};

		/// <summary>
		/// The type of the message.
		/// </summary>
		MessageType type = MessageType::Info;
	};

	/// <summary>
	/// Represents an automatically flushing, buffered logger.
	/// </summary>
	class BufLogger final
	{
	public:

		/// <summary>
		/// Initializes a new buffered logger and reserved capacity.
		/// </summary>
		/// <param name="reserve">The capacity (number of log messages) to reserve memory for.</param>
		explicit BufLogger(std::size_t reserve = 64);
		
		BufLogger(const BufLogger&);
		
		BufLogger(BufLogger&&) noexcept;
		
		BufLogger& operator=(const BufLogger&);
		
		BufLogger& operator=(BufLogger&&) noexcept;
		
		~BufLogger();

		/// <summary>
		/// Returns the buffer of this logger.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getBuffer() const noexcept -> const std::vector<Message>&;

		/// <summary>
		/// Returns the number of warning messages.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getWarningMessageCount() const noexcept -> std::uint16_t;

		/// <summary>
		/// Returns the number of error messages.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getErrorMessageCount() const noexcept -> std::uint16_t;

		/// <summary>
		/// Clears the current log.
		/// </summary>
		void clear();

		/// <summary>
		/// Log to the logger.
		/// </summary>
		/// <param name="type"></param>
		/// <param name="msg"></param>
		void log(MessageType type, std::string&& msg);

		template<typename... T>
		void log(MessageType type, std::string&& msg, T&&... args)
		{
			log(type, fmt::format(msg, args...));
		}

		/// <summary>
		/// Log to the logger without any time or type info formatting.
		/// </summary>
		/// <param name="msg"></param>
		void logDump(std::string&& msg);

		/// <summary>
		/// Flush the logger to the logfile and clear the buffer.
		/// </summary>
		/// <returns></returns>
		auto flush() -> bool;

		/// <summary>
		/// Calls shrink_to_fit() on all message strings to reduce capacity and memory consumption.
		/// </summary>
		void compressMessages();

		/// <summary>
		/// Calls shrink_to_fit() on the buffer to reduce capacity and memory consumption.
		/// </summary>
		void compressBuffer();

	private:
		std::vector<Message> buffer;
		std::uint16_t warningMessageCount;
		std::uint16_t errorMessageCount;
		std::optional<std::filesystem::path> logFile;
	};
}
