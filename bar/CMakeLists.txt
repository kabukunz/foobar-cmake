# CMakeLists.txt

cmake_minimum_required(VERSION 2.8)

project(bar)

add_library(bar SHARED bar.cpp)

target_include_directories(bar PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
