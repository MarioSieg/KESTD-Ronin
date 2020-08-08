# CMakeList.txt : CMake project for KESTD Ronin, include source and define
# project specific logic here.

cmake_minimum_required (VERSION 3.8)

# Add engine:
add_library("KESTD" STATIC "Kernel/Kernel.hpp" "Kernel/Subsystem.hpp" "Kernel/Kernel.cpp" "Kernel/Subsystem.cpp" "Kernel/Security.hpp" "Kernel/Security.cpp" "Logger.hpp" "Platform.hpp" "Logger.cpp" "OsInfo.hpp" "OsInfo.cpp" "Sys.hpp" "Sys.cpp" "Drivers/Platform/Winput.hpp" "Drivers/Platform/Winput.cpp" "Kernel/Services.cpp" "OsInfo.hpp" "OsInfo.cpp" "Sys.hpp" "Sys.cpp" "Drivers/Platform/Winput.hpp" "Drivers/Platform/Winput.cpp" "Kernel/Services.cpp" "Drivers/Renderer/Renderer.hpp" "Drivers/Renderer/Renderer.cpp" "Drivers/Renderer/Context.hpp" "Drivers/Renderer/Context.cpp" "Drivers/SystemGui/SystemGui.hpp" "Drivers/SystemGui/Embedded.hpp" "Drivers/SystemGui/Embedded.cpp" "Drivers/SystemGui/SystemGui.cpp" "Drivers/SystemGui/SystemGuiInput.cpp" "Drivers/SystemGui/SystemGuiRenderer.cpp" "Drivers/Renderer/Utils.hpp" "Screen.hpp")

# Add extern libs:
include("Extern/CMakeLists.txt")

# Add AutoTec:
add_executable("AutoTec" "Entry.cpp")
target_link_libraries("AutoTec" "KESTD")
