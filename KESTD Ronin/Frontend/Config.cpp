// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Config.cpp
// 31.08.2020 15:10
// =============================================================

#include "Export/KESTD/Config.hpp"
#include "Export/KESTD/Platform.hpp"

namespace kestd
{
	auto AutoTecTheme::getChildRounding() const noexcept -> float
	{
		return childRounding;
	}

	void AutoTecTheme::setChildRounding(const float val) noexcept
	{
		childRounding = val;
	}

	auto AutoTecTheme::getFrameRounding() const noexcept -> float
	{
		return frameRounding;
	}

	void AutoTecTheme::setFrameRounding(const float val) noexcept
	{
		frameRounding = val;
	}

	auto AutoTecTheme::getGrabRounding() const noexcept -> float
	{
		return grabRounding;
	}

	void AutoTecTheme::setGrabRounding(const float val) noexcept
	{
		grabRounding = val;
	}

	auto AutoTecTheme::getPopupRounding() const noexcept -> float
	{
		return popupRounding;
	}

	void AutoTecTheme::setPopupRounding(const float val) noexcept
	{
		popupRounding = val;
	}

	auto AutoTecTheme::getScrollbarRounding() const noexcept -> float
	{
		return scrollbarRounding;
	}

	void AutoTecTheme::setScrollbarRounding(const float val) noexcept
	{
		scrollbarRounding = val;
	}

	auto AutoTecTheme::getTabRounding() const noexcept -> float
	{
		return tabRounding;
	}

	void AutoTecTheme::setTabRounding(const float val) noexcept
	{
		tabRounding = val;
	}

	auto AutoTecTheme::getWindowRounding() const noexcept -> float
	{
		return windowRounding;
	}

	void AutoTecTheme::setWindowRounding(const float val) noexcept
	{
		windowRounding = val;
	}

	auto AutoTecTheme::getColorTheme() const noexcept -> AutoTecColorTheme
	{
		return colorTheme;
	}

	void AutoTecTheme::setColorTheme(const AutoTecColorTheme val) noexcept
	{
		colorTheme = val;
	}

	auto AutoTecConfig::getFontSize() const noexcept -> std::uint8_t
	{
		return fontSize;
	}

	void AutoTecConfig::setFontSize(const std::uint8_t val) noexcept
	{
		fontSize = val;
	}

	auto AutoTecConfig::getTheme() noexcept -> AutoTecTheme&
	{
		return theme;
	}

	auto AutoTecConfig::getTheme() const noexcept -> const AutoTecTheme&
	{
		return theme;
	}

	void AutoTecConfig::setTheme(const AutoTecTheme& newtheme) noexcept
	{
		theme = newtheme;
	}

	auto Config::getConfigForAutoTec() const noexcept -> const AutoTecConfig&
	{
		return autoTec;
	}

	auto Config::getConfigForAutoTec() noexcept -> AutoTecConfig&
	{
		return autoTec;
	}

	auto Config::getConfigForIo() const noexcept -> const IoConfig&
	{
		return io;
	}

	auto Config::getConfigForIo() noexcept -> IoConfig&
	{
		return io;
	}

	auto Config::getConfigForGraphics() const noexcept -> const GraphicsConfig&
	{
		return graphics;
	}

	auto Config::getConfigForGraphics() noexcept -> GraphicsConfig&
	{
		return graphics;
	}

	auto getPrefferedPlatformGraphicsApi(const bool modern) noexcept -> GraphicsApi
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

	auto IoConfig::getRequiredDirectories() noexcept -> std::vector<std::tuple<
		std::filesystem::path, DirectoryMissingAction>>&
	{
		return requiredDirectories;
	}

	auto IoConfig::getRequiredDirectories() const noexcept -> const std::vector<std::tuple<
		std::filesystem::path, DirectoryMissingAction>>&
	{
		return requiredDirectories;
	}

	void IoConfig::setRequiredDirectories(
		std::vector<std::tuple<std::filesystem::path, DirectoryMissingAction>>&& val) noexcept
	{
		requiredDirectories = std::move(val);
	}

	auto IoConfig::getWorkingDir() const noexcept -> const std::filesystem::path&
	{
		return workingDir;
	}

	void IoConfig::setWorkingDir(std::filesystem::path&& val) noexcept
	{
		workingDir = std::move(val);
	}
}
