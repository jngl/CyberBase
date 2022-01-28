#pragma once

#include <string>
#include <string_view>

namespace cb
{
    class Error : public std::exception
    {
    public:
        explicit Error(std::string_view message);

        [[nodiscard]] const char *what() const noexcept override;

        [[nodiscard]] std::string message() const;

    private:
        std::string m_message;
    };

    void check(bool mustBeTrue, std::string_view message);
}
