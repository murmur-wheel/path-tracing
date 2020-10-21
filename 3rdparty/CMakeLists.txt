add_library(3rdparty_stub INTERFACE)

include(FetchContent)

# stb
FetchContent_Declare(
    stb
    GIT_REPOSITORY https://github.com/nothings/stb   
)
FetchContent_GetProperties(stb)
if (NOT stb_POPULATED)
    FetchContent_Populate(stb)
    target_include_directories(3rdparty_stub INTERFACE ${stb_SOURCE_DIR})
endif ()