TEST_CASE("vector life")
{
    std::vector<int> nil{};

    SUBCASE("nil")
    {
        REQUIRE_EQ(nil.size(), 0);
        REQUIRE_EQ(nil.begin().base(), nullptr);
    }
    SUBCASE("copy nil")
    {
        std::vector<int> nil_copy{nil};
        REQUIRE_EQ(nil_copy.size(), 0);
    }
    SUBCASE("move nil")
    {
        std::vector<int> nil_move{std::move(nil)};
        REQUIRE_EQ(nil_move.size(), 0);
        REQUIRE_EQ(nil_move.begin().base(), nullptr);
    }

    nil = {};
    SUBCASE("nil assign copy")
    {
        std::vector<int> my(10);
        REQUIRE_EQ(my.size(), 10);
        my = nil;
        REQUIRE_EQ(my.size(), 0);
    }
    SUBCASE("nil assign move")
    {
        std::vector<int> my(10);
        REQUIRE_EQ(my.size(), 10);
        my = std::move(nil);
        REQUIRE_EQ(my.size(), 0);
        REQUIRE_EQ(my.begin().base(), nullptr);
    }
}
