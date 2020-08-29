// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// ConfigGraphics.cpp
// 29.08.2020 13:49
// =============================================================

#include "ConfigGraphics.hpp"
#include "Platform.hpp"

namespace kestd
{
	auto GetPrefferedPlatformGraphicsApi(const bool modern) noexcept -> GraphicsApi
	{
#if SYS_WINDOWS
		return modern ? GraphicsApi::Direct3D12 : GraphicsApi::Direct3D11;
#elif SYS_LINUX
		return modern ? GraphicsApi::Vulkan : GraphicsApi::OpenGL3;
#elif SYS_MAC
		return modern ? GraphicsApi::Metal : GraphicsApi::OpenGL3;;
#endif
	}

	auto ConfigGraphics::getGraphicsApi() const noexcept -> GraphicsApi
	{
		return api;
	}

	void ConfigGraphics::setGraphicsApi(const GraphicsApi val) noexcept
	{
		api = val;
	}

	auto ConfigGraphics::getWidth() const noexcept -> std::uint16_t
	{
		return width;
	}

	void ConfigGraphics::setWidth(const std::uint16_t val) noexcept
	{
		width = val;
	}

	auto ConfigGraphics::getHeight() const noexcept -> std::uint16_t
	{
		return height;
	}

	void ConfigGraphics::setHeight(const std::uint16_t val) noexcept
	{
		height = val;
	}

	auto ConfigGraphics::getWindowMode() const noexcept -> WindowMode
	{
		return windowMode;
	}

	void ConfigGraphics::setWindowMode(const WindowMode mode) noexcept
	{
		windowMode = mode;
	}

	auto ConfigGraphics::getMsaaMode() const noexcept -> MultiSampleAntiAliasingMode
	{
		return msaa;
	}

	void ConfigGraphics::setMsaaMode(const MultiSampleAntiAliasingMode mode) noexcept
	{
		msaa = mode;
	}
}
