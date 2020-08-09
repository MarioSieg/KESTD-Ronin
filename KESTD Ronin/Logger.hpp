// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Logger.hpp
// 07.08.2020 02:30
// =============================================================

#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include <chrono>

namespace kestd
{
	/// <summary>
	/// Represents the type of a log message.
	/// </summary>
	enum class MessageType
	{
		/// <summary>
		/// Just info logging.
		/// </summary>
		Info,

		/// <summary>
		/// Just tracer logging.
		/// </summary>
		Trace,

		/// <summary>
		/// Warning - could lean to an error!
		/// </summary>
		Warning,

		/// <summary>
		/// Fatal error!
		/// </summary>
		Error,
	};

	/// <summary>
	/// Represents a single log message.
	/// </summary>
	struct Message final
	{
		/// <summary>
		/// The message string.
		/// </summary>
		std::string msg;

		/// <summary>
		/// The type of the message.
		/// </summary>
		MessageType type;

		/// <summary>
		/// Time stamp in seconds.
		/// </summary>
		std::chrono::system_clock::time_point timeStamp;
	};

	/// <summary>
	/// Represents an automatically flushing, buffered logger.
	/// </summary>
	class Logger final
	{
	public:
		/// <summary>
		/// After how many messages should we autoflush? Set to 0 to disable autoflush!
		/// </summary>
		std::size_t autoFlushThreshold = 1024;

		/// <summary>
		/// How many info messages are in the buffer?
		/// </summary>
		std::size_t infoMessages = 0;

		/// <summary>
		/// How many trace messages are in the buffer?
		/// </summary>
		std::size_t traceMessages = 0;

		/// <summary>
		/// How many warning messages are in the buffer?
		/// </summary>
		std::size_t warningMessages = 0;

		/// <summary>
		/// How many error messages are in the buffer?
		/// </summary>
		std::size_t errorMessages = 0;

		/// <summary>
		/// The current log file path.
		/// </summary>
		std::filesystem::path logFile = "session.log";

		/// <summary>
		/// Initialize a new logger with n capacity.
		/// </summary>
		Logger();

		/// <summary>
		/// Returns the current buffer.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] auto getBuffer() const noexcept -> const std::vector<Message>&;

		/// <summary>
		/// Returns the log count. Will be set to 0 after flush.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] auto getLogCount() const noexcept -> std::size_t;

		/// <summary>
		/// Clears the current buffer.
		/// </summary>
		/// <returns></returns>
		void clear();

		/// <summary>
		/// Log a message.
		/// </summary>
		/// <param name="msg"></param>
		/// <param name="type"></param>
		void log(std::string&& msg, const MessageType type = MessageType::Info);

		/// <summary>
		/// Log an info message.
		/// </summary>
		/// <param name="msg"></param>
		/// <returns></returns>
		auto operator<<(std::string&& msg) -> Logger&;


		/// <summary>
		/// Log a trace message.
		/// </summary>
		/// <param name="msg"></param>
		/// <returns></returns>
		auto operator>>(std::string&& msg) -> Logger&;

		/// <summary>
		/// Log a warning message.
		/// </summary>
		/// <param name="msg"></param>
		/// <returns></returns>
		auto operator|(std::string&& msg) -> Logger&;

		/// <summary>
		/// Log an error message.
		/// </summary>
		/// <param name="msg"></param>
		/// <returns></returns>
		auto operator&(std::string&& msg) -> Logger&;

		/// <summary>
		/// Flushes the current buffer to the logfile and clears it.
		/// </summary>
		/// <returns>True if the flushing succeeded, else false.</returns>
		auto flush() -> bool;

	private:
		std::size_t logCount = 0;
		std::vector<Message> buffer = {};
	};
}
