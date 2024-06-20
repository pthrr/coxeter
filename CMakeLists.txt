cmake_minimum_required(VERSION 3.27 FATAL_ERROR)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/ProjectVersion.cmake)

project(
  coxeter
  LANGUAGES CXX
  VERSION ${PROJECT_VERSION}
  DESCRIPTION "A library for n-dim geometry")

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/ProjectSettings.cmake)

find_package(Catch2 REQUIRED)

set(XTENSOR_USE_XSIMD 1)
set(XTENSOR_DISABLE_EXCEPTIONS 1)
set(XTENSOR_USE_OPENMP 1)
find_package(xtensor REQUIRED)
find_package(xtensor-blas REQUIRED)

file(GLOB_RECURSE ${PROJECT_NAME}_HEADER CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_subdirectory(include)
add_subdirectory(tests)

execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_SOURCE_DIR}/build/compile_commands.json
)
