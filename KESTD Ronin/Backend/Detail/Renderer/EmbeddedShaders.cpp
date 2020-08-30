// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// EmbeddedShaders.cpp
// 30.08.2020 12:40
// =============================================================

#include <cstdint>
#include "EmbeddedShaders.hpp"
#include "Shaders/GuiGenericVs.bin.inl"
#include "Shaders/GuiGenericFs.bin.inl"
#include "Shaders/GuiImageVs.bin.inl"
#include "Shaders/GuiImageFs.bin.inl"

namespace kestd::detail::renderer
{
	const bgfx::EmbeddedShader EmbeddedShaders[]
	{
		BGFX_EMBEDDED_SHADER(VS_GUI),
		BGFX_EMBEDDED_SHADER(FS_GUI),
		BGFX_EMBEDDED_SHADER(VS_GUI_IMAGE),
		BGFX_EMBEDDED_SHADER(FS_GUI_IMAGE),
		BGFX_EMBEDDED_SHADER_END(),
	};
}
