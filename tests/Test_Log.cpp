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
    constexpr std::string_view module = "module";
    constexpr cb::LogType logType = cb::LogType::Info;
    constexpr fmt::string_view format = "{}";
    const fmt::format_args args = fmt::make_format_args(1);

    cb::LogLine line(file, lineNumber, module, logType, format, args);

    REQUIRE(line.file == file);
    REQUIRE(line.line == lineNumber);
    REQUIRE(line.module == module);
    REQUIRE(line.type == logType);
    REQUIRE(line.message == "1");
}
