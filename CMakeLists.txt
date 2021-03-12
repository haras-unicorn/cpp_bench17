cmake_minimum_required(VERSION 3.11...3.20)
project(cpp_bench LANGUAGES CXX)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_C_COMILER "clang")
set(CMAKE_CXX_COMILER "clang++")
set(CMAKE_GENERATOR "Ninja")
set(CMAKE_BUILD_RPATH ".cmake_build")


include(FetchContent)
