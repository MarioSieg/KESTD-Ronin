// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Logger.cpp
// 07.08.2020 02:30
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
		Buffer.reserve(AutoFlushThreshold);
	}

	auto Logger::GetBuffer() const noexcept -> const std::vector<Message>&
	{
		return Buffer;
	}

	auto Logger::GetLogCount() const noexcept -> std::size_t
	{
		return LogCount;
	}

	auto Logger::Flush() -> bool
	{
		std::ofstream handle(LogFile);
		if (!handle)
		{
			return false;
		}

		for (const auto& msg : Buffer)
		{
			handle << msg.Msg << '\n';
		}

		Clear();

		return true;
	}

	auto Logger::operator<<(std::string&& msg) -> Logger&
	{
		Log(std::move(msg));
		return *this;
	}

	auto Logger::operator>>(std::string&& msg) -> Logger&
	{
		Log(std::move(msg), MessageType::Trace);
		return *this;
	}

	auto Logger::operator|(std::string&& msg) -> Logger&
	{
		Log(std::move(msg), MessageType::Warning);
		return *this;
	}

	auto Logger::operator&(std::string&& msg) -> Logger&
	{
		Log(std::move(msg), MessageType::Error);
		return *this;
	}

	void Logger::Clear()
	{
		Buffer.clear();
		ErrorMessages = InfoMessages = TraceMessages = WarningMessages = 0;
		LogCount = 0;
	}

	void Logger::Log(std::string&& msg, const MessageType type)
	{
#ifndef NDEBUG
		std::cout << msg << '\n';
#endif
		Buffer.emplace_back(
			Message
			{
				std::move(msg),
				type,
				std::chrono::system_clock::now(),
			});
		++LogCount;
		if (AutoFlushThreshold && LogCount >= AutoFlushThreshold)
		{
			Flush();
		}
	}
}
