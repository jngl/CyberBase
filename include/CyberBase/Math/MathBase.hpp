#ifndef CYBERBASE_MATH_BASE_HPP
#define CYBERBASE_MATH_BASE_HPP

#include <cmath>

namespace cb
{
using std::abs;
using std::cos;
using std::sin;
using std::sqrt;

constexpr bool delta_equal(float a, float b) {
    return abs(a - b) < std::numeric_limits<float>::epsilon();
}

constexpr bool delta_equal(double a, double b) {
    return abs(a - b) < std::numeric_limits<double>::epsilon();
}

} // namespace cb

#endif // CYBERBASE_MATH_BASE_HPP