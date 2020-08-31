Warning!
Many 3rd party libraries do have modified build files. So please only update them manuallyif you know what your are doing!
Just update to a new KESTD Ronin version or contant MarioSieg for library updates (support@kerbogames.com)

Modified 31.08.2020:

==============================================================================
Added:
	"imgui/implot.h"
	"imgui/implot.cpp"
	"imgui/implot_demo.cpp"
	"imgui/implot_internal.h"
	"imgui/implot_items.cpp"
	"imgui/text_editor.h"
	"imgui/text_editor.cpp"
To:
	"imgui/CMakeLists.txt" -> Is a custom file! Do NOT delete it!
==============================================================================
Changed options:
	"INFOWARE_USE_D3D"
	"INFOWARE_USE_OPENGL"
To:
	ON by default on Windows
	ON by default on non Windows
==============================================================================
"bgfx/"
Contains a custom bgfx for CMake repo.
bgfx, bimg and bx themselfes are located in subdirectories in bgfx/
So to update them, only replace the files in the subdirs:
bgfx/bx
bgfx/bimg
bgfx/bgfx
Changed options:
	"BGFX_BUILD_TOOLS"
	"BGFX_BUILD_EXAMPLES"
To:
	OFF by default
==============================================================================
Added a custom CMakeLists.txt to:
"nativefiledialog/CMakeLists.txt"