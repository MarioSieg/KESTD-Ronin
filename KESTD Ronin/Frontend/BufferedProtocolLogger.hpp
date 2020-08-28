// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// BufferedProtocolLogger.hpp
// 09.08.2020 07:24
// =============================================================

#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include <optional>

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
		Success
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
	};

	/// <summary>
	/// Represents an automatically flushing, buffered logger.
	/// </summary>
	class BufferedProtocolLogger final
	{
	public:
		/// <summary>
		/// How many info messages are in the buffer?
		/// </summary>
		std::size_t infoMessages;

		/// <summary>
		/// How many trace messages are in the buffer?
		/// </summary>
		std::size_t traceMessages;

		/// <summary>
		/// How many warning messages are in the buffer?
		/// </summary>
		std::size_t warningMessages;

		/// <summary>
		/// How many error messages are in the buffer?
		/// </summary>
		std::size_t errorMessages;

		/// <summary>
		/// The current log file path.
		/// </summary>
		std::optional<std::filesystem::path> logFile;

		/// <summary>
		/// Initialize a new logger with n capacity.
		/// </summary>
		BufferedProtocolLogger(std::size_t reserve = 64);

		/// <summary>
		/// Returns the current buffer.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] auto getBuffer() const noexcept -> const std::vector<Message>&;

		/// <summary>
		/// Clears the current buffer.
		/// </summary>
		/// <returns></returns>
		void clear();

		/// <summary>
		/// Log a message.
		/// </summary>
		/// <param name="msg"></param>
		template<MessageType T = MessageType::Info>
		void log(std::string&& msg);

		/// <summary>
		/// Log a message without any time and type formatting.
		/// </summary>
		/// <param name="msg"></param>
		void log_raw(std::string&& msg);

		/// <summary>
		/// Log a message.
		/// </summary>
		/// <param name="msg"></param>
		template<>
		void log<MessageType::Error>(std::string&& msg);

		/// <summary>
		/// Log a message.
		/// </summary>
		/// <param name="msg"></param>
		template<>
		void log<MessageType::Warning>(std::string&& msg);

		/// <summary>
		/// Log a message.
		/// </summary>
		/// <param name="msg"></param>
		template<>
		void log<MessageType::Trace>(std::string&& msg);

		/// <summary>
		/// Log a message.
		/// </summary>
		/// <param name="msg"></param>
		template<>
		void log<MessageType::Success>(std::string&& msg);

		/// <summary>
		/// Log an info message.
		/// </summary>
		/// <param name="msg"></param>
		/// <returns></returns>
		auto operator<<(std::string&& msg) -> BufferedProtocolLogger&;


		/// <summary>
		/// Log a trace message.
		/// </summary>
		/// <param name="msg"></param>
		/// <returns></returns>
		auto operator>>(std::string&& msg) -> BufferedProtocolLogger&;

		/// <summary>
		/// Log a warning message.
		/// </summary>
		/// <param name="msg"></param>
		/// <returns></returns>
		auto operator|(std::string&& msg) -> BufferedProtocolLogger&;

		/// <summary>
		/// Log an error message.
		/// </summary>
		/// <param name="msg"></param>
		/// <returns></returns>
		auto operator&(std::string&& msg) -> BufferedProtocolLogger&;

		/// <summary>
		/// Log a success message.
		/// </summary>
		/// <param name="msg"></param>
		/// <returns></returns>
		auto operator%(std::string&& msg) -> BufferedProtocolLogger&;

		/// <summary>
		/// Log a message without any time and type formatting.
		/// </summary>
		/// <param name="msg"></param>
		auto operator^(std::string&& msg) -> BufferedProtocolLogger&;

		/// <summary>
		/// Flushes the current buffer to the logfile and clears it.
		/// </summary>
		/// <returns>True if the flushing succeeded, else false.</returns>
		auto flush() -> bool;

		/// <summary>
		/// Shrinks all message strings capacity in the buffer to the minimal size.
		/// </summary>
		void compressMessages();

		/// <summary>
		/// Shrinks the message buffer capacity to the minimal size.
		/// </summary>
		void compressBuffer();

	private:
		std::vector<Message> buffer;
	};
}
