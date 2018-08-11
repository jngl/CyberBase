#include <CyberBase/Log.hpp>
#include <CyberBase/Vector3.hpp>
#include <fstream>
#include <iostream>

int main() {
    std::ofstream logFile("log.txt");

    cb::getLoggerInfo().add(&std::cout);
    cb::getLoggerWarning().add(&std::cerr);
    cb::getLoggerError().add(&std::cerr);

    cb::getLoggerInfo().add(&logFile);
    cb::getLoggerWarning().add(&logFile);
    cb::getLoggerError().add(&logFile);

    CB_LOG_INFO << "i"
                << "1";
    CB_LOG_WARN << "w"
                << "1";
    CB_LOG_ERROR << "e"
                 << "1";

    cb::Vector3 test{45, 2, 3};

    CB_LOG_INFO << test.x << " " << test.y << " " << test.z;
}