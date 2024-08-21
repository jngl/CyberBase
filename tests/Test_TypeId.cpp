//
// Created by jngl on 05/12/2020.
//

#include <catch2/catch_test_macros.hpp>
#include <CyberBase/TypeId.h>
#include <unordered_map>

struct Foo{};
struct Bar{};

TEST_CASE( "cc::typeId value" ) {
    REQUIRE(cb::TypeId::get<int>().value() != cb::TypeId::get<float>().value());
}

TEST_CASE( "cc::typeId hashmap" ) {
    std::unordered_map<cb::TypeId, int> map;

    map[cb::TypeId::get<Foo>()] = 1;
    map[cb::TypeId::get<Bar>()] = 2;

    REQUIRE(map[cb::TypeId::get<Foo>()] == 1);
    REQUIRE(map[cb::TypeId::get<Bar>()] == 2);
}
