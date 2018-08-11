#include <CyberBase/Log.hpp>
#include <CyberBase/Vector3.hpp>

int main() {
    cb::addDefaultLogOutput();

    CB_LOG_INFO << "i"
                << "1";
    CB_LOG_WARN << "w"
                << "1";
    CB_LOG_ERROR << "e"
                 << "1";

    cb::Vector3 test{45, 2, 3};

    CB_LOG_INFO << test.x << " " << test.y << " " << test.z;
}