# CMakeList.txt : CMake project for KESTD Ronin, include source and define
# project specific logic here.

cmake_minimum_required (VERSION 3.8)
set (CMAKE_CXX_STANDARD 20)

# Add engine:
add_library("KESTD" STATIC 
"Kernel/Kernel.hpp" 
"Kernel/Kernel.cpp" 
"Kernel/ISubsystem.hpp" 
"Kernel/ISubsystem.cpp" 
"Kernel/Security.hpp" 
"Kernel/Security.cpp" 
"Logger.hpp" 
"Platform.hpp" 
"Logger.cpp" 
"OsInfo.hpp" 
"OsInfo.cpp" 
"Sys.hpp" 
"Sys.cpp" 
"Kernel/Services.cpp" 
"OsInfo.hpp" 
"OsInfo.cpp" 
"Sys.hpp" 
"Sys.cpp" 
"Drivers/Platform/WindowSystem.hpp" 
"Drivers/Platform/WindowSystem.cpp" 
"Kernel/Services.cpp" 
"Drivers/Renderer/RenderSystem.hpp" 
"Drivers/Renderer/RenderSystem.cpp" 
"Drivers/Renderer/Context.hpp" 
"Drivers/Renderer/Context.cpp" 
"Drivers/SystemGui/Gui.hpp" 
"Drivers/Renderer/EmbeddedShaders.hpp" 
"Drivers/Renderer/EmbeddedShaders.cpp" 
"Drivers/SystemGui/Gui.cpp" 
"Drivers/Platform/GuiInput.cpp" 
"Drivers/Renderer/GuiRenderer.cpp"
"Drivers/Renderer/Utils.hpp" 
"Screen.hpp"  
"Drivers/SystemGui/SystemGuiStyle.cpp"  
"Drivers/AutoTec/AutoTecSystem.hpp" 
"Drivers/AutoTec/Terminal.cpp" 
"Drivers/AutoTec/UI/UI.hpp" 
"Drivers/AutoTec/AutoTecSystem.cpp" 
"Drivers/AutoTec/Menu.cpp" 
"Drivers/Platform/Callbacks.hpp" 
"Drivers/Platform/Callbacks.cpp" 
"Drivers/Renderer/Drivers.hpp" 
"Drivers/Renderer/Drivers.cpp" 
"Drivers/Renderer/Utils.cpp" 
"Drivers/Platform/GuiInput.hpp"
)

# Add extern libs:
include("Extern/CMakeLists.txt")

# Add AutoTec:
add_executable("AutoTec" "Entry.cpp")
target_link_libraries("AutoTec" "KESTD")
