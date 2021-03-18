void no_return() {}

TEST_CASE("void comma")
{
    true ? no_return(), no_return() : no_return();
}

TEST_CASE("nullptr zero")
{
    REQUIRE(static_cast<int *>(nullptr) + 0 == static_cast<int *>(nullptr));
}
