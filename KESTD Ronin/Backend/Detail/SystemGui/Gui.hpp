// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Gui.hpp
// 09.08.2020 07:24
// =============================================================

#pragma once

#include "../../../Frontend/AutoTec.hpp"
#include "../Platform/GuiInput.hpp"
#include "../Renderer/GuiRenderer.hpp"

struct ImGuiContext;
struct ImPlotContext;

namespace kestd::detail::systemgui
{
	class SystemGui final
	{
	public:
		SystemGui(std::size_t fontSize);
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
