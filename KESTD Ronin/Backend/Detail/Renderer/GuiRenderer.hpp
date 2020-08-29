// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// GuiRenderer.hpp
// 10.08.2020 14:09
// =============================================================

#pragma once

#include <bgfx/bgfx.h>
#include <cstddef>

struct ImFont;
struct ImDrawData;

namespace kestd::detail::renderer
{
	class SystemGuiRenderer final
	{
	public:
		SystemGuiRenderer(std::size_t fontSize);
		~SystemGuiRenderer();
		void draw(const ImDrawData* data) const;

	private:
		ImFont* font = nullptr;
		bgfx::VertexLayout layout = {};
		bgfx::ProgramHandle guiProgram = {};
		bgfx::ProgramHandle guiImageProgram = {};
		bgfx::UniformHandle textureUniform = {};
		bgfx::TextureHandle texture = {};
		bgfx::UniformHandle imageLodEnabled = {};
	};
}
