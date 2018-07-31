#ifndef CYBERBASE_VECTOR3_HPP
#define CYBERBASE_VECTOR3_HPP

#include <CyberBase/MathBase.hpp>

namespace cb
{

/**
 *  3D vector
 */
class Vector3
{
  public:
    /**
     * Default constructor.
     */
    constexpr Vector3() = default;

    /**
     * Constructor.
     */
    constexpr Vector3(float p_x, float p_y, float p_z) :
        m_x(p_x),
        m_y(p_y),
        m_z(p_z) {}

    /**
     * getter for x
     */
    constexpr float x() const { return m_x; }

    /**
     * getter for y
     */
    constexpr float y() const { return m_y; }

    /**
     * getter for z
     */
    constexpr float z() const { return m_z; }

    constexpr Vector3 operator+(const Vector3 &r) const {
        return {m_x + r.m_x, m_y + r.m_y, m_z + r.m_z};
    }

    constexpr Vector3 operator-(const Vector3 &r) const {
        return {m_x - r.m_x, m_y - r.m_y, m_z - r.m_z};
    }

    constexpr Vector3 operator/(float r) const {
        return {m_x / r, m_y / r, m_z / r};
    }

    constexpr Vector3 operator*(float r) const {
        return {m_x * r, m_y * r, m_z * r};
    }

    constexpr Vector3 operator/=(float r) {
        m_x /= r;
        m_y /= r;
        m_z /= r;
        return *this;
    }

    constexpr bool operator==(const Vector3 &p_right) const {
        return delta_equal(m_x, p_right.m_x) && delta_equal(m_y, p_right.m_y) &&
               delta_equal(m_z, p_right.m_z);
    }

  private:
    float m_x = 0.f;
    float m_y = 0.f;
    float m_z = 0.f;
};

} // namespace cb

#endif // CYBERBASE_VECTOR3_HPP