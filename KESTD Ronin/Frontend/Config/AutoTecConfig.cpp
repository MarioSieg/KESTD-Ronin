// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// AutoTecConfig.cpp
// 28.08.2020 20:23
// =============================================================

#include "AutoTecConfig.hpp"

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
}
