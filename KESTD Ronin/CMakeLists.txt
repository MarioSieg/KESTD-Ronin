# CMakeList.txt : CMake project for KESTD Ronin, include source and define
# project specific logic here.

cmake_minimum_required (VERSION 3.8)
project("KESTD-Ronin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/../Bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/../Bin")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fp:fast")
set (CMAKE_CXX_STANDARD 20)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) # Export all symbols for the engine dll without using __declspec(dllexport) or __declspec(dllimport)

file(GLOB_RECURSE KESTD_SRC
    "Backend/*.hpp"
    "Backend/*.cpp"
    "Frontend/*.hpp"
    "Frontend/*.cpp"
)

# Add engine:
add_library("KestdRonin" SHARED ${KESTD_SRC})

include("Extern/CMakeLists.txt")

# Add AutoTec:
add_executable("AutoTec" "Frontend/Entry.cpp")
target_link_libraries("AutoTec" "KestdRonin")