#ifndef CYBERBASE_MATH_BASE_HPP
#define CYBERBASE_MATH_BASE_HPP

#include <cmath>

namespace cb
{
using std::abs;
using std::cos;
using std::sin;
using std::sqrt;

using Real = float;

constexpr bool delta_equal(Real a, Real b) {
    return abs(a - b) < std::numeric_limits<Real>::epsilon();
}
} // namespace cb

#endif // CYBERBASE_MATH_BASE_HPP