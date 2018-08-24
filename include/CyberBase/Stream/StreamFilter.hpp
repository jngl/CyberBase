#ifndef CYBER_BASE_STREAM_FILTER_HPP
#define CYBER_BASE_STREAM_FILTER_HPP

namespace cb
{

template <class Stream, class Function> class StreamFilter
{
  public:
    using It = typename Stream::It;

    StreamFilter(Stream p_stream, Function p_function) :
        m_stream(p_stream),
        m_function(p_function) {}

    template <class Function2> void for_each(Function2 func) const {
        m_stream.for_each([=](auto val) {
            if (m_function(val)) {
                func(val);
            }
        });
    }

  private:
    Stream m_stream;
    Function m_function;
};

} // namespace cb

#endif // CYBER_BASE_STREAM_FILTER_HPP
