#ifndef CYBER_BASE_TYPE_SAFE_POSITION2_HPP
#define CYBER_BASE_TYPE_SAFE_POSITION2_HPP

#include <CyberBase/Kernel.hpp>
#include <CyberBase/Math/Zero.hpp>

namespace cb
{
template <class Kernel> struct Position2
{
    static_assert(isKernel<Kernel>());

    using Length = typename Kernel::Length;
    using Real = typename Kernel::Real;

    Length x = zero<Length>();
    Length y = zero<Length>();
};
} // namespace cb

#endif // CYBER_BASE_TYPE_SAFE_POSITION2_HPP