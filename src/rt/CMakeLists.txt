file(GLOB_RECURSE SOURCE_LIST *.cpp *.h)
add_library(rt ${SOURCE_LIST})
target_link_libraries(rt 3rdparty_stub)