#ifndef CYBERBASE_UNIT_PREFIX_HPP
#define CYBERBASE_UNIT_PREFIX_HPP

#include <CyberBase/Math/MathBase.hpp>

namespace cb
{

enum class UnitPrefix
{
    milli,
    centi,
    no,
    kilo,
};

static constexpr int UnitPrefix_Count = 4;

static constexpr Real UnitPrefix_definition[UnitPrefix_Count] = {
    0.001f,
    0.01f,
    1.f,
    1000.f,
};

} // namespace cb

#endif // CYBERBASE_UNIT_PREFIX_HPP