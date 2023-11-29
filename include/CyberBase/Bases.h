#pragma once

namespace cc
{
    class NonCopyable{
    public:
        NonCopyable() = default;
        NonCopyable(const NonCopyable&) = delete;
        NonCopyable(NonCopyable&&) = delete;

        NonCopyable& operator=(const NonCopyable&) = delete;
        NonCopyable& operator=(NonCopyable&&) = delete;

        virtual ~NonCopyable() = default;
    };

    class Copyable{
    public:
        constexpr Copyable() = default;
        constexpr Copyable(const Copyable&) = default;
        constexpr Copyable(Copyable&&) = default;

        Copyable& operator=(const Copyable&) = default;
        Copyable& operator=(Copyable&&) = default;

        virtual ~Copyable() = default;
    };
}

