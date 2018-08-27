#ifndef CYBERBASE_TEST_VECTOR2_HPP
#define CYBERBASE_TEST_VECTOR2_HPP

#include <CyberBase/Math/Vector2.hpp>
#include <CyberBase/Zero.hpp>

template <class Kernel> constexpr bool testVector2DefaultConstructor() {
    using Length = typename Kernel::Length;
    constexpr cb::Vector2<Kernel> a;
    return a.x == cb::zero<Length>() && a.y == cb::zero<Length>();
}
static_assert(testVector2DefaultConstructor<cb::MetreKernel>());
static_assert(testVector2DefaultConstructor<cb::BasicKernel>());

template <class Kernel>
constexpr bool testVector2Constructor(typename Kernel::Length x,
                                      typename Kernel::Length y) {
    cb::Vector2<Kernel> a{x, y};
    return a.x == x && a.y == y;
}
static_assert(testVector2Constructor<cb::MetreKernel>(cb::m(1), cb::m(2)));

template <class Kernel>
constexpr bool
testVector2Plus(typename Kernel::Length ax, typename Kernel::Length ay,
                typename Kernel::Length bx, typename Kernel::Length by,
                typename Kernel::Length rx, typename Kernel::Length ry) {
    cb::Vector2<Kernel> a{ax, ay};
    cb::Vector2<Kernel> b{bx, by};
    cb::Vector2<Kernel> c = a + b;

    cb::Vector2<Kernel> result{rx, ry};
    return c == result;
}
static_assert(testVector2Plus<cb::MetreKernel>(cb::m(1), cb::m(2), cb::m(3),
                                               cb::m(4), cb::m(4), cb::m(6)));
static_assert(testVector2Plus<cb::BasicKernel>(1, 2, 3, 4, 4, 6));
/*
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
}*/

#endif