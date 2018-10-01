#include <CyberBase.hpp>
#include <vector>

#include "Person.hpp"

int add2(int v) { return v + 2; }
int mult2(int v) { return v * 2; }

int main() {
    cb::addDefaultLogOutput();

    CB_LOG_INFO << "i"
                << "1";
    CB_LOG_WARN << "w"
                << "1";

    cb::Vector3f test{45, 2, 3};
    CB_LOG_INFO << "Vector3f :" << test;

    cb::Vector2f test2{45, 2};
    CB_LOG_INFO << "Vector2f :" << test2;

    std::string text;
    std::vector<Person> people = {{15, "Alice"}, {18, "Bob"}, {24, "Cecile"}};
    cb::stream(people)
        .filter(cb::getter(&Person::isAdult))
        .map(cb::getter(&Person::name))
        .for_each([&text](std::string str) { text += str + " "; });

    CB_LOG_INFO << "person : " << text;

    int i = cr::Pipe(42, &add2).to(&mult2).result();
    CB_LOG_INFO << "pipe : " << i;

    CB_LOG_ERROR << "a error";
}