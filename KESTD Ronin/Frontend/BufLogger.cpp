// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// BufLogger.cpp
// 09.08.2020 07:24
// =============================================================

#include "BufLogger.hpp"
#include <fstream>
#include <chrono>
#include <fmt/core.h>
#include <fmt/chrono.h>

namespace kestd
{
	BufLogger::BufLogger(const std::size_t reserve)
	{
		buffer.reserve(reserve);
	}

	auto BufLogger::getBuffer() const noexcept -> const std::vector<Message>&
	{
		return buffer;
	}

	auto BufLogger::getWarningMessageCount() const noexcept -> std::uint16_t
	{
		return warningMessageCount;
	}

	auto BufLogger::getErrorMessageCount() const noexcept -> std::uint16_t
	{
		return errorMessageCount;
	}

	auto BufLogger::flush() -> bool
	{
		const auto now = std::time(nullptr);
		std::ofstream handle(
			logFile.value_or(fmt::format("../Proto/KESTD-Ronin-{:%d-%m-%Y-%H-%M-%S}.log", fmt::localtime(now))));
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

	void BufLogger::compressMessages()
	{
		for (auto& msg : buffer)
		{
			msg.msg.shrink_to_fit();
		}
	}

	void BufLogger::compressBuffer()
	{
		buffer.shrink_to_fit();
	}

	void BufLogger::clear()
	{
		buffer.clear();
		buffer.shrink_to_fit();
		errorMessageCount = warningMessageCount = 0;
	}

	constexpr std::string_view MessageTypeMnemonics[static_cast<std::size_t>(MessageType::Count)]
	{
		"Info",
		"Trace",
		"Error",
		"Warning",
		"Success"
	};

	void BufLogger::log(const MessageType type, std::string&& msg)
	{
		auto message = Message
		{
			fmt::format("{:%H:%M:%S} [{}] {}",
			            fmt::localtime(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())),
			            MessageTypeMnemonics[static_cast<std::size_t>(type)],
			            msg),
			type,
		};

		buffer.emplace_back(std::move(message));

		if (type == MessageType::Error)
		{
			++errorMessageCount;
		}
		else if (type == MessageType::Warning)
		{
			++warningMessageCount;
		}
	}

	void BufLogger::logDump(std::string&& msg)
	{
		buffer.emplace_back(
			Message
			{
				msg,
				MessageType::Info
			});
	}
}
