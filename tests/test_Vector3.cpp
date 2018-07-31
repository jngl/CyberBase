#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest

#include <CyberBase/Vector3.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(Vector3Constructor) {
    cb::Vector3 a(1, 2, 3);
    BOOST_CHECK_EQUAL(a.x(), 1.f);
    BOOST_CHECK_EQUAL(a.y(), 2.f);
    BOOST_CHECK_EQUAL(a.z(), 3.f);
}