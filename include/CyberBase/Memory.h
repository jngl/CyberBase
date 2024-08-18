#pragma once

#include "Common.h"

#include <optional>
#include <vector>
#include <array>
#include <string_view>
#include <span>

namespace cb{
    class ByteArray
    {
    private:
        std::vector<std::byte> m_data;

    public:
        ByteArray() = default;
        explicit ByteArray(Uint64 size);

        void clear();

        [[nodiscard]] Uint64 size() const;
        [[nodiscard]] const std::byte* data() const;

        template<class T>
        static ByteArray fromVar(const T& value)
        {
            ByteArray result;
            result.m_data.resize(sizeof value);
            memcpy(result.m_data.data(), &value, result.m_data.size());
            return result;
        }

        static std::optional<ByteArray> tryFromFile(std::string_view filename);

        template<class T, size_t size>
        static ByteArray copyFromArray(const std::array<T, size>& array){
            return ByteArray(array.data(), array.size() * sizeof(T));
        }
    };

    class ByteArrayView
    {
    private:
        std::span<const std::byte> m_data;

    public:
        ByteArrayView() = default;
        ByteArrayView(const std::byte* refFrom, Uint64 size);
        explicit ByteArrayView(const ByteArray&);

        void clear();

        ByteArrayView& operator=(const ByteArray&);

        [[nodiscard]] Uint64 size() const;
        [[nodiscard]] const std::byte* data() const;

        template<class T, size_t size>
        static ByteArray fromArray(const std::array<T, size>& array){
            return ByteArray(array.data(), array.size() * sizeof(T));
        }
    };
}

