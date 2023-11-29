#pragma once

#include <CyberBase/hash.h>
#include <CyberBase/typeName.h>

namespace cc {
    class TypeId {
    public:
        template<class T>
        static TypeId get(){
            constexpr std::string_view name = typeName<T>();
            constexpr uint64_t hash = hash_64_fnv1a_const(name);
            constexpr TypeId id(hash);
            return id;
        }

        [[nodiscard]] constexpr uint64_t value() const {
            return m_id;
        }

        bool operator==(const TypeId &rhs) const {
            return m_id == rhs.m_id;
        }

    private:
        constexpr explicit TypeId(uint64_t id): m_id(id) {}

        uint64_t m_id;
    };
}

namespace std {
    template<> struct hash<cc::TypeId> {
        std::size_t operator()(const cc::TypeId &f) const {
            return std::hash<uint64_t>{}(f.value());
        }
    };
}

