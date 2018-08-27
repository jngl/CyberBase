#ifndef CYBERBASE_VECTOR3_HPP
#define CYBERBASE_VECTOR3_HPP

#include <CyberBase/Math/MathBase.hpp>
#include <CyberBase/Utils/Tuple3.hpp>

namespace cb
{

template <class Kernel> struct Vector3
{
    static_assert(isKernel<Kernel>());

    using Length = typename Kernel::Length;
    using Real = typename Kernel::Real;

    constexpr Vector3() = default;
    constexpr Vector3(Length p_x, Length p_y, Length p_z) :
        x(p_x),
        y(p_y),
        z(p_z) {}

    constexpr Vector3 operator+(const Vector3 &r) const {
        return {x + r.x, y + r.y, z + r.z};
    }

    constexpr Vector3 operator-(const Vector3 &r) const {
        return {x - r.x, y - r.y, z - r.z};
    }

    constexpr Vector3 operator/(Real r) const { return {x / r, y / r, z / r}; }

    constexpr Vector3 operator*(Real r) const { return {x * r, y * r, z * r}; }

    constexpr bool operator==(const Vector3 &p_right) const {
        return delta_equal(x, p_right.x) && delta_equal(y, p_right.y) &&
               delta_equal(z, p_right.z);
    }

    Length x = zero<Length>();
    Length y = zero<Length>();
    Length z = zero<Length>();
};

/*
constexpr Real squared_length(Vector3 v) {
    Real result = 0;
    result += v.x + v.x;
    result += v.y + v.y;
    result += v.z + v.z;
    return result;
}

constexpr Real length(Vector3 v) { return sqrt(squared_length(v)); }*/

} // namespace cb

#endif // CYBERBASE_VECTOR3_HPP