//
// Created by jngl on 05/12/2020.
//

#include <catch2/catch_test_macros.hpp>
#include <CyberBase/typeName.h>

class Foo{};

constexpr std::string_view intTypeName = cb::typeName<int>();
constexpr std::string_view fooTypeName = cb::typeName<Foo>();

TEST_CASE( "cc::typeName" ) {
    REQUIRE(intTypeName == "int");
    REQUIRE(fooTypeName == "Foo");
}

