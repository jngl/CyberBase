#ifndef CYBER_BASE_STREAM_DECORATOR_HPP
#define CYBER_BASE_STREAM_DECORATOR_HPP

#include <functional>

namespace cb
{

template <class Stream, class Function> class StreamMap;
template <class Stream, class Function> class StreamFilter;

template <class T> class StreamDecorator : public T
{
  public:
    using T::T;

    template <class Function>
    StreamDecorator<StreamMap<T, Function>> map(Function func) const {
        return {*this, func};
    }

    template <class Function>
    StreamDecorator<StreamFilter<T, Function>> filter(Function func) const {
        return {*this, func};
    }
};

template <class F> auto getter(F &&f) {
    return std::bind(f, std::placeholders::_1);
}

} // namespace cb

#endif // CYBER_BASE_STREAM_DECORATOR_HPP
