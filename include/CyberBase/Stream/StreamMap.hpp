#ifndef CYBER_BASE_STREAM_MAP_HPP
#define CYBER_BASE_STREAM_MAP_HPP

namespace cb
{

template <class Stream, class Function> class StreamMap
{
  public:
    using It = typename Stream::It;

    StreamMap(Stream p_stream, Function p_function) :
        m_stream(p_stream),
        m_function(p_function) {}

    template <class Function2> void for_each(Function2 func) const {
        m_stream.for_each([=](auto val) { func(m_function(val)); });
    }

  private:
    Stream m_stream;
    Function m_function;
};

} // namespace cb

#endif // CYBER_BASE_STREAM_MAP_HPP
