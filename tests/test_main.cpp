#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

TEST_CASE("Sanity Check", "[basic]") {
    REQUIRE(2 + 2 == 4);
}