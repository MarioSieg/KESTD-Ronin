// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Kernel.hpp
// 09.08.2020 07:25
// =============================================================

#pragma once

#include "ISubsystem.hpp"
#include "Security.hpp"
#include <memory>
#include <string>
#include <vector>

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
	/// Configuration to boot the kernel.
	/// </summary>
	struct KernelDescriptor final
	{
		std::string appName;
		std::string companyName;
		User user = User::Normal;
		Pin pin = Pin::Invalid;
		bool pushLegacySubsystems = true;
	};

	/// <summary>
	/// Represents the engine kernel and handle.
	/// </summary>
	class Kernel final
	{
	public:
		/// <summary>
		/// Creates a new engine kernel, initializes all resources and starts all systems.
		/// </summary>
		/// <param name="desc">Boot description.</param>
		explicit Kernel(KernelDescriptor&& desc);

		Kernel(const Kernel&) = delete;

		Kernel(Kernel&&) = delete;

		auto operator=(const Kernel&) -> Kernel& = delete;

		auto operator=(Kernel&&) -> Kernel& = delete;

		~Kernel();

		/// <summary>
		/// Allocates and pushes a new subsystem into the kernel.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <typeparam name="...Args"></typeparam>
		/// <param name="args">Additional parameters for subsystem constructor.</param>
		/// <returns></returns>
		template<typename T, typename... Args> requires std::is_base_of_v<ISubsystem, T>
		auto makeSubsystem(Args&&... args) -> std::size_t
		{
			return pushSubsystem(std::make_unique<T>(const_cast<Environment &>(getEnvironment()), args...));
		}

		/// <summary>
		/// Pushes a new subsystem into the kernel.
		/// </summary>
		/// <param name="ptr"></param>
		/// <returns></returns>
		auto pushSubsystem(std::unique_ptr<ISubsystem>&& ptr) const -> std::size_t;

		/// <summary>
		/// Executes the kernel and enters the game loop.
		/// </summary>
		/// <returns>The number of cycles before interrupt!</returns>
		[[nodiscard]] auto execute() const -> std::uint32_t;

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
		/// Returns the current runtime environment.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] auto getEnvironment() const noexcept -> const Environment&;

		/// <summary>
		/// Interrupts execution, ending the application.
		/// </summary>
		/// <returns></returns>
		void interrupt() const noexcept;

	private:
		void dumpBootInfo() const;
		struct Pimpl;
		std::unique_ptr<Pimpl> core;
	};
}
