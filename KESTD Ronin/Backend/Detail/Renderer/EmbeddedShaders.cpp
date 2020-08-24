// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// EmbeddedShaders.cpp
// 09.08.2020 07:24
// =============================================================

#include <cstdint>
#include "EmbeddedShaders.hpp"
#include "Shaders/GuiGenericVs.bin.inl"
#include "Shaders/GuiGenericFs.bin.inl"
#include "Shaders/GuiImageVs.bin.inl"
#include "Shaders/GuiImageFs.bin.inl"

const bgfx::EmbeddedShader INTERNAL_SHADERS[]
{
	BGFX_EMBEDDED_SHADER(VS_GUI),
	BGFX_EMBEDDED_SHADER(FS_GUI),
	BGFX_EMBEDDED_SHADER(VS_GUI_IMAGE),
	BGFX_EMBEDDED_SHADER(FS_GUI_IMAGE),
	BGFX_EMBEDDED_SHADER_END(),
};
