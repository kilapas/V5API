cmake_minimum_required(VERSION 3.14)

project(V5API LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libV5SDK)

#headers
include_directories(libV5SDK/include)

#sources
aux_source_directory(source SOURCES)

#target
add_library(V5API SHARED source/V5API.cpp)

#librarys
target_link_libraries(V5API libV5SDK)
