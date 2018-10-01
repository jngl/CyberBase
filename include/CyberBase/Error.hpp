#pragma once

#include <string>

namespace cb
{
class Error
{
public:
    Error(std::string message);

    std::string message() const;

private:
    std::string m_message;
};

void check(bool mustBeTrue, std::string message);
}