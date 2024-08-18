//
// Created by jngl on 22/08/2021.
//
#include "CyberBase/Memory.h"

#include <cstring>
#include <fstream>

namespace cb{

    ByteArray::ByteArray(Uint64 size)
    {
        m_data.resize(size);
    }

    Uint64 ByteArray::size() const {
        return m_data.size();
    }

    const std::byte *ByteArray::data() const {
        if(m_data.empty())
        {
            return nullptr;
        }
        else
        {
            return m_data.data();
        }
    }

    std::optional<ByteArray> ByteArray::tryFromFile(std::string_view filename) {
        std::ifstream file(std::string(filename), std::ifstream::binary);
        if(!file){
            return {};
        }

        file.seekg (0, file.end);
        const long int size = file.tellg();
        file.seekg (0, file.beg);

        ByteArray result(static_cast<Uint64>(size));

        file.read (reinterpret_cast<char*>(result.m_data.data()),size);

        return result;
    }

    void ByteArray::clear() {
        m_data.clear();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ByteArrayView::ByteArrayView(const std::byte *refFrom, Uint64 size):
    m_data(refFrom, size)
    {
    }

    ByteArrayView::ByteArrayView(const ByteArray & from):
    m_data(from.data(), from.size())
    {
    }

    void ByteArrayView::clear() {
        m_data = std::span<const std::byte>();
    }

    ByteArrayView &ByteArrayView::operator=(const ByteArray& from) {
        m_data = std::span<const std::byte>(from.data(), from.size());
        return *this;
    }

    Uint64 ByteArrayView::size() const {
        return m_data.size();
    }

    const std::byte *ByteArrayView::data() const {
        return m_data.data();
    }
}

