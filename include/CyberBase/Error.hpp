#ifndef CYBER_BASE_ERROR_HPP
#define CYBER_BASE_ERROR_HPP

#include <string>

namespace cb
{
class Error
{
  public:
    Error(std::string p_message);

    std::string message();

  private:
    std::string m_message;
};
} // namespace cb

#endif // CYBER_BASE_ERROR_HPP