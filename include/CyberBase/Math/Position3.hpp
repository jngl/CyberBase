#ifndef CYBER_BASE_TYPE_SAFE_POSITION3_HPP
#define CYBER_BASE_TYPE_SAFE_POSITION3_HPP

#include <CyberBase/Kernel.hpp>
#include <CyberBase/Math/Zero.hpp>

namespace cb
{
template <class Kernel> struct Position3
{
    static_assert(isKernel<Kernel>());

    using Length = typename Kernel::Length;
    using Real = typename Kernel::Real;

    Length x = zero<Length>();
    Length y = zero<Length>();
    Length z = zero<Length>();
};

template <class Kernel>
const LogLine &operator<<(const LogLine &ll, const Position3<Kernel> &pos) {
    ll << pos.x << " " << pos.y << " " << pos.z;
    return ll;
}

} // namespace cb

#endif // CYBER_BASE_TYPE_SAFE_POSITION2_HPP