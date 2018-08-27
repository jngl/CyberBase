#ifndef CYBERBASE_TYPESAFE_METRE_HPP
#define CYBERBASE_TYPESAFE_METRE_HPP

#include <gsl/gsl_util>

#include <CyberBase/Log.hpp>
#include <CyberBase/TypeSafe/TypeSafeBase.hpp>
#include <CyberBase/TypeSafe/UnitPrefix.hpp>

namespace cb
{

class Metre : public TypeSafeBase<float>
{
  public:
    explicit constexpr Metre(float p_value,
                             UnitPrefix p_prefix = UnitPrefix::no) :
        TypeSafeBase<float>(p_value * gsl::at(UnitPrefix_definition,
                                              static_cast<size_t>(p_prefix))) {}

    constexpr bool operator==(const Metre &p_right) const {
        return delta_equal(value(), p_right.value());
    }

    constexpr Metre operator+(const Metre &r) const {
        return Metre{value() + r.value(), UnitPrefix::no};
    }
};

constexpr Metre m(float p_value) { return Metre{p_value, UnitPrefix::no}; }

const LogLine &operator<<(const LogLine &ll, const Metre &metre);

constexpr bool delta_equal(Metre a, Metre b) {
    return abs(a.value() - b.value()) < std::numeric_limits<float>::epsilon();
}

} // namespace cb

#endif // CYBERBASE_MATH_METRE_HPP