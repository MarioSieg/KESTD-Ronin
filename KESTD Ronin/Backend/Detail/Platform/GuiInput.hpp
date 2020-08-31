// =============================================================
// (C) Copyright KerboGames(R) Mario Sieg, Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// GuiInput.hpp
// 31.08.2020 15:09
// =============================================================

#pragma once

namespace kestd::detail::platform
{
	class SystemGuiInput final
	{
	public:
		SystemGuiInput();
		~SystemGuiInput();
		void update();

	private:
		void updateMouse();
		void updateCursor();
		void updateGamepads();
		void installCallbackProcedures();
	};
}
