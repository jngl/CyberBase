#ifndef CYBER_RAY_MATH_TUPLE3_HPP
#define CYBER_RAY_MATH_TUPLE3_HPP

#include <CyberBase/Log.hpp>

namespace cb
{
template <class T> class Tuple3
{
  public:
    T x;
    T y;
    T z;

    constexpr Tuple3() : x(0), y(0), z(0) {}
    constexpr Tuple3(T p_x, T p_y, T p_z) : x(p_x), y(p_y), z(p_z) {}
};

template <class T>
const LogLine &operator<<(const LogLine &ll, const Tuple3<T> &tuple) {
    ll << "{" << tuple.x << " " << tuple.y << " " << tuple.z << "}";
    return ll;
}

} // namespace cb

#endif // CYBER_RAY_MATH_TUPLE3_HPP