//
// Created by jngl on 15/02/2022.
//

#include <catch2/catch_test_macros.hpp>
#include <CyberBase/Memory.h>

#include <fstream>

TEST_CASE( "cc::ByteArray Default constructor" ) {
    const cb::ByteArray ba;

    REQUIRE(ba.size() == 0);
    REQUIRE(ba.data() == nullptr);
}

TEST_CASE( "cc::ByteArray constructor copy from data" ) {
    unsigned int var = 42;

    const cb::ByteArray ba(&var, sizeof(var));

    REQUIRE(ba.size() == sizeof(var));
    REQUIRE(ba.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(ba.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}

TEST_CASE( "cc::ByteArray from size" ) {
    const cb::ByteArray ba(12);

    REQUIRE(ba.size() == 12);
    REQUIRE(ba.data() != nullptr);
}

TEST_CASE( "cc::ByteArray copy constructor" ) {
    unsigned int var = 42;

    const cb::ByteArray ba1(&var, sizeof(var));
    const cb::ByteArray ba2(ba1);

    REQUIRE(ba2.size() == sizeof(var));
    REQUIRE(ba2.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(ba2.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}

TEST_CASE( "cc::ByteArray move constructor" ) {
    unsigned int var = 42;

    const cb::ByteArray ba1(&var, sizeof(var));
    const cb::ByteArray ba2(std::move(ba1));

    REQUIRE(ba2.size() == sizeof(var));
    REQUIRE(ba2.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(ba2.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}

TEST_CASE( "cc::ByteArray copy operator (construction)" ) {
    unsigned int var = 42;

    const cb::ByteArray ba1(&var, sizeof(var));
    const cb::ByteArray ba2 = ba1;

    REQUIRE(ba2.size() == sizeof(var));
    REQUIRE(ba2.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(ba2.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}

TEST_CASE( "cc::ByteArray equal operator" ) {
    unsigned int var = 42;

    const cb::ByteArray ba1(&var, sizeof(var));
    cb::ByteArray ba2;

    ba2 = ba1;

    REQUIRE(ba2.size() == sizeof(var));
    REQUIRE(ba2.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(ba2.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}

TEST_CASE( "cc::ByteArray move operator (construction)" ) {
    unsigned int var = 42;

    cb::ByteArray ba1(&var, sizeof(var));
    const cb::ByteArray ba2 = std::move(ba1);

    REQUIRE(ba2.size() == sizeof(var));
    REQUIRE(ba2.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(ba2.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}
TEST_CASE( "cc::ByteArray move operator" ) {
    unsigned int var = 42;

    cb::ByteArray ba1(&var, sizeof(var));
    cb::ByteArray ba2;
    ba2 = std::move(ba1);

    REQUIRE(ba2.size() == sizeof(var));
    REQUIRE(ba2.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(ba2.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}


TEST_CASE( "cc::ByteArray clear" ) {
    cb::ByteArray ba(12);

    ba.clear();

    REQUIRE(ba.size() == 0);
    REQUIRE(ba.data() == nullptr);
}

TEST_CASE( "cc::ByteArray load from file" ) {
    const std::string filename = "filename-test-file";
    unsigned int var = 42;

    // Write file
    {
        std::ofstream file(filename, std::ifstream::binary);
        REQUIRE(file);

        file.write(reinterpret_cast<const char*>(&var), sizeof(var));

        file.close();
    }

    // Test
    const std::optional<cb::ByteArray> ba = cb::ByteArray::loadFromFile(filename);

    REQUIRE(ba.has_value());

    REQUIRE(ba->size() == sizeof(var));
    REQUIRE(ba->data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(ba->data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}

TEST_CASE( "cc::ByteArray copy from data" ) {
    unsigned int var = 42;

    cb::ByteArray ba;
    ba.copy(&var, sizeof(var));

    REQUIRE(ba.size() == sizeof(var));
    REQUIRE(ba.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(ba.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}
