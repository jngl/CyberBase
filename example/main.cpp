#include <CyberBase.hpp>

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

    cb::Vector2 test2{45, 2};
    CB_LOG_INFO << test2.x << " " << test2.y;

    cb::Metre m(12, cb::UnitPrefix::kilo);
    CB_LOG_INFO << "metre : " << m;

    cb::Metre m2 = cb::m(1.21);
    CB_LOG_INFO << "metre : " << m2;

    cb::Position pos{cb::m(1), cb::m(2), cb::m(3)};
    CB_LOG_INFO << "pos : " << pos;
}