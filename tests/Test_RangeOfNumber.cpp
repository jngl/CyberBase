//
// Created by jngl on 20/12/2020.
//

#include <catch2/catch_test_macros.hpp>
#include <CyberBase/Range.h>

constexpr int g_range_min_1 = 3;
constexpr int g_range_max_1 = 10;
constexpr cb::Range g_range_1(g_range_min_1, g_range_max_1);

constexpr int g_range_min_2 = 2;
constexpr int g_range_max_2 = 2;
constexpr cb::Range g_range_2(g_range_min_2, g_range_max_2);

TEST_CASE( "cc::Range construct" ) {
    cb::Range<int> b(g_range_min_1, g_range_max_1);
    REQUIRE(b.min() == g_range_min_1);
    REQUIRE(b.max() == g_range_max_1);

    REQUIRE_THROWS_AS(cb::Range<int>(g_range_max_1, g_range_min_1), cb::InvalidRange);  //NOLINT
}

TEST_CASE( "cc::Range copy construct" ) {
    cb::Range<int> b(g_range_1);

    REQUIRE(b.min() == g_range_min_1);
    REQUIRE(b.max() == g_range_max_1);
}

TEST_CASE( "cc::Range move construct" ) {
    cb::Range<int> a = g_range_1;
    cb::Range<int> b = std::move(a);

    REQUIRE(b.min() == g_range_min_1);
    REQUIRE(b.max() == g_range_max_1);
}

TEST_CASE( "cc:Range copy assignment Operator" ) {
    cb::Range<int> a = g_range_1;

    a= g_range_2;

    REQUIRE(a.min() == g_range_min_2);
    REQUIRE(a.max() == g_range_max_2);
}

TEST_CASE( "cc:Range copy assignment Operator same" ) {
    cb::Range<int> a = g_range_1;
    const cb::Range<int>& b = a;

    a= b;

    REQUIRE(a.min() == g_range_min_1);
    REQUIRE(a.max() == g_range_max_1);
}

TEST_CASE( "cc:Range move assignment Operator" ) {
    cb::Range<int> a = g_range_1;

    cb::Range<int> b = g_range_2;
    a = std::move(b);

    REQUIRE(a.min() == g_range_min_2);
    REQUIRE(a.max() == g_range_max_2);
}

TEST_CASE( "cc:Range move assignment Operator same" ) {
    cb::Range<int> a = g_range_1;
    cb::Range<int>& b = a;

    a = std::move(b);

    REQUIRE(a.min() == g_range_min_1);
    REQUIRE(a.max() == g_range_max_1);
}

TEST_CASE( "cc::Range tryPopMin" ) {
    auto a = g_range_1;
    auto b = g_range_2;

    std::optional<int> value1 =  a.tryPopMin();
    REQUIRE(value1 == g_range_min_1);

    std::optional<int> value2 =  b.tryPopMin();
    REQUIRE(!value2.has_value());
}

TEST_CASE( "cc::Range tryPopMax" ) {
    auto a = g_range_1;
    auto b = g_range_2;

    std::optional<int> value1 =  a.tryPopMax();
    REQUIRE(value1 == g_range_max_1);

    std::optional<int> value2 =  b.tryPopMax();
    REQUIRE(!value2.has_value());
}

TEST_CASE( "cc::Range tryFusion" ) {
    auto a =  cb::Range<int>::tryFusion(g_range_1, g_range_2);
    REQUIRE(a == cb::Range<int>(2, 10));

    auto b =  cb::Range<int>::tryFusion(g_range_2, g_range_1);
    REQUIRE(b == cb::Range<int>(2, 10));
}

TEST_CASE( "cc::Range tryFusion Impossible" ) {
    cb::Range<int> a{1, 10};
    cb::Range<int> b{100, 1000};

    auto c =  cb::Range<int>::tryFusion(a, b);
    REQUIRE(!c.has_value());
}

TEST_CASE( "cc::MultiRange add number" ) {
    cb::MultiRange<int> mr;

    mr.addNumber(0);
    mr.addNumber(-1);
    mr.addNumber(1);
    mr.addNumber(-3);
    mr.addNumber(-2);
    mr.addNumber(3);
    mr.addNumber(2);
    mr.addNumber(20);
    mr.addNumber(19);

    // -3_1 2_3 19_20

    REQUIRE(mr.tryPopFirst() == -3);
    REQUIRE(mr.tryPopFirst() == -2);
    REQUIRE(mr.tryPopFirst() == -1);
    REQUIRE(mr.tryPopFirst() == 0);
    REQUIRE(mr.tryPopFirst() == 1);
    REQUIRE(mr.tryPopFirst() == 2);
    REQUIRE(mr.tryPopFirst() == 3);
    REQUIRE(mr.tryPopFirst() == 19);
    REQUIRE(mr.tryPopFirst() == 20);
}
