file(GLOB_RECURSE SRC
    "Export/*.hpp"
    "Src/*.hpp"
    "Src/*.cpp"
)

# Add engine:
add_library("RonKernel" STATIC ${SRC})