#pragma once

#include <cstdint>
#include <string_view>
#include <filesystem>

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
		auto getTheme() noexcept -> AutoTecTheme&;

		/// <summary>
		///
		/// </summary>
		/// <returns>The current colorTheme.</returns>
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

	// <summary>
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
	class GraphicsConfig final
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

	enum class SystemDirs
	{
		SystemDataBase,
		Protocol,
		Config,
		Count,
	};

	enum class DirectoryMissingAction
	{
		Create,
		Throw
	};

	class IoConfig final
	{
	public:
		static constexpr std::string_view DataBaseDir = "DB";
		static constexpr std::string_view ConfigurationDir = "Config";
		static constexpr std::string_view ProtocolDir = "Proto";

		/// <summary>
		/// Returns all required directories. These directories must exist in the working directory!
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto getRequiredDirectories() noexcept -> std::vector<std::tuple<std::filesystem::path, DirectoryMissingAction>
		>&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>All required directories. These directories must exist in the working directory!</returns>
		[[nodiscard]]
		auto getRequiredDirectories() const noexcept -> const std::vector<std::tuple<
			std::filesystem::path, DirectoryMissingAction>>&;

		/// <summary>
		/// Sets all required directories. These directories must exist in the working directory!
		/// </summary>
		/// <returns></returns>
		void setRequiredDirectories(
			std::vector<std::tuple<std::filesystem::path, DirectoryMissingAction>>&& val) noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Working directory which will be entered on boot.</returns>
		[[nodiscard]]
		auto getWorkingDir() const noexcept -> const std::filesystem::path&;

		/// <summary>
		/// Sets working directory which will be entered on boot.
		/// </summary>
		/// <returns></returns>
		void setWorkingDir(std::filesystem::path&& val) noexcept;

	private:
		std::filesystem::path workingDir = "../";
		std::vector<std::tuple<std::filesystem::path, DirectoryMissingAction>> requiredDirectories
		{
			{DataBaseDir, DirectoryMissingAction::Throw},
			{ConfigurationDir, DirectoryMissingAction::Create},
			{ProtocolDir, DirectoryMissingAction::Create},
		};
	};

	/// <summary>
	/// Contains the full engine boot configuration.
	/// </summary>
	class Config final
	{
		friend class AutoTec;
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <returns>The boot config for the AutoTec editor.</returns>
		[[nodiscard]]
		auto getConfigForAutoTec() const noexcept -> const AutoTecConfig&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The boot config for the AutoTec editor.</returns>
		[[nodiscard]]
		auto getConfigForAutoTec() noexcept -> AutoTecConfig&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The boot config for disk input output.</returns>
		[[nodiscard]]
		auto getConfigForIo() const noexcept -> const IoConfig&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The boot config for disk input output.</returns>
		[[nodiscard]]
		auto getConfigForIo() noexcept -> IoConfig&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The boot config for graphics and display.</returns>
		[[nodiscard]]
		auto getConfigForGraphics() const noexcept -> const GraphicsConfig&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The boot config for graphics and display.</returns>
		[[nodiscard]]
		auto getConfigForGraphics() noexcept -> GraphicsConfig&;

	private:
		AutoTecConfig autoTec = {};
		IoConfig io = {};
		GraphicsConfig graphics = {};
	};
}