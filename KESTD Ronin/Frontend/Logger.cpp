// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Logger.cpp
// 09.08.2020 07:24
// =============================================================

#include "Logger.hpp"
#include <fstream>
#include <chrono>
#include <fmt/core.h>
#include <fmt/chrono.h>

namespace kestd
{
	Logger::Logger(const std::size_t reserve)
	{
		buffer.reserve(reserve);
	}

	auto Logger::getBuffer() const noexcept -> const std::vector<Message>&
	{
		return buffer;
	}

	auto Logger::flush() -> bool
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

	auto Logger::operator<<(std::string&& msg) -> Logger&
	{
		log(std::move(msg));
		return *this;
	}

	auto Logger::operator>>(std::string&& msg) -> Logger&
	{
		log<MessageType::Trace>(std::move(msg));
		return *this;
	}

	auto Logger::operator|(std::string&& msg) -> Logger&
	{
		log<MessageType::Warning>(std::move(msg));
		return *this;
	}

	auto Logger::operator&(std::string&& msg) -> Logger&
	{
		log<MessageType::Error>(std::move(msg));
		return *this;
	}

	auto Logger::operator^(std::string&& msg) -> Logger&
	{
		log_raw(std::move(msg));
		return *this;
	}

	void Logger::clear()
	{
		buffer.clear();
		errorMessages = infoMessages = traceMessages = warningMessages = 0;
	}

	void Logger::log_raw(std::string&& msg)
	{
		buffer.emplace_back(
			Message
			{
				msg,
				MessageType::Info
			});
	}

	template<>
	void Logger::log<MessageType::Error>(std::string&& msg)
	{
		buffer.emplace_back(
			Message
			{
				fmt::format("{:%H:%M:%S} [ERROR] {}", fmt::localtime(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())), msg),
				MessageType::Error,
			});
	}

	template<>
	void Logger::log<MessageType::Warning>(std::string&& msg)
	{
		buffer.emplace_back(
			Message
			{
				fmt::format("{:%H:%M:%S} [WARNING] {}", fmt::localtime(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())), msg),
				MessageType::Warning,
			});
	}

	template<>
	void Logger::log<MessageType::Trace>(std::string&& msg)
	{
		buffer.emplace_back(
			Message
			{
				fmt::format("{:%H:%M:%S} [TRACE] {}", fmt::localtime(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())), msg),
				MessageType::Warning,
			});
	}

	template<MessageType T>
	void Logger::log(std::string&& msg)
	{
		buffer.emplace_back(
			Message
			{
				fmt::format("{:%H:%M:%S} [INFO] {}", fmt::localtime(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())), msg),
				T,
			});
	}
}
