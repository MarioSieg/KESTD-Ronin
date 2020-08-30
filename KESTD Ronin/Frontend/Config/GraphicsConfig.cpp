// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// GraphicsConfig.cpp
// 29.08.2020 13:49
// =============================================================

#include "GraphicsConfig.hpp"
#include "../Platform.hpp"

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

	auto GraphicsConfig::getGraphicsApi() const noexcept -> GraphicsApi
	{
		return api;
	}

	void GraphicsConfig::setGraphicsApi(const GraphicsApi val) noexcept
	{
		api = val;
	}

	auto GraphicsConfig::getWidth() const noexcept -> std::uint16_t
	{
		return width;
	}

	void GraphicsConfig::setWidth(const std::uint16_t val) noexcept
	{
		width = val;
	}

	auto GraphicsConfig::getHeight() const noexcept -> std::uint16_t
	{
		return height;
	}

	void GraphicsConfig::setHeight(const std::uint16_t val) noexcept
	{
		height = val;
	}

	auto GraphicsConfig::getWindowMode() const noexcept -> WindowMode
	{
		return windowMode;
	}

	void GraphicsConfig::setWindowMode(const WindowMode mode) noexcept
	{
		windowMode = mode;
	}

	auto GraphicsConfig::getMsaaMode() const noexcept -> MultiSampleAntiAliasingMode
	{
		return msaa;
	}

	void GraphicsConfig::setMsaaMode(const MultiSampleAntiAliasingMode mode) noexcept
	{
		msaa = mode;
	}
}
