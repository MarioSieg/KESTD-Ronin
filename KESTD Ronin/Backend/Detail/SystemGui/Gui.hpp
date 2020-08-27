// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Gui.hpp
// 09.08.2020 07:24
// =============================================================

#pragma once

#include <imgui.h>


#include "../../../Frontend/AutoTec.hpp"
#include "../Platform/GuiInput.hpp"
#include "../Renderer/GuiRenderer.hpp"

namespace kestd::detail::sysgui
{
	class SystemGui final
	{
	public:
		SystemGui(const std::size_t fontSize);
		SystemGui(const SystemGui&) = delete;
		SystemGui(SystemGui&) = delete;
		auto operator=(const SystemGui&) -> SystemGui& = delete;
		auto operator=(SystemGui&&) -> SystemGui& = delete;
		~SystemGui();

		void beginFrame();
		void endFrame() const;
		static void ApplyTheme(const AutoTecTheme& sty, const bool applyColors = true);

	private:
		void beginDockSpace() const;
		void endDockSpace() const;
		ImGuiContext* context{ImGui::CreateContext()};
		SystemGuiRenderer renderer;
		SystemGuiInput input;
	};
}
