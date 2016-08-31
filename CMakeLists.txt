cmake_minimum_required(VERSION 3.0)

project(WowMapEditor)


list(APPEND CMAKE_MODULE_PATH "${WowMapEditor_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_subdirectory(src)
