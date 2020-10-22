add_library(3rdparty_stub INTERFACE)

include(FetchContent)

# stb
FetchContent_Declare(
    stb
    GIT_REPOSITORY https://github.com/nothings/stb.git
)
FetchContent_GetProperties(stb)
if (NOT stb_POPULATED)
    FetchContent_Populate(stb)
    target_include_directories(3rdparty_stub INTERFACE ${stb_SOURCE_DIR})
endif ()

# gtest
FetchContent_Declare(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.10.0
)
FetchContent_GetProperties(gtest)
if (NOT gtest_POPULATED)
    FetchContent_Populate(gtest)
    add_subdirectory(${gtest_SOURCE_DIR} ${gtest_BINARY_DIR})
    target_link_libraries(3rdparty_stub INTERFACE gtest)
endif ()