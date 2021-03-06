// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Logger.hpp
// 31.08.2020 15:10
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
	/// Represents an automatically flushing, buffered bufLogger.
	/// </summary>
	class Logger final
	{
	public:

		/// <summary>
		/// Initializes a new buffered bufLogger and reserved capacity.
		/// </summary>
		/// <param name="reserve">The capacity (number of log messages) to reserve memory for.</param>
		explicit Logger(std::size_t reserve = 64);

		Logger(const Logger&) = default;

		Logger(Logger&&) noexcept = default;

		Logger& operator=(const Logger&) = default;

		Logger& operator=(Logger&&) noexcept = default;

		~Logger() = default;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The buffer containing the messages.</returns>
		[[nodiscard]]
		auto getBuffer() const noexcept -> const std::vector<Message>&;

		/// <summary>
		/// .
		/// </summary>
		/// <returns>The number of warning messages.</returns>
		[[nodiscard]]
		auto getWarningMessageCount() const noexcept -> std::uint16_t;

		/// <summary>
		///
		/// </summary>
		/// <returns>The number of error messages.</returns>
		[[nodiscard]]
		auto getErrorMessageCount() const noexcept -> std::uint16_t;

		/// <summary>
		/// Clears the current log.
		/// </summary>
		void clear();

		/// <summary>
		/// Log to the bufLogger.
		/// </summary>
		/// <param name="type"></param>
		/// <param name="msg"></param>
		void log(MessageType type, std::string&& msg);

		template<typename... T>
		void log(MessageType type, std::string&& msg, T&&... args)
		{
			log(type, fmt::format(msg, args...));
		}

		template<typename... T>
		void warning(std::string&& msg, T&&... args)
		{
			log(MessageType::Warning, fmt::format(msg, args...));
		}

		template<typename... T>
		void info(std::string&& msg, T&&... args)
		{
			log(MessageType::Info, fmt::format(msg, args...));
		}

		template<typename... T>
		void trace(std::string&& msg, T&&... args)
		{
			log(MessageType::Trace, fmt::format(msg, args...));
		}

		template<typename... T>
		void success(std::string&& msg, T&&... args)
		{
			log(MessageType::Success, fmt::format(msg, args...));
		}

		template<typename... T>
		void error(std::string&& msg, T&&... args)
		{
			log(MessageType::Error, fmt::format(msg, args...));
		}

		/// <summary>
		/// Insert a separator.
		/// </summary>
		void separator();

		/// <summary>
		/// Log to the bufLogger without any time or type info formatting.
		/// </summary>
		/// <param name="msg"></param>
		void logDump(std::string&& msg);

		/// <summary>
		/// Flush the bufLogger to the logfile and clear the buffer.
		/// </summary>
		/// <returns>True if the disk write was successful, else false!</returns>
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
