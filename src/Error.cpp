#include "CyberBase/Error.hpp"

namespace cb
{
Error::Error(std::string message):
    m_message(message)
{
}

std::string Error::message() const{
    return m_message;
}

void check(bool mustBeTrue, std::string message){
    if(!mustBeTrue){
        throw Error(message);
    }
}
}