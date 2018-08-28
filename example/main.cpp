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

    cb::Vector3<cb::BasicKernel> test{45, 2, 3};
    CB_LOG_INFO << "Vector3<BasicKernel> :" << test;

    cb::Vector3<cb::MetreKernel> testb{cb::m(45), cb::m(2), cb::m(3)};
    CB_LOG_INFO << "Vector3<MetreKernel> :" << testb;

    cb::Vector2<cb::BasicKernel> test2{45, 2};
    CB_LOG_INFO << "Vector2<BasicKernel> :" << test2;

    cb::Vector2<cb::MetreKernel> test3{cb::m(45), cb::m(2)};
    CB_LOG_INFO << "Vector2<MetreKernel> :" << test3;

    cb::Metre m(12, cb::UnitPrefix::kilo);
    CB_LOG_INFO << "metre : " << m;

    cb::Metre m2 = cb::m(1.21);
    CB_LOG_INFO << "metre : " << m2;

    cb::Position2<cb::MetreKernel> pos2{cb::m(1), cb::m(2)};
    CB_LOG_INFO << "pos2 : " << pos2;

    cb::Position3<cb::MetreKernel> pos3{cb::m(1), cb::m(2), cb::m(3)};
    CB_LOG_INFO << "pos3 : " << pos3;

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