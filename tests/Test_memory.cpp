//
// Created by jngl on 15/02/2022.
//

#include <catch2/catch_test_macros.hpp>
#include <CyberBase/Memory.h>

TEST_CASE( "cc::ByteArray Default constructor" ) {
    cc::ByteArray ba;

    REQUIRE(ba.size() == 0);
    REQUIRE(ba.data() == nullptr);
}

TEST_CASE( "cc::ByteArray constructor copy from data" ) {
    unsigned int var = 42;

    cc::ByteArray ba(&var, sizeof(var));

    REQUIRE(ba.size() == sizeof(var));
    REQUIRE(ba.data() != nullptr);
}

TEST_CASE( "cc::ByteArray constructor copy from size" ) {
    cc::ByteArray ba(12);

    REQUIRE(ba.size() == 12);
    REQUIRE(ba.data() != nullptr);
}

TEST_CASE( "cc::ByteArray copy constructor" ) {
    cc::ByteArray ba1(12);
    cc::ByteArray ba2(ba1);

    REQUIRE(ba2.size() == 12);
    REQUIRE(ba2.data() != nullptr);
}

TEST_CASE( "cc::ByteArray move constructor" ) {
    cc::ByteArray ba1(12);
    cc::ByteArray ba2(std::move(ba1));

    REQUIRE(ba2.size() == 12);
    REQUIRE(ba2.data() != nullptr);
}

TEST_CASE( "cc::ByteArray copy operator" ) {
    cc::ByteArray ba1(12);

    cc::ByteArray ba2 = ba1;

    REQUIRE(ba2.size() == 12);
    REQUIRE(ba2.data() != nullptr);
}

TEST_CASE( "cc::ByteArray move operator" ) {
    cc::ByteArray ba1(12);
    cc::ByteArray ba2 = std::move(ba1);

    REQUIRE(ba2.size() == 12);
    REQUIRE(ba2.data() != nullptr);
}

TEST_CASE( "cc::ByteArray clear" ) {
    cc::ByteArray ba(12);

    ba.clear();

    REQUIRE(ba.size() == 0);
    REQUIRE(ba.data() == nullptr);
}

