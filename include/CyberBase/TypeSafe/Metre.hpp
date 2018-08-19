#ifndef CYBERBASE_TYPESAFE_METRE_HPP
#define CYBERBASE_TYPESAFE_METRE_HPP

#include <gsl/gsl_util>

#include <CyberBase/Log.hpp>
#include <CyberBase/TypeSafe/TypeSafeBase.hpp>
#include <CyberBase/TypeSafe/UnitPrefix.hpp>

namespace cb
{

class Metre : public TypeSafeBase<Real>
{
  public:
    explicit constexpr Metre(Real p_value,
                             UnitPrefix p_prefix = UnitPrefix::no) :
        TypeSafeBase<Real>(p_value * gsl::at(UnitPrefix_definition,
                                             static_cast<size_t>(p_prefix))) {}
};

constexpr Metre m(Real p_value) { return Metre{p_value, UnitPrefix::no}; }

const LogLine &operator<<(const LogLine &ll, const Metre &tuple);

} // namespace cb

#endif // CYBERBASE_MATH_METRE_HPP