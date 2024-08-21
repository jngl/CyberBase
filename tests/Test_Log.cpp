//
// Created by jngl on 31/01/2022.
//

#include <catch2/catch_test_macros.hpp>
#include <CyberBase/Log.hpp>


TEST_CASE( "cb::logTypeName" ) {
    REQUIRE(cb::logTypeName(cb::LogType::Info) == "Info");
    REQUIRE(cb::logTypeName(cb::LogType::Warning) == "Warning");
    REQUIRE(cb::logTypeName(cb::LogType::Error) == "Error");
}

TEST_CASE( "cb::logTypeColor" ) {
    REQUIRE(cb::logTypeColor(cb::LogType::Info) == fmt::color::green);
    REQUIRE(cb::logTypeColor(cb::LogType::Warning) == fmt::color::orange);
    REQUIRE(cb::logTypeColor(cb::LogType::Error) == fmt::color::red);
}

TEST_CASE( "cb::LogLine" )
{
    constexpr std::string_view file = "file";
    constexpr int lineNumber = 42;
    constexpr std::string_view module_name = "module";
    constexpr cb::LogType logType = cb::LogType::Info;
    constexpr fmt::string_view format = "{} {}";
    constexpr int var1 = 45;
    constexpr int var2 = 666;

    cb::LogLine line = cb::LogLine::make(file, lineNumber, module_name, logType, format, var1, var2);

    REQUIRE(line.file == file);
    REQUIRE(line.line == lineNumber);
    REQUIRE(line.module == module_name);
    REQUIRE(line.type == logType);
    REQUIRE(line.message == "45 666");
}
