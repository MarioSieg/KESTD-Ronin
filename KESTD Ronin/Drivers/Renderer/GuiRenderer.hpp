// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// GuiRenderer.hpp
// 10.08.2020 14:09
// =============================================================

#pragma once

#include <imgui.h>
#include <bgfx/bgfx.h>
#include <cstddef>

namespace kestd::drivers
{
	struct FontRangeMerge final
	{
		const void* data = nullptr;
		std::size_t size = 0;
		ImWchar ranges[3] = {};
	};

	class SystemGuiRenderer final
	{
	public:
		SystemGuiRenderer();
		~SystemGuiRenderer();
		void draw(const ImDrawData* const data) const;

	private:
		ImFont* font = nullptr;
		FontRangeMerge fontRangeMerge = {};
		bgfx::VertexLayout layout = {};
		bgfx::ProgramHandle guiProgram = {};
		bgfx::ProgramHandle guiImageProgram = {};
		bgfx::UniformHandle textureUniform = {};
		bgfx::TextureHandle texture = {};
		bgfx::UniformHandle imageLodEnabled = {};
	};
}
