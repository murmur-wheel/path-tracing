file(GLOB_RECURSE SOURCE_LIST *.h *.cpp)
add_executable(rt_cli ${SOURCE_LIST})
target_link_libraries(rt_cli rt)