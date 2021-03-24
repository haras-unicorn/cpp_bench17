enum class ref_type_t
{
    lvalue,
    rvalue,
    value
};

template <typename T>
constexpr inline ref_type_t get_ref_type(T &&of) noexcept
{
    if constexpr (std::is_rvalue_reference_v<T>)
        return ref_type_t::rvalue;
    else if constexpr (std::is_lvalue_reference_v<T>)
        return ref_type_t::lvalue;
    else
        return ref_type_t::value;
}

TEST_CASE("universal_ref")
{
    int lvalue{1};
    REQUIRE_EQ(get_ref_type(1), ref_type_t::value);
    REQUIRE_EQ(get_ref_type(lvalue), ref_type_t::lvalue);
}
