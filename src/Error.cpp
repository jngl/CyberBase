#include "CyberBase/Error.hpp"

namespace cb
{
Error::Error(std::string p_message) : m_message(p_message) {}

std::string Error::message() { return m_message; }
} // namespace cb