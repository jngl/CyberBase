#include <CyberBase.hpp>

#include <iostream>

int main() {
    CB_LOG(trace) << "A trace severity message " << 42;
    CB_LOG(debug) << "A debug severity message";
    CB_LOG(info) << "An informational severity message";
    CB_LOG(warning) << "A warning severity message";
    CB_LOG(error) << "An error severity message";
    CB_LOG(fatal) << "A fatal severity message";

    cb::Vector3 test{45, 2, 3};
    float x = 0.f;

    std::cout << test.x() / x << " " << test.y() << " " << test.z()
              << std::endl;
}