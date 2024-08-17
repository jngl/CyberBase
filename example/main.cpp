#include <CyberBase/Log.hpp>
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
}
