cmake_minimum_required(VERSION 3.15)
project(ray-tracing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(3rdparty)
add_subdirectory(src)
