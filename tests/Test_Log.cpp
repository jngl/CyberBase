//
// Created by jngl on 31/01/2022.
//

#include <catch.hpp>
#include <CyberBase/Log.hpp>


TEST_CASE( "cc::logTypeName" ) {
    REQUIRE(cb::logTypeName(cb::LogType::Info) == "Info");
    REQUIRE(cb::logTypeName(cb::LogType::Warning) == "Warning");
    REQUIRE(cb::logTypeName(cb::LogType::Error) == "Error");
}

TEST_CASE( "cc::logTypeColor" ) {
    REQUIRE(cb::logTypeColor(cb::LogType::Info) == fmt::color::green);
    REQUIRE(cb::logTypeColor(cb::LogType::Warning) == fmt::color::orange);
    REQUIRE(cb::logTypeColor(cb::LogType::Error) == fmt::color::red);
}
