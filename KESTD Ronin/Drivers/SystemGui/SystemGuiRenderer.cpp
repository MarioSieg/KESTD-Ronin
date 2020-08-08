#include <algorithm>
#include "Embedded.hpp"
#include "RobotoRegular.ttf.inl"
#include "IconsFontAwesome5.hpp"
#include "SystemGui.hpp"
#include "../Renderer/Utils.hpp"
#include <bx/math.h>

namespace kestd::drivers
{
	constexpr bgfx::ViewId GUI_VIEW_ID = 0xff;
	
	void SystemGui::InitializeRendering()
	{
		auto& io = ImGui::GetIO();
		const auto type = bgfx::getRendererType();
		GuiProgram = bgfx::createProgram(
			createEmbeddedShader(INTERNAL_SHADERS, type, "VS_GUI"),
			createEmbeddedShader(INTERNAL_SHADERS, type, "FS_GUI"),
			true
		);

		ImageLodEnabled = createUniform("u_imageLodEnabled", bgfx::UniformType::Vec4);

		GuiImageProgram = createProgram(
			createEmbeddedShader(INTERNAL_SHADERS, type, "VS_GUI_IMAGE"),
			createEmbeddedShader(INTERNAL_SHADERS, type, "FS_GUI_IMAGE"),
			true
		);

		Layout
			.begin()
			.add(bgfx::Attrib::Position, 2, bgfx::AttribType::Float)
			.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
			.add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
			.end();

		TextureUniform = createUniform("s_tex", bgfx::UniformType::Sampler);

		std::uint8_t* data;
		std::int32_t lwidth;
		std::int32_t lheight;
		{
			ImFontConfig config;
			config.FontDataOwnedByAtlas = false;
			config.MergeMode = false;

			const ImWchar* ranges = io.Fonts->GetGlyphRangesCyrillic();
			Font = io.Fonts->AddFontFromMemoryTTF((void*)ROBOTO_REGULAR,
				sizeof ROBOTO_REGULAR,
				18,
				&config,
				ranges);

			config.MergeMode = true;
			config.DstFont = Font;

			FontRangeMerge.Data = ROBOTO_REGULAR;
			FontRangeMerge.Size = sizeof ROBOTO_REGULAR;
			FontRangeMerge.Ranges[0] = ICON_MIN_FA;
			FontRangeMerge.Ranges[1] = ICON_MAX_FA;
			FontRangeMerge.Ranges[2] = 0;

			io.Fonts->AddFontFromMemoryTTF(const_cast<void*>(FontRangeMerge.Data),
				static_cast<int>(FontRangeMerge.Size),
				18 - 3.0f,
				&config,
				FontRangeMerge.Ranges
			);
		}

		io.Fonts->GetTexDataAsRGBA32(&data, &lwidth, &lheight);

		Texture = createTexture2D(
			static_cast<uint16_t>(lwidth),
			static_cast<uint16_t>(lheight),
			false,
			1,
			bgfx::TextureFormat::BGRA8,
			0,
			bgfx::copy(data, lwidth * lheight * 4)
		);
	}

	void SystemGui::ShutdownRendering()
	{
		destroy(TextureUniform);
		destroy(ImageLodEnabled);
		destroy(GuiProgram);
		destroy(GuiImageProgram);
	}

	void SystemGui::BeginRendering()
	{
		ImGui::NewFrame();
		ImGui::ShowDemoWindow();
	}

	void SystemGui::Render()
	{
		ImGui::Render();
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

			if (!CheckAvailTransientBuffers(vertexCount, Layout, indexCount))
			{
				break;
			}

			bgfx::TransientVertexBuffer tvb;
			bgfx::TransientIndexBuffer tib;

			allocTransientVertexBuffer(&tvb, vertexCount, Layout);
			allocTransientIndexBuffer(&tib, indexCount);

			auto* const vertices = reinterpret_cast<ImDrawVert*>(tvb.data);
			auto* const indices = reinterpret_cast<ImDrawIdx*>(tib.data);

			memcpy(vertices, drawList->VtxBuffer.begin(), vertexCount * sizeof(ImDrawVert));
			memcpy(indices, drawList->IdxBuffer.begin(), indexCount * sizeof(ImDrawIdx));

			std::uint32_t offset = 0;
			for (const auto* cmd = drawList->CmdBuffer.begin(), *end = drawList->CmdBuffer.end(); cmd != end; ++cmd)
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

					auto textureHandle = Texture;
					auto program = GuiProgram;

					if (cmd->TextureId)
					{
						const union
						{
							ImTextureID ptr;

							struct
							{
								bgfx::TextureHandle Handle;
								uint8_t Flags;
								uint8_t Mip;
							} s;
						}
						texture = { cmd->TextureId };
						state |= 0x01 & texture.s.Flags
							? BGFX_STATE_BLEND_FUNC(BGFX_STATE_BLEND_SRC_ALPHA, BGFX_STATE_BLEND_INV_SRC_ALPHA)
							: BGFX_STATE_NONE;
						textureHandle = texture.s.Handle;
						if (texture.s.Mip)
						{
							const float lodEnabled[4] = { static_cast<float>(texture.s.Mip), 1.f, .0f, .0f };
							setUniform(ImageLodEnabled, lodEnabled);
							program = GuiImageProgram;
						}
					}
					else
					{
						state |= BGFX_STATE_BLEND_FUNC(BGFX_STATE_BLEND_SRC_ALPHA, BGFX_STATE_BLEND_INV_SRC_ALPHA);
					}

					const auto xx = uint16_t(std::max(cmd->ClipRect.x, .0f));
					const auto yy = uint16_t(std::max(cmd->ClipRect.y, .0f));
					bgfx::setScissor(xx,
						yy,
						uint16_t(std::min(cmd->ClipRect.z, 65535.f) - xx),
						uint16_t(std::min(cmd->ClipRect.w, 65535.f) - yy)
					);

					bgfx::setState(state);
					setTexture(0, TextureUniform, textureHandle);
					setVertexBuffer(0, &tvb, 0, vertexCount);
					setIndexBuffer(&tib, offset, cmd->ElemCount);
					submit(GUI_VIEW_ID, program);
				}
				offset += cmd->ElemCount;
			}
		}
	}
}
