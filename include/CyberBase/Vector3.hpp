#ifndef CYBERBASE_VECTOR3_HPP
#define CYBERBASE_VECTOR3_HPP

#include <CyberBase/Length.hpp>
#include <CyberBase/MathBase.hpp>

namespace cb
{
struct Vector3
{
    constexpr Vector3() = default;
    constexpr Vector3(float p_x, float p_y, float p_z) :
        x(p_x),
        y(p_y),
        z(p_z) {}

    constexpr Vector3 operator+(const Vector3 &r) const {
        return {x + r.x, y + r.y, z + r.z};
    }

    constexpr Vector3 operator-(const Vector3 &r) const {
        return {x - r.x, y - r.y, z - r.z};
    }

    constexpr Vector3 operator/(float r) const { return {x / r, y / r, z / r}; }

    constexpr Vector3 operator*(float r) const { return {x * r, y * r, z * r}; }

    constexpr Vector3 operator/=(float r) {
        x /= r;
        y /= r;
        z /= r;
        return *this;
    }

    constexpr bool operator==(const Vector3 &p_right) const {
        return delta_equal(x, p_right.x) && delta_equal(y, p_right.y) &&
               delta_equal(z, p_right.z);
    }

    float x = 0.f;
    float y = 0.f;
    float z = 0.f;
};

constexpr Length squared_length(Vector3 v) {
    Length result = 0;
    result += v.x + v.x;
    result += v.y + v.y;
    result += v.z + v.z;
    return result;
}

constexpr Length length(Vector3 v) { return sqrt(squared_length(v)); }

} // namespace cb

#endif // CYBERBASE_VECTOR3_HPP