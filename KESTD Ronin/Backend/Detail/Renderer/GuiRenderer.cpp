// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// GuiRenderer.cpp
// 31.08.2020 15:09
// =============================================================

#include "EmbeddedShaders.hpp"
#include "GuiRenderer.hpp"
#include "../Renderer/Utils.hpp"
#include <bx/math.h>
#include <imgui.h>
#include <algorithm>
#include <fontawesome/icons_font_awesome5.h>

namespace kestd::detail::renderer
{
	constexpr bgfx::ViewId GUI_VIEW_ID = 0xff;

	SystemGuiRenderer::SystemGuiRenderer(const std::size_t fontSize)
	{
		auto& io = ImGui::GetIO();
		const auto type = bgfx::getRendererType();
		guiProgram = createProgram(
			createEmbeddedShader(EmbeddedShaders, type, "VS_GUI"),
			createEmbeddedShader(EmbeddedShaders, type, "FS_GUI"),
			true
		);

		imageLodEnabled = createUniform("u_imageLodEnabled", bgfx::UniformType::Vec4);

		guiImageProgram = createProgram(
			createEmbeddedShader(EmbeddedShaders, type, "VS_GUI_IMAGE"),
			createEmbeddedShader(EmbeddedShaders, type, "FS_GUI_IMAGE"),
			true
		);

		layout
			.begin()
			.add(bgfx::Attrib::Position, 2, bgfx::AttribType::Float)
			.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
			.add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
			.end();

		textureUniform = createUniform("s_tex", bgfx::UniformType::Sampler);

		std::uint8_t* data;
		std::int32_t lwidth;
		std::int32_t lheight;
		{
			const auto* ranges = io.Fonts->GetGlyphRangesDefault();
			ImFontConfig config;
			config.FontDataOwnedByAtlas = false;
			config.MergeMode = false;

			io.Fonts->AddFontFromFileTTF("DB/Fonts/JetBrainsMono.ttf", fontSize - 3.f, &config, ranges);

			config.MergeMode = true;
			ImWchar mergeRanges[3] = {};

			mergeRanges[0] = ICON_MIN_FA;
			mergeRanges[1] = ICON_MAX_FA;
			io.Fonts->AddFontFromFileTTF("DB/Fonts/FontAwesome5.ttf", fontSize - 3.f, &config, mergeRanges);

			/*mergeRanges[0] = ICON_MIN_KI;
			mergeRanges[1] = ICON_MAX_KI;
			io.Fonts->AddFontFromFileTTF("DB/Fonts/KenneyIconFont.ttf", fontSize - 3.f, &config, mergeRanges);*/


			/*
			font = io.Fonts->AddFontFromMemoryTTF((void *)ROBOTO_REGULAR,
			                                      sizeof ROBOTO_REGULAR,
			                                      18,
			                                      &config,
			                                      ranges);
			*/

			config.MergeMode = false;
			config.DstFont = font;
		}


		io.Fonts->GetTexDataAsRGBA32(&data, &lwidth, &lheight);

		texture = createTexture2D(
			static_cast<uint16_t>(lwidth),
			static_cast<uint16_t>(lheight),
			false,
			1,
			bgfx::TextureFormat::BGRA8,
			0,
			bgfx::copy(data, lwidth * lheight * 4)
		);
	}

	SystemGuiRenderer::~SystemGuiRenderer()
	{
		destroy(textureUniform);
		destroy(imageLodEnabled);
		destroy(guiProgram);
		destroy(guiImageProgram);
	}

	void SystemGuiRenderer::draw(const ImDrawData* const data) const
	{
		const auto* const drawData = ImGui::GetDrawData();
		const auto& io = ImGui::GetIO();
		const auto width = static_cast<std::uint16_t>(io.DisplaySize.x);
		const auto height = static_cast<std::uint16_t>(io.DisplaySize.y);
		setViewMode(GUI_VIEW_ID, bgfx::ViewMode::Sequential);
		const auto& caps = *bgfx::getCaps();
		{
			float ortho[16];
			bx::mtxOrtho(ortho, .0f, width, height, .0f, .0f, 1000.f, .0f, caps.homogeneousDepth);
			bgfx::setViewTransform(GUI_VIEW_ID, nullptr, ortho);
			bgfx::setViewRect(GUI_VIEW_ID, 0, 0, width, height);
		}

		for (auto i = 0; i < drawData->CmdListsCount; ++i)
		{
			const auto* drawList = drawData->CmdLists[i];
			const auto vertexCount = drawList->VtxBuffer.size();
			const auto indexCount = drawList->IdxBuffer.size();

			if (!checkAvailTransientBuffers(vertexCount, layout, indexCount))
			{
				break;
			}

			bgfx::TransientVertexBuffer tvb;
			bgfx::TransientIndexBuffer tib;

			allocTransientVertexBuffer(&tvb, vertexCount, layout);
			allocTransientIndexBuffer(&tib, indexCount);

			auto* const vertices = reinterpret_cast<ImDrawVert *>(tvb.data);
			auto* const indices = reinterpret_cast<ImDrawIdx *>(tib.data);

			memcpy(vertices, drawList->VtxBuffer.begin(), vertexCount * sizeof(ImDrawVert));
			memcpy(indices, drawList->IdxBuffer.begin(), indexCount * sizeof(ImDrawIdx));

			std::uint32_t offset = 0;
			for (const auto* cmd = drawList->CmdBuffer.begin(),* end = drawList->CmdBuffer.end(); cmd != end; ++cmd)
			{
				if (cmd->UserCallback)
				{
					cmd->UserCallback(drawList, cmd);
				}
				else if (cmd->ElemCount)
				{
					auto state = BGFX_STATE_WRITE_RGB
						| BGFX_STATE_WRITE_A
						| BGFX_STATE_MSAA;

					auto textureHandle = texture;
					auto program = guiProgram;

					if (cmd->TextureId)
					{
						const union
						{
							ImTextureID ptr;

							struct
							{
								bgfx::TextureHandle handle;
								std::uint8_t flags;
								std::uint8_t mip;
							} S;
						}
							texture = {cmd->TextureId};
						state |= 0x01 & texture.S.flags
							         ? BGFX_STATE_BLEND_FUNC(BGFX_STATE_BLEND_SRC_ALPHA, BGFX_STATE_BLEND_INV_SRC_ALPHA)
							         : BGFX_STATE_NONE;
						textureHandle = texture.S.handle;
						if (texture.S.mip)
						{
							const float lodEnabled[4] = {static_cast<float>(texture.S.mip), 1.f, .0f, .0f};
							setUniform(imageLodEnabled, lodEnabled);
							program = guiImageProgram;
						}
					}
					else
					{
						state |= BGFX_STATE_BLEND_FUNC(BGFX_STATE_BLEND_SRC_ALPHA, BGFX_STATE_BLEND_INV_SRC_ALPHA);
					}

					const auto xx = std::uint16_t(std::max(cmd->ClipRect.x, .0f));
					const auto yy = std::uint16_t(std::max(cmd->ClipRect.y, .0f));
					bgfx::setScissor(xx,
					                 yy,
					                 std::uint16_t(std::min(cmd->ClipRect.z, 65535.f) - xx),
					                 std::uint16_t(std::min(cmd->ClipRect.w, 65535.f) - yy)
					);

					bgfx::setState(state);
					setTexture(0, textureUniform, textureHandle);
					setVertexBuffer(0, &tvb, 0, vertexCount);
					setIndexBuffer(&tib, offset, cmd->ElemCount);
					submit(GUI_VIEW_ID, program);
				}
				offset += cmd->ElemCount;
			}
		}
	}
}
