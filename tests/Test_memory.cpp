//
// Created by jngl on 15/02/2022.
//

#include <catch2/catch_test_macros.hpp>
#include <CyberBase/Memory.h>

#include <fstream>
#include <bit>

TEST_CASE( "cc::ByteArray Default constructor" ) {
    const cb::ByteArray byte_array;

    REQUIRE(byte_array.size() == 0);
    REQUIRE(byte_array.data() == nullptr);
}

TEST_CASE( "cc::ByteArray constructor copy from variable" ) {
    constexpr unsigned int var = 42;

    auto byte_array = cb::ByteArray::fromVar(var);

    REQUIRE(byte_array.size() == sizeof(var));
    REQUIRE(byte_array.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(byte_array.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}

TEST_CASE( "cc::ByteArray from size" ) {
    const cb::ByteArray byte_array(12);

    REQUIRE(byte_array.size() == 12);
    REQUIRE(byte_array.data() != nullptr);
}

TEST_CASE( "cc::ByteArray copy constructor" ) {
    constexpr unsigned int var = 42;

    auto byte_array1 = cb::ByteArray::fromVar(var);

    REQUIRE(byte_array1.size() == sizeof(var));
    REQUIRE(byte_array1.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(byte_array1.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);

    const cb::ByteArray byte_array2(byte_array1);

    REQUIRE(byte_array1.size() == sizeof(var));
    REQUIRE(byte_array1.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(byte_array1.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);

    REQUIRE(byte_array2.size() == sizeof(var));
    REQUIRE(byte_array2.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(byte_array2.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}

TEST_CASE( "cc::ByteArray move constructor" ) {
    unsigned int var = 42;

    auto byte_array1 = cb::ByteArray::fromVar(var);
    const cb::ByteArray ba2(std::move(byte_array1));

    REQUIRE(ba2.size() == sizeof(var));
    REQUIRE(ba2.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(ba2.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}

TEST_CASE( "cc::ByteArray copy operator (construction)" ) {
    unsigned int var = 42;

    auto byte_array1 = cb::ByteArray::fromVar(var);
    const cb::ByteArray byte_array2 = byte_array1;

    REQUIRE(byte_array2.size() == sizeof(var));
    REQUIRE(byte_array2.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(byte_array2.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}

TEST_CASE( "cc::ByteArray equal operator" ) {
    unsigned int var = 42;

    auto byte_array1 = cb::ByteArray::fromVar(var);
    cb::ByteArray byte_array2;

    byte_array2 = byte_array1;

    REQUIRE(byte_array2.size() == sizeof(var));
    REQUIRE(byte_array2.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(byte_array2.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}

TEST_CASE( "cc::ByteArray move operator (construction)" ) {
    unsigned int var = 42;

    auto byte_array1 = cb::ByteArray::fromVar(var);
    const cb::ByteArray byte_array2 = std::move(byte_array1);

    REQUIRE(byte_array2.size() == sizeof(var));
    REQUIRE(byte_array2.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(byte_array2.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}
TEST_CASE( "cc::ByteArray move operator" ) {
    unsigned int var = 42;

    auto byte_array1 = cb::ByteArray::fromVar(var);
    cb::ByteArray byte_array2;
    byte_array2 = std::move(byte_array1);

    REQUIRE(byte_array2.size() == sizeof(var));
    REQUIRE(byte_array2.data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(byte_array2.data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}


TEST_CASE( "cc::ByteArray clear" ) {
    cb::ByteArray byte_array(12);

    byte_array.clear();

    REQUIRE(byte_array.size() == 0);
    REQUIRE(byte_array.data() == nullptr);
}

TEST_CASE( "cc::ByteArray from file" ) {
    const std::string filename = "filename-test-file";
    constexpr unsigned int var = 42;

    // Write file
    {
        std::ofstream file(filename, std::ifstream::binary);
        REQUIRE(file);

        file.write(reinterpret_cast<const char*>(&var), sizeof(var));

        file.close();
    }

    // Test
    auto byte_array = cb::ByteArray::tryFromFile(filename);

    REQUIRE(byte_array.has_value());

    REQUIRE(byte_array->size() == sizeof(var));
    REQUIRE(byte_array->data() != nullptr);
    REQUIRE(strncmp(reinterpret_cast<const char*>(byte_array->data()), reinterpret_cast<const char*>(&var), sizeof(var)) == 0);
}

