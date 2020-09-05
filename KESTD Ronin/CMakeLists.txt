# CMakeList.txt : CMake project for KESTD Ronin, include source and define
# project specific logic here.

cmake_minimum_required (VERSION 3.8)
project("KESTD-Ronin")

set(CMAKE_BUILD_FILES_DIRECTORY "${PROJECT_SOURCE_DIR}/../Bin/Temp/Files" FORCE)
set(CMAKE_BUILD_DIRECTORY "${PROJECT_SOURCE_DIR}/../Bin/Temp/Build" FORCE)
SET(CMAKE_CACHEFILE_DIR "${PROJECT_SOURCE_DIR}/../Bin/Temp/Cache" FORCE)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/../Bin/Temp/Lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/../Bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/../Bin")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE KESTD_SRC
    "Backend/*.hpp"
    "Backend/*.cpp"
    "Frontend/*.hpp"
    "Frontend/*.cpp"
)

# Add engine:
add_library("KestdRonin" SHARED ${KESTD_SRC})

include("Extern/CMakeLists.txt")

add_subdirectory("Kernel")
target_link_libraries("KestdRonin" "RonKernel")

# Add AutoTec:
add_executable("AutoTec" "Exec/Entry.cpp")
target_link_libraries("AutoTec" "KestdRonin")