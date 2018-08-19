#ifndef CYBER_RAY_MATH_TUPLE3_HPP
#define CYBER_RAY_MATH_TUPLE3_HPP

#include <CyberBase/Log.hpp>

namespace cb
{
template <class T> struct Tuple3
{
    T x;
    T y;
    T z;

    constexpr Tuple3() : x(0), y(0), z(0) {}
    constexpr Tuple3(T p_x, T p_y, T p_z) : x(p_x), y(p_y), z(p_z) {}

    constexpr Tuple3 operator+(const Tuple3 &r) const {
        return {x + r.x, y + r.y, z + r.z};
    }

    constexpr Tuple3 operator-(const Tuple3 &r) const {
        return {x - r.x, y - r.y, z - r.z};
    }

    constexpr Tuple3 operator/(Real r) const { return {x / r, y / r, z / r}; }

    constexpr Tuple3 operator*(Real r) const { return {x * r, y * r, z * r}; }

    constexpr Tuple3 operator/=(Real r) {
        x /= r;
        y /= r;
        z /= r;
        return *this;
    }

    constexpr bool operator==(const Tuple3 &p_right) const {
        return delta_equal(x, p_right.x) && delta_equal(y, p_right.y) &&
               delta_equal(z, p_right.z);
    }
};

template <class T>
const LogLine &operator<<(const LogLine &ll, const Tuple3<T> &tuple) {
    ll << "{" << tuple.x << " " << tuple.y << " " << tuple.z << "}";
    return ll;
}

} // namespace cb

#endif // CYBER_RAY_MATH_TUPLE3_HPP