#ifndef PERSON_HPP
#define PERSON_HPP

class Person
{
  public:
    Person(int p_age, std::string p_name) :
        m_age(p_age),
        m_name(std::move(p_name)){};

    int age() const { return m_age; }

    std::string name() const { return m_name; }

    bool isAdult() const { return age() >= 18; }

  private:
    int m_age;
    std::string m_name;
};

#endif // PERSON_HPP
