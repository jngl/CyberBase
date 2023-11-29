#pragma once

#include "StreamDecorator.hpp"

namespace cb
{

template <class T> class StreamVector
{
  public:
    using It = typename T::const_iterator;

    StreamVector(const T &p_vector) :
        m_begin(p_vector.begin()),
        m_end(p_vector.end()) {}

    template <class Function> void for_each(Function func) const {
        for (It it = m_begin; it != m_end; ++it) {
            func(*it);
        }
    }

  private:
    It m_begin;
    It m_end;
};

template <class T> StreamDecorator<StreamVector<T>> stream(const T &p_vector) {
    return StreamDecorator<StreamVector<T>>(p_vector);
}

} // namespace cb
