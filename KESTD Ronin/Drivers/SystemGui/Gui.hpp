// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// Gui.hpp
// 09.08.2020 07:24
// =============================================================

#pragma once

#include <imgui.h>

#include "../Platform/GuiInput.hpp"
#include "../Renderer/GuiRenderer.hpp"

namespace kestd
{
	namespace drivers
	{
		enum class Style
		{
			Dark,
			Light,
			Blue,
			Cherry,
			Green,
		};

		class SystemGui final
		{
		public:
			SystemGui();
			SystemGui(const SystemGui&) = delete;
			SystemGui(SystemGui&) = delete;
			auto operator=(const SystemGui&) -> SystemGui& = delete;
			auto operator=(SystemGui&&) -> SystemGui& = delete;
			~SystemGui();

			void begin();
			void end() const;
			void applyStyle(const Style sty);

		private:
			ImGuiContext* context{ImGui::CreateContext()};
			SystemGuiRenderer renderer;
			SystemGuiInput input;
		};
	}
}
