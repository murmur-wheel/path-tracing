file(GLOB_RECURSE SOURCE_LIST *.h *.cpp)
add_executable(rt_test ${SOURCE_LIST})
target_link_libraries(rt_test rt)