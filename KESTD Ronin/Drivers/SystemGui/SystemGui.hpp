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
			const void* data = nullptr;
			std::size_t size = 0;
			ImWchar ranges[3] = {};
		};

		class SystemGui final
		{
		public:
			void initialize();
			void beginGui();
			void endGui();
			void shutdown() const;
			void applyStyle(const Style sty);

		private:
			void initializeInput();
			void shutdownInput();
			void beginInput();
			void updateMouse();
			void updateGamepads();
			void installCallbackProcPtrs();
			void initializeRendering();
			void shutdownRendering() const;
			void renderDrawData() const;

			ImGuiContext* context = nullptr;
			ImFont* font = nullptr;
			FontRangeMerge fontRangeMerge = {};
			std::int64_t last = 0;
			std::int32_t lastScroll = 0;
			bgfx::VertexLayout layout = {};
			bgfx::ProgramHandle guiProgram = {};
			bgfx::ProgramHandle guiImageProgram = {};
			bgfx::UniformHandle textureUniform = {};
			bgfx::TextureHandle texture = {};
			bgfx::UniformHandle imageLodEnabled = {};
		};
	}
}
