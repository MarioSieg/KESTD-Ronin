file(GLOB_RECURSE LUA_SRC
    "src/*.h"
    "src/*.c"
)

add_library("liblua_static" STATIC ${LUA_SRC})