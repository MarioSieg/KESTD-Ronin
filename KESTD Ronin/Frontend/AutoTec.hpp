// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// AutoTec.hpp
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
	class AutoTecTheme final
	{
		friend class AutoTec;
		
	public:
		/// <summary>
		/// Returns the current child rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getChildRounding() const noexcept -> float;

		/// <summary>
		/// Sets the current child rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <returns></returns>
		void setChildRounding(const float val) noexcept;

		/// <summary>
		/// Returns the current frame rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getFrameRounding() const noexcept -> float;

		/// <summary>
		/// Sets the current frame rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setFrameRounding(const float val) noexcept;

		/// <summary>
		/// Returns the current grab rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getGrabRounding() const noexcept -> float;

		/// <summary>
		/// Sets the current grab rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setGrabRounding(const float val) noexcept;

		/// <summary>
		/// Returns the current popup rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getPopupRounding() const noexcept -> float;

		/// <summary>
		/// Sets the current popup rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setPopupRounding(const float val) noexcept;

		/// <summary>
		/// Returns the current scrollbar rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getScrollbarRounding() const noexcept -> float;

		/// <summary>
		/// Sets the current scrollbar rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setScrollbarRounding(const float val) noexcept;

		/// <summary>
		/// Returns the current tab rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getTabRounding() const noexcept -> float;

		/// <summary>
		/// Sets the current tab rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setTabRounding(const float val) noexcept;

		/// <summary>
		/// Returns the current window rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getWindowRounding() const noexcept -> float;

		/// <summary>
		/// Sets the current window rounding. (Valid between 0.0f - 10.0f)
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setWindowRounding(const float val) noexcept;

		/// <summary>
		/// Returns the current colorTheme.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getColorTheme() const noexcept -> AutoTecColorTheme;

		/// <summary>
		/// Sets the new colorTheme.
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setColorTheme(const AutoTecColorTheme val) noexcept;

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
		/// Returns the current font size.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getFontSize() const noexcept -> std::uint8_t;

		/// <summary>
		/// Set the new font size.
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		void setFontSize(const std::uint8_t val) noexcept;

		/// <summary>
		/// Returns the current colorTheme.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getTheme() noexcept -> AutoTecTheme&;

		/// <summary>
		/// Returns the current colorTheme.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getTheme() const noexcept -> const AutoTecTheme&;

		/// <summary>
		/// Sets the current colorTheme to a whole new one.
		/// </summary>
		/// <param name="newtheme"></param>
		void setTheme(const AutoTecTheme& newtheme) noexcept;
		
	private:
		std::uint8_t fontSize = 18;
		AutoTecTheme theme;
	};
}
