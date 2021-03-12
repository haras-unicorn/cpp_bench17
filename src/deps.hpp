#ifndef CPP_BENCH_DEPS_HPP
#define CPP_BENCH_DEPS_HPP


#include <type_traits>
#include <utility>
#include <memory>
#include <cstring>

#include <array>
#include <vector>


// info: https://github.com/google/benchmark
#ifdef _WIN32
#pragma comment ( lib, "Shlwapi.lib" )
#ifdef _DEBUG
#pragma comment ( lib, "benchmarkd.lib" )
#else
#pragma comment ( lib, "benchmark.lib" )
#endif
#endif


#include <doctest/doctest.h>
#include <benchmark/benchmark.h>


#endif
