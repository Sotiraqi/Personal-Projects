cmake_minimum_required (VERSION 3.5)

project (helloworld)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FILES} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")

add_executable (helloworld "${source_files}")
