#ifndef CYBER_BASE_PIPE_HPP
#define CYBER_BASE_PIPE_HPP

#include <functional>
#include <type_traits>

namespace cr
{

template <class Param, class Return> class Pipe
{
  public:
    Pipe(Param p_parm, Return (*p_func)(Param)) : m_data(p_func(p_parm)) {}

    template <class Func2> auto to(Func2 p_func2) {
        return Pipe(m_data, p_func2);
    }

    Return &result() { return m_data; }

  private:
    Return m_data;
};

} // namespace cr

#endif