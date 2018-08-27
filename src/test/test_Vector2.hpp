#ifndef CYBERBASE_TEST_VECTOR2_HPP
#define CYBERBASE_TEST_VECTOR2_HPP

#include <CyberBase/Math/Vector2.hpp>
#include <CyberBase/Zero.hpp>

//////////////////////////////////////////////////////////////////////////
//                          DefaultConstructor
//////////////////////////////////////////////////////////////////////////
template <class Kernel> constexpr bool testVector2DefaultConstructor() {
    using Length = typename Kernel::Length;
    constexpr cb::Vector2<Kernel> a;
    return a.x == cb::zero<Length>() && a.y == cb::zero<Length>();
}
static_assert(testVector2DefaultConstructor<cb::MetreKernel>());
static_assert(testVector2DefaultConstructor<cb::BasicKernel>());

//////////////////////////////////////////////////////////////////////////
//                           Constructor
//////////////////////////////////////////////////////////////////////////
template <class Kernel>
constexpr bool testVector2Constructor(typename Kernel::Length x,
                                      typename Kernel::Length y) {
    cb::Vector2<Kernel> a{x, y};
    return a.x == x && a.y == y;
}
static_assert(testVector2Constructor<cb::MetreKernel>(cb::m(1), cb::m(2)));
static_assert(testVector2Constructor<cb::BasicKernel>(1, 2));

//////////////////////////////////////////////////////////////////////////
//                           Plus
//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////
//                           Minus
//////////////////////////////////////////////////////////////////////////
template <class Kernel>
constexpr bool
testVector2Minus(typename Kernel::Length ax, typename Kernel::Length ay,
                 typename Kernel::Length bx, typename Kernel::Length by,
                 typename Kernel::Length rx, typename Kernel::Length ry) {
    cb::Vector2<Kernel> a{ax, ay};
    cb::Vector2<Kernel> b{bx, by};
    cb::Vector2<Kernel> c = a - b;

    cb::Vector2<Kernel> result{rx, ry};
    return c == result;
}
static_assert(testVector2Minus<cb::MetreKernel>(cb::m(1), cb::m(2), cb::m(3),
                                                cb::m(4), cb::m(-2),
                                                cb::m(-2)));
static_assert(testVector2Minus<cb::BasicKernel>(1, 2, 3, 4, -2, -2));

//////////////////////////////////////////////////////////////////////////
//                           Mult
//////////////////////////////////////////////////////////////////////////
template <class Kernel>
constexpr bool
testVector2Div(typename Kernel::Length ax, typename Kernel::Length ay,
               typename Kernel::Real b, typename Kernel::Length rx,
               typename Kernel::Length ry) {
    cb::Vector2<Kernel> a{ax, ay};
    cb::Vector2<Kernel> c = a / b;

    cb::Vector2<Kernel> result{rx, ry};
    return c == result;
}
static_assert(testVector2Div<cb::MetreKernel>(cb::m(1), cb::m(2), 2, cb::m(0.5),
                                              cb::m(1)));
static_assert(testVector2Div<cb::BasicKernel>(1, 2, 2, 0.5, 1));

//////////////////////////////////////////////////////////////////////////
//                           Div
//////////////////////////////////////////////////////////////////////////
template <class Kernel>
constexpr bool
testVector2Mult(typename Kernel::Length ax, typename Kernel::Length ay,
                typename Kernel::Real b, typename Kernel::Length rx,
                typename Kernel::Length ry) {
    cb::Vector2<Kernel> a{ax, ay};
    cb::Vector2<Kernel> c = a * b;

    cb::Vector2<Kernel> result{rx, ry};
    return c == result;
}
static_assert(testVector2Mult<cb::MetreKernel>(cb::m(1), cb::m(2), 2, cb::m(2),
                                               cb::m(4)));
static_assert(testVector2Mult<cb::BasicKernel>(1, 2, 2, 2, 4));

#endif