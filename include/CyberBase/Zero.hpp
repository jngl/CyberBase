#ifndef CYBER_BASE_ZERO_HPP
#define CYBER_BASE_ZERO_HPP

#include <CyberBase/TypeSafe/Metre.hpp>

namespace cb
{
template <class T> constexpr T zero();

template <> constexpr Metre zero<Metre>() { return Metre(0); }
template <> constexpr float zero<float>() { return 0.f; }
template <> constexpr double zero<double>() { return 0.0; }
template <> constexpr int zero<int>() { return 0; }

} // namespace cb

#endif // CYBER_BASE_ZERO_HPP