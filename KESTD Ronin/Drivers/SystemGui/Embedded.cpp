// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD Ronin
// Mario
// InternalShaders.cpp
// 08.08.2020 01:22

#include <cstdint>
#include "Embedded.hpp"
#include "GuiGenericVs.bin.inl"
#include "GuiGenericFs.bin.inl"
#include "GuiImageVs.bin.inl"
#include "GuiImageFs.bin.inl"

const bgfx::EmbeddedShader INTERNAL_SHADERS[]
{
	BGFX_EMBEDDED_SHADER(VS_GUI),
	BGFX_EMBEDDED_SHADER(FS_GUI),
	BGFX_EMBEDDED_SHADER(VS_GUI_IMAGE),
	BGFX_EMBEDDED_SHADER(FS_GUI_IMAGE),
	BGFX_EMBEDDED_SHADER_END(),
};
