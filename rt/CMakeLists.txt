file(GLOB_RECURSE SOURCE_LIST *.cpp *.h)

foreach (item ${SOURCE_LIST})
    string(REGEX MATCH ".*_test.cpp" TEST_CODE ${item})
    if (TEST_CODE)
        list(APPEND TEST_SOURCE_LIST ${item})
    else ()
        list(APPEND RT_SOURCE_LIST ${item})
    endif ()
endforeach ()

# rt_lib
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(rt_lib ${RT_SOURCE_LIST})
target_link_libraries(rt_lib 3rdparty_stub)

# rt
add_executable(rt main.cpp)
target_link_libraries(rt rt_lib)

# rt_test
add_executable(rt_test ${TEST_SOURCE_LIST})
target_link_libraries(rt_test gtest_main rt_lib)