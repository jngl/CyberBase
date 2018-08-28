#ifndef CYBERBASE_VECTOR2_HPP
#define CYBERBASE_VECTOR2_HPP

#include <CyberBase/Kernel.hpp>
#include <CyberBase/Math/MathBase.hpp>
#include <CyberBase/Math/Zero.hpp>

namespace cb
{

template <class Kernel> struct Vector2
{
    static_assert(isKernel<Kernel>());

    using Length = typename Kernel::Length;
    using Real = typename Kernel::Real;

    constexpr Vector2() = default;
    constexpr Vector2(Length p_x, Length p_y) : x(p_x), y(p_y) {}

    constexpr Vector2 operator+(const Vector2 &r) const {
        return {x + r.x, y + r.y};
    }

    constexpr Vector2 operator-(const Vector2 &r) const {
        return {x - r.x, y - r.y};
    }

    constexpr Vector2 operator/(Real r) const { return {x / r, y / r}; }

    constexpr Vector2 operator*(Real r) const { return {x * r, y * r}; }

    constexpr bool operator==(const Vector2 &p_right) const {
        return delta_equal(x, p_right.x) && delta_equal(y, p_right.y);
    }

    Length x = zero<Length>();
    Length y = zero<Length>();
};
/*
constexpr Real squared_length(Vector2 v) {
    Real result = 0;
    result += v.x + v.x;
    result += v.y + v.y;
    return result;
}

constexpr Real length(Vector2 v) { return sqrt(squared_length(v)); }
*/
} // namespace cb

#endif // CYBERBASE_VECTOR2_HPP