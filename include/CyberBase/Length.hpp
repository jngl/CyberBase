#ifndef CYBERBASE_LENGTH_HPP
#define CYBERBASE_LENGTH_HPP

#include <CyberBase/UnitPrefix.hpp>

namespace cb
{
typedef float Length;

constexpr Length mm(float v) {
    return UnitPrefix_definition[static_cast<unsigned int>(UnitPrefix::milli)];
}

constexpr Length cm(float v) {
    return UnitPrefix_definition[static_cast<unsigned int>(UnitPrefix::centi)];
}

constexpr Length m(float v) {
    return UnitPrefix_definition[static_cast<unsigned int>(UnitPrefix::no)];
}

constexpr Length km(float v) {
    return UnitPrefix_definition[static_cast<unsigned int>(UnitPrefix::kilo)];
}

} // namespace cb

#endif // CYBERBASE_LENGTH_HPP