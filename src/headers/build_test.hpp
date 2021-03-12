#include "deps.hpp"


// doctest

TEST_CASE("build test")
{
    REQUIRE(true);
}


// benchmark

void build_test(benchmark::State& state)
{
    for (auto _ : state)
    {

    }
}

BENCHMARK(build_test);
