#include "deps.hpp"

template <size_t size, size_t align>
class alignas(align) aligned_storage
{
    std::byte val[size]{std::byte{0}};

public:
    constexpr inline aligned_storage() noexcept = default;

    template <typename T>
    typename std::enable_if_t<
        sizeof(T) == size &&
            alignof(T) == align &&
            std::is_trivially_copyable_v<T>,
        aligned_storage &> inline
    operator=(const T &other) noexcept
    {
        std::memcpy(val, &other, size);
        return *this;
    }

    template <
        typename T,
        std::enable_if_t<
            sizeof(T) == size &&
                alignof(T) == align &&
                std::is_trivially_copyable_v<T>,
            int> = 0>
    inline aligned_storage(const T &other) noexcept
    {
        *this = other;
    }

    template <
        typename T,
        std::enable_if_t<
            sizeof(T) == size &&
                alignof(T) == align &&
                std::is_trivially_constructible_v<T> &&
                std::is_trivially_copyable_v<T>,
            int> = 0>
    explicit inline operator T() const noexcept
    {
        T dst;
        std::memcpy(&dst, val, size);
        return dst;
    }
};

void stack_storage(benchmark::State &state)
{
    std::array<aligned_storage<sizeof(int), alignof(int)>, 100> a{};

    for (auto _ : state)
    {
        int i = 1000;
        for (auto &s : a)
            s = i++;

        int sum_bits = 0;
        for (const auto &s : a)
            sum_bits += int{s};
    }
}

BENCHMARK(stack_storage);

void stack_int(benchmark::State &state)
{
    std::array<int, 100> ai{};

    for (auto _ : state)
    {
        int i = 1000;
        for (auto &s : ai)
            s = i++;

        int sum = 0;
        for (const auto &s : ai)
            sum += s;
    }
}

BENCHMARK(stack_int);

void heap_storage(benchmark::State &state)
{
    std::vector<aligned_storage<sizeof(int), alignof(int)>> v{};
    v.reserve(100);

    for (auto _ : state)
    {
        int i = 1000;
        while (i < 1100)
            v.push_back(i++);

        int sum_bits = 0;
        for (const auto &s : v)
            sum_bits += int{s};
    }
}

BENCHMARK(heap_storage);

void heap_int(benchmark::State &state)
{
    std::vector<int> vi{};
    vi.reserve(100);

    for (auto _ : state)
    {
        int i = 1000;
        while (i < 1100)
            vi.push_back(i++);

        int sum = 0;
        for (const auto &s : vi)
            sum += s;
    }
}

BENCHMARK(heap_int);
