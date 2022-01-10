#include "CyberBase/Error.hpp"

namespace cb
{
    Error::Error(std::string_view message):
        m_message(message)
    {
    }

    std::string Error::message() const{
        return m_message;
    }

    const char *Error::what() const noexcept {
        return m_message.c_str();
    }

    void check(bool mustBeTrue, std::string_view message){
        if(!mustBeTrue){
            throw Error(message);
        }
    }
}
