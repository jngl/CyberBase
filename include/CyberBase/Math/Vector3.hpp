#ifndef CYBERBASE_VECTOR3_HPP
#define CYBERBASE_VECTOR3_HPP

#include <CyberBase/Math/MathBase.hpp>
#include <CyberBase/Utils/Tuple3.hpp>

namespace cb
{
/*
template <class T> class Vector3 : public Tuple3<T>
{
  public:
    using Tuple3<T>::Tuple3;
    using Tuple3<T>::x;
    using Tuple3<T>::y;
    using Tuple3<T>::z;

    constexpr Vector3<T> operator+(const Vector3<T> &r) const {
        return {x + r.x, y + r.y, z + r.z};
    }

    constexpr Vector3<T> operator-(const Vector3<T> &r) const {
        return {x - r.x, y - r.y, z - r.z};
    }

    constexpr Vector3<T> operator/(T r) const { return {x / r, y / r, z / r}; }

    constexpr Vector3<T> operator*(T r) const { return {x * r, y * r, z * r}; }

    constexpr Vector3<T> operator+=(const Vector3<T> &r) {
        x += r.x;
        y += r.y;
        z += r.z;
        return *this;
    }

    constexpr Vector3<T> operator-=(const Vector3<T> &r) {
        x -= r.x;
        y -= r.y;
        z -= r.z;
        return *this;
    }

    constexpr Vector3<T> operator/=(T r) {
        x /= r;
        y /= r;
        z /= r;
        return *this;
    }

    constexpr Vector3<T> operator*=(T r) {
        x *= r;
        y *= r;
        z *= r;
        return *this;
    }

    constexpr bool operator==(const Vector3<T> &p_right) const {
        return delta_equal(x, p_right.x) && delta_equal(y, p_right.y) &&
               delta_equal(z, p_right.z);
    }
};

using Vector3f = Vector3<float>;
using Vector3d = Vector3<double>;
using Vector3r = Vector3<Real>;
*/
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