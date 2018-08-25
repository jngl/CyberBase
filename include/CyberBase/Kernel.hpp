#ifndef CYBER_BASE_KERNEL_HPP
#define CYBER_BASE_KERNEL_HPP

#include <CyberBase/TypeSafe/Metre.hpp>

namespace cb
{

struct BasicKernel
{
    using Length = float;
};

struct MetreKernel
{
    using Length = Metre;
};

template <class T> constexpr bool hasLength(T *) { return false; };
template <class T> constexpr bool hasLength(typename T::Length *) {
    return true;
};

template <class T> constexpr bool isKernel() { return hasLength<T>(nullptr); }

static_assert(isKernel<BasicKernel>());
static_assert(isKernel<MetreKernel>());

} // namespace cb

#endif // CYBER_BASE_KERNEL_HPP