#include "CyberBase/TypeSafe/Metre.hpp"

namespace cb
{
const LogLine &operator<<(const LogLine &ll, const Metre &metre) {
    ll << metre.value() << "m";
    return ll;
}
} // namespace cb