#include "CyberBase/Vector3.hpp"

namespace cb
{
Vector3::Vector3(float p_x, float p_y, float p_z) :
    m_x(p_x),
    m_y(p_y),
    m_z(p_z) {}

float Vector3::x() const { return m_x; }

float Vector3::y() const { return m_y; }

float Vector3::z() const { return m_z; }
} // namespace cb
