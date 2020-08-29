// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// ConfigGraphics.hpp
// 29.08.2020 13:43
// =============================================================

#pragma once

#include <string_view>

namespace kestd
{
	/// <summary>
	/// Contains all graphics APIs supported.
	/// </summary>
	enum class GraphicsApi
	{
		Direct3D9,
		Direct3D11,
		Direct3D12,
		OpenGL2,
		OpenGL3,
		OpenGL_ES2,
		OpenGL_ES3,
		Vulkan,
		Metal,
		WebGL1,
		WebGL2,
		WebGPU,
		Count
	};

	constexpr std::string_view GraphicsApiNames[static_cast<std::size_t>(GraphicsApi::Count)]
	{
		"Direct3D 9",
		"Direct3D 11",
		"Direct3D 12",
		"OpenGL 2",
		"OpenGL 3",
		"OpenGL EmbeddedSystems 2",
		"OpenGL EmbeddedSystems 3",
		"Vulkan",
		"Metal",
		"WebGL 1",
		"WebGL 2",
		"WebGPU",
	};

	/// <summary>
	/// Selects Direct3D11 on Windows. If "modern" is true it selects Direct3D12.
	/// </summary>
	/// <param name="modern">If true, it will return the more modern graphics API like Direct3D12 instead of Direct3D11 or Vulkan instead of OpenGL.</param>
	/// <returns>The preferred graphics API on the current platform.</returns>
	extern auto GetPrefferedPlatformGraphicsApi(bool modern) noexcept -> GraphicsApi;

	/// <summary>
	/// Represents window modes.
	/// </summary>
	enum class WindowMode
	{
		FullScreen,
		Windowed,
		WindowedMaximized
	};

	/// <summary>
	/// Represents MSAA level.
	/// </summary>
	enum class MultiSampleAntiAliasingMode
	{
		Off = 1,
		X2 = 2,
		X4 = 4,
		X8 = 8,
		X16 = 16,
	};

	/// <summary>
	/// Contains graphics and display configuration.
	/// </summary>
	class ConfigGraphics final
	{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <returns>The graphics API.</returns>
		[[nodiscard]]
		auto getGraphicsApi() const noexcept -> GraphicsApi;

		/// <summary>
		/// Sets the graphics API.
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setGraphicsApi(GraphicsApi val) noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The width of the window and framebuffer.</returns>
		[[nodiscard]]
		auto getWidth() const noexcept -> std::uint16_t;

		/// <summary>
		/// Sets the width of the window and framebuffer. !! Ignored when fullscreen !!
		/// </summary>
		/// <returns></returns>
		void setWidth(std::uint16_t val) noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The height of the window and framebuffer.</returns>
		[[nodiscard]]
		auto getHeight() const noexcept -> std::uint16_t;

		/// <summary>
		/// Sets the height of the window and framebuffer. !! Ignored when fullscreen !!
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setHeight(std::uint16_t val) noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current window mode.</returns>
		[[nodiscard]]
		auto getWindowMode() const noexcept -> WindowMode;

		/// <summary>
		/// Sets the current window mode.
		/// </summary>
		/// <param name="mode"></param>
		/// <returns></returns>
		void setWindowMode(WindowMode mode) noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current msaa mode.</returns>
		[[nodiscard]]
		auto getMsaaMode() const noexcept -> MultiSampleAntiAliasingMode;

		/// <summary>
		/// Sets the current msaa mode.
		/// </summary>
		/// <param name="mode"></param>
		/// <returns></returns>
		void setMsaaMode(MultiSampleAntiAliasingMode mode) noexcept;

	private:
		GraphicsApi api = GraphicsApi::Vulkan;
		std::uint16_t width = 1920;  //TODO Replace with Resolution
		std::uint16_t height = 1080; //TODO Replace with Resolution
		WindowMode windowMode = WindowMode::WindowedMaximized;
		MultiSampleAntiAliasingMode msaa = MultiSampleAntiAliasingMode::Off;
	};
}
