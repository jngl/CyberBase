#ifndef CYBERBASE_TEST_VECTOR2_HPP
#define CYBERBASE_TEST_VECTOR2_HPP

#include <CyberBase/Vector2.hpp>

constexpr void testVector2DefaultConstructor() {
    constexpr cb::Vector2 a;

    static_assert(a.x == 0.f && a.y == 0.f);
}

constexpr void testVector2Constructor() {
    constexpr cb::Vector2 a{1.f, 2.f};

    static_assert(a.x == 1.f && a.y == 2.f);
}

constexpr void testVector2Plus() {
    constexpr cb::Vector2 a{1.f, 2.f};
    constexpr cb::Vector2 b{4.f, 5.f};
    constexpr cb::Vector2 c = a + b;

    constexpr cb::Vector2 result{5.f, 7.f};
    static_assert(c == result);
}

constexpr void testVector2Minus() {
    constexpr cb::Vector2 a{1.f, 2.f};
    constexpr cb::Vector2 b{4.f, 5.f};
    constexpr cb::Vector2 c = a - b;

    constexpr cb::Vector2 result{-3.f, -3.f};
    static_assert(c == result);
}

constexpr void testVector2Mult() {
    constexpr cb::Vector2 a{1.f, 2.f};
    constexpr float b = 2.f;
    constexpr cb::Vector2 c = a * b;

    constexpr cb::Vector2 result{2.f, 4.f};
    static_assert(c == result);
}

constexpr void testVector2Div() {
    constexpr cb::Vector2 a{1.f, 2.f};
    constexpr float b = 2.f;
    constexpr cb::Vector2 c = a / b;

    constexpr cb::Vector2 result{0.5f, 1.f};
    static_assert(c == result);
}

constexpr void testVector2DivEqual() {
    constexpr cb::Vector2 val = []() {
        cb::Vector2 a = {1.f, 2.f};
        a /= 2.f;
        return a;
    }();

    constexpr cb::Vector2 result{0.5f, 1.f};
    static_assert(val == result);
}

#endif