#ifndef CYBERBASE_TEST_VECTOR3_HPP
#define CYBERBASE_TEST_VECTOR3_HPP

#include <CyberBase/Math/Vector3.hpp>

constexpr void testVector3DefaultConstructor() {
    constexpr cb::Vector3r a;

    static_assert(a.x == 0.f && a.y == 0.f && a.z == 0.f);
}

constexpr void testVector3Constructor() {
    constexpr cb::Vector3r a{1.f, 2.f, 3.f};

    static_assert(a.x == 1.f && a.y == 2.f && a.z == 3.f);
}

constexpr void testVector3Plus() {
    constexpr cb::Vector3r a{1.f, 2.f, 3.f};
    constexpr cb::Vector3r b{4.f, 5.f, 6.f};
    constexpr cb::Vector3r c = a + b;

    constexpr cb::Vector3r result{5.f, 7.f, 9.f};
    static_assert(c == result);
}

constexpr void testVector3Minus() {
    constexpr cb::Vector3r a{1.f, 2.f, 3.f};
    constexpr cb::Vector3r b{4.f, 5.f, 6.f};
    constexpr cb::Vector3r c = a - b;

    constexpr cb::Vector3r result{-3.f, -3.f, -3.f};
    static_assert(c == result);
}

constexpr void testVector3Mult() {
    constexpr cb::Vector3r a{1.f, 2.f, 3.f};
    constexpr float b = 2.f;
    constexpr cb::Vector3r c = a * b;

    constexpr cb::Vector3r result{2.f, 4.f, 6.f};
    static_assert(c == result);
}

constexpr void testVector3Div() {
    constexpr cb::Vector3r a{1.f, 2.f, 3.f};
    constexpr float b = 2.f;
    constexpr cb::Vector3r c = a / b;

    constexpr cb::Vector3r result{0.5f, 1.f, 1.5f};
    static_assert(c == result);
}

constexpr cb::Vector3r testVector3AddEqual() {
    cb::Vector3r a = {1.f, 2.f, 3.f};
    cb::Vector3r b = {1, 2, 3};
    a += b;
    return a;
}
static_assert(testVector3AddEqual() == cb::Vector3r{2, 4, 6});

constexpr cb::Vector3r testVector3MinusEqual() {
    cb::Vector3r a = {2.f, 4.f, 6.f};
    cb::Vector3r b = {1, 2, 3};
    a -= b;
    return a;
}
static_assert(testVector3MinusEqual() == cb::Vector3r{1, 2, 3});

constexpr cb::Vector3r testVector3DivEqual() {
    cb::Vector3r a = {1.f, 2.f, 3.f};
    a /= 2.f;
    return a;
}
static_assert(testVector3DivEqual() == cb::Vector3r{0.5f, 1.f, 1.5f});

constexpr cb::Vector3r testVector3MultEqual() {
    cb::Vector3r a = {1.f, 2.f, 3.f};
    a *= 2.f;
    return a;
}
static_assert(testVector3MultEqual() == cb::Vector3r{2, 4, 6});

#endif