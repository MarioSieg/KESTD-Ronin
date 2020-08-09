// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Kernel.hpp
// 07.08.2020 02:30
// =============================================================

#pragma once

#include "Subsystem.hpp"
#include "Security.hpp"
#include <memory>
#include <string>
#include <vector>
#include <tuple>

namespace kestd::kernel
{
	/// <summary>
	/// Represents the a kernel status.
	/// </summary>
	enum class SystemState
	{
		/// <summary>
		/// System is online.
		/// </summary>
		Online,

		/// <summary>
		/// System is ready to run.
		/// </summary>
		Ready,

		/// <summary>
		/// System is offline.
		/// </summary>
		Offline,
	};

	/// <summary>
	/// Represents the engine kernel and handle.
	/// </summary>
	class Kernel final
	{
	public:
		/// <summary>
		/// Creates a new engine kernel.
		/// </summary>
		/// <param name="appName">The name of the application or game.</param>
		/// <param name="companyName">The name of the developing company.</param>
		/// <returns></returns>
		explicit Kernel(std::string&& appName, std::string&& companyName);

		Kernel(const Kernel&) = delete;

		Kernel(Kernel&&) = delete;

		auto operator=(const Kernel&) -> Kernel& = delete;

		auto operator=(Kernel&&) -> Kernel& = delete;

		~Kernel();

		/// <summary>
		/// Starts all subsystems and sets the state to Ready
		/// </summary>
		/// <param name="usr"></param>
		/// <param name="pin"></param>
		/// <returns></returns>
		[[nodiscard]] auto startup(const User usr = User::Normal, const Pin pin = Pin::Invalid) const -> bool;

		/// <summary>
		/// Executes the kernel and enters the game loop.
		/// </summary>
		/// <returns>The number of cycles before interrupt!</returns>
		[[nodiscard]] auto execute() const -> std::tuple<bool, uint32_t>;

		/// <summary>
		/// Returns the current state of the system.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] auto getState() const noexcept -> SystemState;

		/// <summary>
		/// Returns the current trap flag of the system.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] auto getTrapFlag() const noexcept -> bool;

		/// <summary>
		/// Returns all registered subsystems.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] auto getSystems() const noexcept -> const std::vector<std::unique_ptr<ISubsystem>>&;

		/// <summary>
		/// Interrupts execution, ending the application.
		/// </summary>
		/// <returns></returns>
		auto interrupt() const noexcept;

	private:
		struct Pimpl;
		std::unique_ptr<Pimpl> core;
	};
}
