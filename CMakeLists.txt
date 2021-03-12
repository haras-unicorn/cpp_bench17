cmake_minimum_required(VERSION 3.11...3.20)
project(cpp_bench LANGUAGES CXX)

include(FetchContent)


# google benchmark

set(BENCHMARK_DOWNLOAD_DEPENDENCIES True)

FetchContent_Declare(
     google_benchmark_fetch
     GIT_REPOSITORY "https://github.com/google/benchmark.git"
     GIT_TAG "v1.5.2"
)

FetchContent_MakeAvailable(google_benchmark_fetch)


# doctest

FetchContent_Declare(
    doctest_fetch
    GIT_REPOSITORY "https://github.com/onqtam/doctest.git"
    GIT_TAG "2.4.5"
)

FetchContent_MakeAvailable(doctest_fetch)


# executables

add_executable(bench ${PROJECT_SOURCE_DIR}/src/bench.cpp)

add_executable(test ${PROJECT_SOURCE_DIR}/src/test.cpp)


# links

target_link_libraries(bench PRIVATE doctest)
target_link_libraries(bench PRIVATE benchmark::benchmark)

target_link_libraries(test PRIVATE doctest)
target_link_libraries(test PRIVATE benchmark::benchmark)


#includes

target_include_directories(bench PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(test PRIVATE ${PROJECT_SOURCE_DIR}/src)
