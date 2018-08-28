#ifndef CYBERBASE_TEST_VECTOR3_HPP
#define CYBERBASE_TEST_VECTOR3_HPP

#include <CyberBase/Kernel.hpp>
#include <CyberBase/Math/Vector3.hpp>
#include <CyberBase/Math/Zero.hpp>

//////////////////////////////////////////////////////////////////////////
//                          DefaultConstructor
//////////////////////////////////////////////////////////////////////////
template <class Kernel> constexpr bool testVector3DefaultConstructor() {
    using Length = typename Kernel::Length;
    constexpr cb::Vector3<Kernel> a;
    return a.x == cb::zero<Length>() && a.y == cb::zero<Length>() &&
           a.z == cb::zero<Length>();
}
static_assert(testVector3DefaultConstructor<cb::MetreKernel>());
static_assert(testVector3DefaultConstructor<cb::BasicKernel>());

//////////////////////////////////////////////////////////////////////////
//                           Constructor
//////////////////////////////////////////////////////////////////////////
template <class Kernel>
constexpr bool testVector3Constructor(typename Kernel::Length x,
                                      typename Kernel::Length y,
                                      typename Kernel::Length z) {
    cb::Vector3<Kernel> a{x, y, z};
    return a.x == x && a.y == y && a.z == z;
}
static_assert(testVector3Constructor<cb::MetreKernel>(cb::m(1), cb::m(2),
                                                      cb::m(3)));
static_assert(testVector3Constructor<cb::BasicKernel>(1, 2, 3));

//////////////////////////////////////////////////////////////////////////
//                           Plus
//////////////////////////////////////////////////////////////////////////
template <class Kernel>
constexpr bool
testVector3Plus(typename Kernel::Length ax, typename Kernel::Length ay,
                typename Kernel::Length az, typename Kernel::Length bx,
                typename Kernel::Length by, typename Kernel::Length bz,
                typename Kernel::Length rx, typename Kernel::Length ry,
                typename Kernel::Length rz) {
    cb::Vector3<Kernel> a{ax, ay, az};
    cb::Vector3<Kernel> b{bx, by, bz};
    cb::Vector3<Kernel> c = a + b;

    cb::Vector3<Kernel> result{rx, ry, rz};
    return c == result;
}
static_assert(testVector3Plus<cb::MetreKernel>(cb::m(1), cb::m(2), cb::m(3),
                                               cb::m(4), cb::m(4), cb::m(6),
                                               cb::m(5), cb::m(6), cb::m(9)));
static_assert(testVector3Plus<cb::BasicKernel>(1, 2, 3, 4, 4, 6, 5, 6, 9));

//////////////////////////////////////////////////////////////////////////
//                           Minus
//////////////////////////////////////////////////////////////////////////
template <class Kernel>
constexpr bool
testVector3Minus(typename Kernel::Length ax, typename Kernel::Length ay,
                 typename Kernel::Length az, typename Kernel::Length bx,
                 typename Kernel::Length by, typename Kernel::Length bz,
                 typename Kernel::Length rx, typename Kernel::Length ry,
                 typename Kernel::Length rz) {
    cb::Vector3<Kernel> a{ax, ay, az};
    cb::Vector3<Kernel> b{bx, by, bz};
    cb::Vector3<Kernel> c = a - b;

    cb::Vector3<Kernel> result{rx, ry, rz};
    return c == result;
}
static_assert(testVector3Minus<cb::MetreKernel>(cb::m(1), cb::m(2), cb::m(3),
                                                cb::m(4), cb::m(5), cb::m(6),
                                                cb::m(-3), cb::m(-3),
                                                cb::m(-3)));
static_assert(testVector3Minus<cb::BasicKernel>(1, 2, 3, 4, 5, 6, -3, -3, -3));

//////////////////////////////////////////////////////////////////////////
//                           Mult
//////////////////////////////////////////////////////////////////////////
template <class Kernel>
constexpr bool
testVector3Div(typename Kernel::Length ax, typename Kernel::Length ay,
               typename Kernel::Length az, typename Kernel::Real b,
               typename Kernel::Length rx, typename Kernel::Length ry,
               typename Kernel::Length rz) {
    cb::Vector3<Kernel> a{ax, ay, az};
    cb::Vector3<Kernel> c = a / b;

    cb::Vector3<Kernel> result{rx, ry, rz};
    return c == result;
}
static_assert(testVector3Div<cb::MetreKernel>(cb::m(1), cb::m(2), cb::m(3), 2,
                                              cb::m(0.5), cb::m(1),
                                              cb::m(3.f / 2)));
static_assert(testVector3Div<cb::BasicKernel>(1, 2, 3, 2, 0.5, 1, 3.f / 2));

//////////////////////////////////////////////////////////////////////////
//                           Div
//////////////////////////////////////////////////////////////////////////
template <class Kernel>
constexpr bool
testVector3Mult(typename Kernel::Length ax, typename Kernel::Length ay,
                typename Kernel::Length az, typename Kernel::Real b,
                typename Kernel::Length rx, typename Kernel::Length ry,
                typename Kernel::Length rz) {
    cb::Vector3<Kernel> a{ax, ay, az};
    cb::Vector3<Kernel> c = a * b;

    cb::Vector3<Kernel> result{rx, ry, rz};
    return c == result;
}
static_assert(testVector3Mult<cb::MetreKernel>(cb::m(1), cb::m(2), cb::m(3), 2,
                                               cb::m(2), cb::m(4), cb::m(6)));
static_assert(testVector3Mult<cb::BasicKernel>(1, 2, 3, 2, 2, 4, 6));

#endif