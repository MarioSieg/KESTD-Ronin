// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// GuiInput.hpp
// 30.08.2020 12:40
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
