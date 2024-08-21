#include <catch2/catch_test_macros.hpp>
#include <CyberBase/pointer.h>

constexpr int testValue1 = 42;
constexpr int testValue2 = -1;

class Foo{
public:
    void a(){}
};

class Bar : public Foo{};

TEST_CASE( "cc::Ref constructor ref" ) {
    int i = testValue1;

    cb::Ref<int> a(i);
    REQUIRE(*a == testValue1);

    *a = testValue2;
    REQUIRE(i == testValue2);
}

TEST_CASE( "cc::Ref constructor copy" ) {
    int i = testValue1;

    cb::Ref<int> a(i);
    cb::Ref<int> b(a);

    REQUIRE(*b == testValue1);

    *b = testValue2;
    REQUIRE(i == testValue2);
}

TEST_CASE( "cc::Ref constructor move" ) {
    int i = testValue1;

    cb::Ref<int> a(i);
    cb::Ref<int> b(std::move(a));

    REQUIRE(*b == testValue1);

    *b = testValue2;
    REQUIRE(i == testValue2);
}

TEST_CASE( "cc::Ref assign copy" ) {
    int i = testValue1;
    int j = testValue2;

    cb::Ref<int> a(i);
    cb::Ref<int> b(j);

    a = b;

    REQUIRE(*a == testValue2);
}

TEST_CASE( "cc::Ref assign move" ) {
    int i = testValue1;
    int j = testValue2;

    cb::Ref<int> a(i);
    cb::Ref<int> b(j);

    a = std::move(b);

    REQUIRE(*a == testValue2);
}

TEST_CASE( "cc::Ref get" ) {
    int i = testValue1;

    cb::Ref<int> a(i);
    const cb::Ref<int>& b(a);

    REQUIRE(*b == testValue1);
}

TEST_CASE( "cc::Ref ->" ) {
    Foo a;

    cb::Ref<Foo> b(a);

    b->a();
}

TEST_CASE( "cc::make_ref" ) {
    Bar a;

    cb::Ref<Foo> b = cb::make_ref(a);

    b->a();
}

TEST_CASE( "cc::OptionalRef default constructor" ) {
    cb::OptionalRef<int> a;

    REQUIRE(a == nullptr);
}

TEST_CASE( "cc::OptionalRef construct from ptr" ) {
    int i = testValue1;

    cb::OptionalRef<int> a(&i);

    REQUIRE(a == &i);
}

TEST_CASE( "cc::OptionalRef construct from ref" ) {
    int i = testValue1;

    cb::OptionalRef<int> a(i);

    REQUIRE(a == &i);
}

TEST_CASE( "cc::OptionalRef construct from copy" ) {
    int i = testValue1;

    cb::OptionalRef<int> a(i);
    cb::OptionalRef<int> b(a);

    REQUIRE(b == &i);
}

TEST_CASE( "cc::OptionalRef construct from move" ) {
    int i = testValue1;

    cb::OptionalRef<int> a(i);
    cb::OptionalRef<int> b(std::move(a));

    REQUIRE(b == &i);
}

TEST_CASE( "cc::OptionalRef assign copy" ) {
    int i = testValue1;

    cb::OptionalRef<int> a(i);
    cb::OptionalRef<int> b;

    b = a;

    REQUIRE(b == &i);
}

TEST_CASE( "cc::OptionalRef assign move" ) {
    int i = testValue1;

    cb::OptionalRef<int> a(i);
    cb::OptionalRef<int> b;

    b = a;

    REQUIRE(b == &i);
}

