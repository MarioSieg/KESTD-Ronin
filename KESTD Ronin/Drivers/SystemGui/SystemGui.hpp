// =============================================================
// © Copyright KerboGames®, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// SystemGui.hpp
// 08.08.2020 00:58
// =============================================================

#pragma once

#include "../../Logger.hpp"
#include <bgfx/bgfx.h>
#include <imgui.h>
#include <cstdint>
#include <cstddef>

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

		struct FontRangeMerge final
		{
			const void* Data = nullptr;
			std::size_t Size = 0;
			ImWchar Ranges[3] = {};
		};

		class SystemGui final
		{
		public:
			void Initialize();
			void BeginGui();
			void EndGui();
			void Shutdown() const;
			void ApplyStyle(const Style sty);

		private:
			void InitializeInput();
			void ShutdownInput();
			void BeginInput();
			void UpdateMouse();
			void UpdateGamepads();
			void InstallCallbackProcPtrs();
			void InitializeRendering();
			void ShutdownRendering() const;
			void RenderDrawData() const;

			ImGuiContext* Context = nullptr;
			ImFont* Font = nullptr;
			FontRangeMerge FontRangeMerge = {};
			std::int64_t Last = 0;
			std::int32_t LastScroll = 0;
			bgfx::VertexLayout Layout = {};
			bgfx::ProgramHandle GuiProgram = {};
			bgfx::ProgramHandle GuiImageProgram = {};
			bgfx::UniformHandle TextureUniform = {};
			bgfx::TextureHandle Texture = {};
			bgfx::UniformHandle ImageLodEnabled = {};
		};
	}
}
