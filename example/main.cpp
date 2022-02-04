#include <CyberBase.hpp>
#include <vector>

#include "Person.hpp"

int add2(int v) { return v + 2; }
int mult2(int v) { return v * 2; }

int main() {
    cb::MultiLogger logger;
    logger.addOutput(std::make_unique<cb::ConsoleLogger>());
    logger.addOutput(std::make_unique<cb::FileLogger>("log.csv"));

    CB_INFO(logger, "Foo", "Un Test {}", 1);
    CB_WARNING(logger, "Bar", "Un Test {}", 2);
    CB_ERROR(logger, "Truc Much", "Un Test");

    std::string text;
    std::vector<Person> people = {{15, "Alice"}, {18, "Bob"}, {24, "Cecile"}};
    cb::stream(people)
        .filter(cb::getter(&Person::isAdult))
        .map(cb::getter(&Person::name))
        .for_each([&text](std::string str) { text += str + " "; });

    CB_INFO(logger,"Stream", "person : {}", text);

    int i = cr::Pipe(42, &add2).to(&mult2).result();
    CB_INFO(logger,"Pipe", "pipe : {}", i);
    CB_INFO(logger,"Pipe", "pipe : {}", i);
}
