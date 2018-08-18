#ifndef CYBERBASE_TYPESAFE_TYPESAFEBASE_HPP
#define CYBERBASE_TYPESAFE_TYPESAFEBASE_HPP

namespace cb
{

template <class T> class TypeSafeBase
{
  public:
    explicit constexpr TypeSafeBase(T p_value) : m_value(p_value) {}

    constexpr T value() const { return m_value; }

  private:
    T m_value;
};

} // namespace cb

#endif // CYBERBASE_TYPESAFE_TYPESAFEBASE_HPP