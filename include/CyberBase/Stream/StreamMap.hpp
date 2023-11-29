#pragma once

namespace cb
{

template <class Stream, class Function> class StreamMap
{
  public:
    using It = typename Stream::It;

    StreamMap(Stream p_stream, Function p_function) :
        m_stream(std::move(p_stream)),
        m_function(std::move(p_function)) {}

    template <class Function2> void for_each(Function2 func) const {
        m_stream.for_each([=](auto val) { func(m_function(val)); });
    }

  private:
    Stream m_stream;
    Function m_function;
};

} // namespace cb
