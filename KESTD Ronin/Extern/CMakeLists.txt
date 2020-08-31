include_directories("Extern/infoware/include/")
add_subdirectory("Extern/infoware/")
target_link_libraries("KestdRonin" "infoware")

include_directories("Extern/glfw/include/")
add_subdirectory("Extern/glfw/")
target_link_libraries("KestdRonin" "glfw")

include_directories("Extern/bgfx/include/")
add_subdirectory("Extern/bgfx/")
target_link_libraries("KestdRonin" "bgfx")

include_directories("Extern/imgui/")
add_subdirectory("Extern/imgui/")
target_link_libraries("KestdRonin" "imgui")

include_directories("Extern/fmt/include/")
add_subdirectory("Extern/fmt/")
target_link_libraries("KestdRonin" "fmt")

include_directories("Extern/lua/src")
add_subdirectory("Extern/lua/")
target_link_libraries("KestdRonin" "liblua_static")

include_directories("Extern/fontawesome/include/")