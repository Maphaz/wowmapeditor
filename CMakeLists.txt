cmake_minimum_required(VERSION 3.0)

project(WowMapEditor)

set(${CMAKE_PROJECT_NAME}_VERSION_MAJOR 0)
set(${CMAKE_PROJECT_NAME}_VERSION_MINOR 0)
set(${CMAKE_PROJECT_NAME}_VERSION_PATCH 0)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

find_package(Git)

include(GenerateVersion)

include_directories("${PROJECT_BINARY_DIR}/src" "${PROJECT_SOURCE_DIR}/src")
add_subdirectory(src)
