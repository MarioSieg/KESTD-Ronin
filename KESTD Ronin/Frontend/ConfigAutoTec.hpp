// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// ConfigAutoTec.hpp
// 26.08.2020 00:19
// =============================================================

#pragma once

#include <cstdint>

namespace kestd
{
	/// <summary>
	/// Represents a basic color theme.
	/// </summary>
	enum class AutoTecColorTheme
	{
		Dark,
		Light,
		Blue,
		Cherry,
		Green,
	};

	/// <summary>
	/// Represents a style and color theme for the AutoTec and terminal gui.
	/// </summary>
	class ConfigAutoTec final
	{
		friend class AutoTec;

	public:
		/// <summary>
		///
		/// </summary>
		/// <returns>The current child rounding. (Valid between 0.0f - 10.0f)</returns>
		[[nodiscard]]
		auto getChildRounding() const noexcept -> float;

		/// <summary>
		/// Sets the current child rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <returns></returns>
		void setChildRounding(float val) noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current frame rounding. (Valid between 0.0f - 10.0f)</returns>
		[[nodiscard]]
		auto getFrameRounding() const noexcept -> float;

		/// <summary>
		/// Sets the current frame rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setFrameRounding(float val) noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current grab rounding. (Valid between 0.0f - 10.0f)</returns>
		[[nodiscard]]
		auto getGrabRounding() const noexcept -> float;

		/// <summary>
		/// Sets the current grab rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setGrabRounding(float val) noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current popup rounding. (Valid between 0.0f - 10.0f)</returns>
		[[nodiscard]]
		auto getPopupRounding() const noexcept -> float;

		/// <summary>
		/// Sets the current popup rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setPopupRounding(float val) noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current scrollbar rounding. (Valid between 0.0f - 10.0f)</returns>
		[[nodiscard]]
		auto getScrollbarRounding() const noexcept -> float;

		/// <summary>
		/// Sets the current scrollbar rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setScrollbarRounding(float val) noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current tab rounding. (Valid between 0.0f - 10.0f)</returns>
		[[nodiscard]]
		auto getTabRounding() const noexcept -> float;

		/// <summary>
		/// Sets the current tab rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setTabRounding(float val) noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current window rounding. (Valid between 0.0f - 10.0f)</returns>
		[[nodiscard]]
		auto getWindowRounding() const noexcept -> float;

		/// <summary>
		/// Sets the current window rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setWindowRounding(float val) noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current colorTheme.</returns>
		[[nodiscard]]
		auto getColorTheme() const noexcept -> AutoTecColorTheme;

		/// <summary>
		/// Sets the new colorTheme.
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setColorTheme(AutoTecColorTheme val) noexcept;

	private:
		float childRounding = .0f;
		float frameRounding = .0f;
		float grabRounding = .0f;
		float popupRounding = .0f;
		float scrollbarRounding = .0f;
		float tabRounding = .0f;
		float windowRounding = .0f;
		AutoTecColorTheme colorTheme = AutoTecColorTheme::Dark;
	};

	/// <summary>
	/// Contains configuration parameters for the AutoTec editor (and terminal).
	/// </summary>
	class AutoTecConfig final
	{
		friend class AutoTec;
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current font size.</returns>
		[[nodiscard]]
		auto getFontSize() const noexcept -> std::uint8_t;

		/// <summary>
		/// Set the new font size.
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setFontSize(std::uint8_t val) noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current colorTheme.</returns>
		[[nodiscard]]
		auto getTheme() noexcept -> ConfigAutoTec&;

		/// <summary>
		///
		/// </summary>
		/// <returns>The current colorTheme.</returns>
		[[nodiscard]]
		auto getTheme() const noexcept -> const ConfigAutoTec&;

		/// <summary>
		/// Sets the current colorTheme to a whole new one.
		/// </summary>
		/// <param name="newtheme"></param>
		void setTheme(const ConfigAutoTec& newtheme) noexcept;

	private:
		std::uint8_t fontSize = 18;
		ConfigAutoTec theme;
	};
}
