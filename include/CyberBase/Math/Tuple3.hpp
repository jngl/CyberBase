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
};

template <class T>
const LogLine &operator<<(const LogLine &ll, const Tuple3<T> &tuple) {
    ll << "{" << tuple.x << " " << tuple.y << " " << tuple.z << "}";
    return ll;
}

} // namespace cb

#endif // CYBER_RAY_MATH_TUPLE3_HPP