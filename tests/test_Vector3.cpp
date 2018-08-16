#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest

#include <CyberBase/Math/Vector3.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(Vector3DefaultConstructor) {
    cb::Vector3 a;
    BOOST_CHECK_EQUAL(a.x, 0.f);
    BOOST_CHECK_EQUAL(a.y, 0.f);
    BOOST_CHECK_EQUAL(a.z, 0.f);
}

BOOST_AUTO_TEST_CASE(Vector3Constructor) {
    cb::Vector3 a{1.f, 2.f, 3.f};
    BOOST_CHECK_EQUAL(a.x, 1.f);
    BOOST_CHECK_EQUAL(a.y, 2.f);
    BOOST_CHECK_EQUAL(a.z, 3.f);
}

BOOST_AUTO_TEST_CASE(Vector3Plus) {
    cb::Vector3 a{1.f, 2.f, 3.f};
    cb::Vector3 b{4.f, 5.f, 6.f};
    cb::Vector3 c = a + b;
    BOOST_CHECK_EQUAL(c.x, 5.f);
    BOOST_CHECK_EQUAL(c.y, 7.f);
    BOOST_CHECK_EQUAL(c.z, 9.f);
}

BOOST_AUTO_TEST_CASE(Vector3Minus) {
    cb::Vector3 a{1.f, 2.f, 3.f};
    cb::Vector3 b{4.f, 5.f, 6.f};
    cb::Vector3 c = a - b;
    BOOST_CHECK_EQUAL(c.x, -3.f);
    BOOST_CHECK_EQUAL(c.y, -3.f);
    BOOST_CHECK_EQUAL(c.z, -3.f);
}

BOOST_AUTO_TEST_CASE(Vector3Mult) {
    cb::Vector3 a{1.f, 2.f, 3.f};
    float b = 2.f;
    cb::Vector3 c = a * b;
    BOOST_CHECK_EQUAL(c.x, 2.f);
    BOOST_CHECK_EQUAL(c.y, 4.f);
    BOOST_CHECK_EQUAL(c.z, 6.f);
}

BOOST_AUTO_TEST_CASE(Vector3Div) {
    cb::Vector3 a{1.f, 2.f, 3.f};
    float b = 2.f;
    cb::Vector3 c = a / b;
    BOOST_CHECK_EQUAL(c.x, 0.5f);
    BOOST_CHECK_EQUAL(c.y, 1.f);
    BOOST_CHECK_EQUAL(c.z, 1.5f);
}

BOOST_AUTO_TEST_CASE(Vector3DivEqual) {
    cb::Vector3 a{1.f, 2.f, 3.f};
    float b = 2.f;
    a /= b;
    BOOST_CHECK_EQUAL(a.x, 0.5f);
    BOOST_CHECK_EQUAL(a.y, 1.f);
    BOOST_CHECK_EQUAL(a.z, 1.5f);
}

BOOST_AUTO_TEST_CASE(Vector3Equal) {
    cb::Vector3 a{1.f, 2.f, 3.f};
    cb::Vector3 b{1.f, 2.f, 3.f};
    BOOST_CHECK(a == b);
}