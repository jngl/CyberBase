//
// Created by jngl on 21/08/2021.
//

#include <catch2/catch_test_macros.hpp>
#include <CyberBase/Component.h>
#include <CyberBase/Common.h>
#include <CyberBase/Id.h>

using Id = cb::Id<cb::Uint16, struct id>;

struct Comp {
    int value = 0;
};

TEST_CASE( "cc::ComponentManager" ) {
    constexpr int value = 42;
    Id id(0);

    cb::ComponentManager<Comp, Id> componentManager;

    { // Construct
        cb::OptionalRef<Comp> comp = componentManager.get(id);
        REQUIRE(!comp.hasValue());
    }

    { // create
        Comp &comp2 = componentManager.create(id);
        comp2.value = value;

        cb::OptionalRef<Comp> comp3 = componentManager.get(id);
        REQUIRE(comp3.hasValue());
        REQUIRE(comp3->value == value);
    }

    { // destroy
        componentManager.destroy(Id(0));

        cb::OptionalRef<Comp> comp4 = componentManager.get(id);
        REQUIRE(!comp4.hasValue());
    }
}
