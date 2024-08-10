cmake_minimum_required(VERSION 3.10)

project(Jeek_Jeek_CLI)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(SRC_DIR src)
set(INCLUDE_DIR include)

include_directories(${INCLUDE_DIR})

file(GLOB SOURCES "${SRC_DIR}/*.cpp")

add_executable(jeek_jeek_cli ${SOURCES})