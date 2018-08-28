#include <CyberBase.hpp>
#include <vector>

#include "Person.hpp"

int main() {
    cb::addDefaultLogOutput();

    CB_LOG_INFO << "i"
                << "1";
    CB_LOG_WARN << "w"
                << "1";
    CB_LOG_ERROR << "e"
                 << "1";

    cb::Vector3f test{45, 2, 3};
    CB_LOG_INFO << "Vector3f :" << test;

    cb::Vector2f test2{45, 2};
    CB_LOG_INFO << "Vector2f :" << test2;

    {
        auto line = CB_LOG_INFO;
        line << "person : ";
        std::vector<Person> people = {
            {15, "Alice"}, {18, "Bob"}, {24, "Cecile"}};
        cb::stream(people)
            .filter(cb::getter(&Person::isAdult))
            .map(cb::getter(&Person::name))
            .for_each([&line](std::string str) { line << str << " "; });
    }
}