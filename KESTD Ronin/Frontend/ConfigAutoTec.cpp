// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// ConfigAutoTec.cpp
// 28.08.2020 20:23
// =============================================================

#include "ConfigAutoTec.hpp"

namespace kestd
{
	auto ConfigAutoTec::getChildRounding() const noexcept -> float
	{
		return childRounding;
	}

	void ConfigAutoTec::setChildRounding(const float val) noexcept
	{
		childRounding = val;
	}

	auto ConfigAutoTec::getFrameRounding() const noexcept -> float
	{
		return frameRounding;
	}

	void ConfigAutoTec::setFrameRounding(const float val) noexcept
	{
		frameRounding = val;
	}

	auto ConfigAutoTec::getGrabRounding() const noexcept -> float
	{
		return grabRounding;
	}

	void ConfigAutoTec::setGrabRounding(const float val) noexcept
	{
		grabRounding = val;
	}

	auto ConfigAutoTec::getPopupRounding() const noexcept -> float
	{
		return popupRounding;
	}

	void ConfigAutoTec::setPopupRounding(const float val) noexcept
	{
		popupRounding = val;
	}

	auto ConfigAutoTec::getScrollbarRounding() const noexcept -> float
	{
		return scrollbarRounding;
	}

	void ConfigAutoTec::setScrollbarRounding(const float val) noexcept
	{
		scrollbarRounding = val;
	}

	auto ConfigAutoTec::getTabRounding() const noexcept -> float
	{
		return tabRounding;
	}

	void ConfigAutoTec::setTabRounding(const float val) noexcept
	{
		tabRounding = val;
	}

	auto ConfigAutoTec::getWindowRounding() const noexcept -> float
	{
		return windowRounding;
	}

	void ConfigAutoTec::setWindowRounding(const float val) noexcept
	{
		windowRounding = val;
	}

	auto ConfigAutoTec::getColorTheme() const noexcept -> AutoTecColorTheme
	{
		return colorTheme;
	}

	void ConfigAutoTec::setColorTheme(const AutoTecColorTheme val) noexcept
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

	auto AutoTecConfig::getTheme() noexcept -> ConfigAutoTec&
	{
		return theme;
	}

	auto AutoTecConfig::getTheme() const noexcept -> const ConfigAutoTec&
	{
		return theme;
	}

	void AutoTecConfig::setTheme(const ConfigAutoTec& newtheme) noexcept
	{
		theme = newtheme;
	}
}
