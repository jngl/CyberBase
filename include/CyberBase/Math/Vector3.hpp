#ifndef CYBERBASE_VECTOR3_HPP
#define CYBERBASE_VECTOR3_HPP

#include <CyberBase/Math/MathBase.hpp>
#include <CyberBase/Math/Tuple3.hpp>

namespace cb
{
using Vector3 = Tuple3<Real>;

constexpr Real squared_length(Vector3 v) {
    Real result = 0;
    result += v.x + v.x;
    result += v.y + v.y;
    result += v.z + v.z;
    return result;
}

constexpr Real length(Vector3 v) { return sqrt(squared_length(v)); }

} // namespace cb

#endif // CYBERBASE_VECTOR3_HPP