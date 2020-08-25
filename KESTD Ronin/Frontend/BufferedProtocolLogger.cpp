// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// BufferedProtocolLogger.cpp
// 09.08.2020 07:24
// =============================================================

#include "BufferedProtocolLogger.hpp"
#include <fstream>
#include <chrono>
#include <fmt/core.h>
#include <fmt/chrono.h>

namespace kestd
{
	BufferedProtocolLogger::BufferedProtocolLogger(const std::size_t reserve)
	{
		buffer.reserve(reserve);
	}

	auto BufferedProtocolLogger::getBuffer() const noexcept -> const std::vector<Message>&
	{
		return buffer;
	}

	auto BufferedProtocolLogger::flush() -> bool
	{
		std::ofstream handle(logFile);
		if (!handle)
		{
			return false;
		}

		for (const auto& msg : buffer)
		{
			handle << msg.msg << '\n';
		}

		clear();

		return true;
	}

	auto BufferedProtocolLogger::operator<<(std::string&& msg) -> BufferedProtocolLogger&
	{
		log(std::move(msg));
		return *this;
	}

	auto BufferedProtocolLogger::operator>>(std::string&& msg) -> BufferedProtocolLogger&
	{
		log<MessageType::Trace>(std::move(msg));
		return *this;
	}

	auto BufferedProtocolLogger::operator|(std::string&& msg) -> BufferedProtocolLogger&
	{
		log<MessageType::Warning>(std::move(msg));
		return *this;
	}

	auto BufferedProtocolLogger::operator&(std::string&& msg) -> BufferedProtocolLogger&
	{
		log<MessageType::Error>(std::move(msg));
		return *this;
	}

	auto BufferedProtocolLogger::operator%(std::string&& msg) -> BufferedProtocolLogger&
	{
		log<MessageType::Success>(std::move(msg));
		return *this;
	}

	auto BufferedProtocolLogger::operator^(std::string&& msg) -> BufferedProtocolLogger&
	{
		log_raw(std::move(msg));
		return *this;
	}

	void BufferedProtocolLogger::clear()
	{
		buffer.clear();
		errorMessages = infoMessages = traceMessages = warningMessages = 0;
	}

	void BufferedProtocolLogger::log_raw(std::string&& msg)
	{
		buffer.emplace_back(
			Message
			{
				msg,
				MessageType::Info
			});
	}

	template<>
	void BufferedProtocolLogger::log<MessageType::Error>(std::string&& msg)
	{
		buffer.emplace_back(
			Message
			{
				fmt::format("{:%H:%M:%S} [ERROR] {}",
				            fmt::localtime(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())),
				            msg),
				MessageType::Error,
			});
	}

	template<>
	void BufferedProtocolLogger::log<MessageType::Warning>(std::string&& msg)
	{
		buffer.emplace_back(
			Message
			{
				fmt::format("{:%H:%M:%S} [WARNING] {}",
				            fmt::localtime(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())),
				            msg),
				MessageType::Warning,
			});
	}

	template<>
	void BufferedProtocolLogger::log<MessageType::Trace>(std::string&& msg)
	{
		buffer.emplace_back(
			Message
			{
				fmt::format("{:%H:%M:%S} [TRACE] {}",
				            fmt::localtime(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())),
				            msg),
				MessageType::Warning,
			});
	}

	template<>
	void BufferedProtocolLogger::log<MessageType::Success>(std::string&& msg)
	{
		buffer.emplace_back(
			Message
			{
				fmt::format("{:%H:%M:%S} [OKAY] {}",
				            fmt::localtime(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())),
				            msg),
				MessageType::Success,
			});
	}

	template<MessageType T>
	void BufferedProtocolLogger::log(std::string&& msg)
	{
		buffer.emplace_back(
			Message
			{
				fmt::format("{:%H:%M:%S} [INFO] {}",
				            fmt::localtime(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())),
				            msg),
				T,
			});
	}
}
