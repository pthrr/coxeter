#include <catch2/catch_test_macros.hpp>

#include "../include/coxeter/point.h"

TEST_CASE( "point ctor", "[point]" )
{
    REQUIRE( cx::Point{ 1, 2, 3 }.size() == 3 );
}
