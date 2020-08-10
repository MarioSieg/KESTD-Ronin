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
#ifndef NDEBUG
#include <iostream>
#endif

namespace kestd
{
	Logger::Logger()
	{
		buffer.reserve(autoFlushThreshold);
	}

	auto Logger::getBuffer() const noexcept -> const std::vector<Message>&
	{
		return buffer;
	}

	auto Logger::getLogCount() const noexcept -> std::size_t
	{
		return logCount;
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
		log(std::move(msg), MessageType::Trace);
		return *this;
	}

	auto Logger::operator|(std::string&& msg) -> Logger&
	{
		log(std::move(msg), MessageType::Warning);
		return *this;
	}

	auto Logger::operator&(std::string&& msg) -> Logger&
	{
		log(std::move(msg), MessageType::Error);
		return *this;
	}

	void Logger::clear()
	{
		buffer.clear();
		errorMessages = infoMessages = traceMessages = warningMessages = 0;
		logCount = 0;
	}

	void Logger::log(std::string&& msg, const MessageType type)
	{
#ifndef NDEBUG
		std::cout << msg << '\n';
#endif
		buffer.emplace_back(
			Message
			{
				std::move(msg),
				type,
				std::chrono::system_clock::now(),
			});
		++logCount;
		if (autoFlushThreshold && logCount >= autoFlushThreshold)
		{
			flush();
		}
	}
}
