// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Gui.hpp
// 30.08.2020 12:40
// =============================================================

#pragma once

#include <cstdint>
#include "../Platform/GuiInput.hpp"
#include "../Renderer/GuiRenderer.hpp"

struct ImGuiContext;
struct ImPlotContext;

namespace kestd::detail::systemgui
{
	class SystemGui final
	{
	public:
		SystemGui(std::uint8_t fontSize, std::uint16_t width, std::uint16_t heigth); //TODO Replace with Resolution
		SystemGui(const SystemGui&) = delete;
		SystemGui(SystemGui&) = delete;
		auto operator=(const SystemGui&) -> SystemGui& = delete;
		auto operator=(SystemGui&&) -> SystemGui& = delete;
		~SystemGui();

		void beginFrame();
		void endFrame() const;

	private:
		void beginDockSpace() const;
		void endDockSpace() const;
		ImGuiContext* guiContext;
		ImPlotContext* plotContext;
		renderer::SystemGuiRenderer renderer;
		platform::SystemGuiInput input;
	};
}
