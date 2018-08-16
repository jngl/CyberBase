#ifndef CYBERBASE_VECTOR2_HPP
#define CYBERBASE_VECTOR2_HPP

#include <CyberBase/Math/Length.hpp>
#include <CyberBase/Math/MathBase.hpp>

namespace cb
{
struct Vector2
{
    constexpr Vector2() = default;
    constexpr Vector2(float p_x, float p_y) : x(p_x), y(p_y) {}

    constexpr Vector2 operator+(const Vector2 &r) const {
        return {x + r.x, y + r.y};
    }

    constexpr Vector2 operator-(const Vector2 &r) const {
        return {x - r.x, y - r.y};
    }

    constexpr Vector2 operator/(float r) const { return {x / r, y / r}; }

    constexpr Vector2 operator*(float r) const { return {x * r, y * r}; }

    constexpr Vector2 operator/=(float r) {
        x /= r;
        y /= r;
        return *this;
    }

    constexpr bool operator==(const Vector2 &p_right) const {
        return delta_equal(x, p_right.x) && delta_equal(y, p_right.y);
    }

    float x = 0.f;
    float y = 0.f;
};

constexpr Length squared_length(Vector2 v) {
    Length result = 0;
    result += v.x + v.x;
    result += v.y + v.y;
    return result;
}

constexpr Length length(Vector2 v) { return sqrt(squared_length(v)); }

} // namespace cb

#endif // CYBERBASE_VECTOR2_HPP