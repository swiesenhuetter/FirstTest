#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "OptVal.h"
#include <iostream>

TEST_CASE("test compare"){
    OptVal<double> o1{1.0/3.0};
    OptVal<double> o2{1.0/3.0};
    REQUIRE(o1 == o2);
}

TEST_CASE("test assignment"){
    OptVal<double> o1{9};
    OptVal<double> o2;
    REQUIRE( *o1 == 9.0);
    o2 = o1;
    REQUIRE( *o1 == 9.0);
    REQUIRE( *o2 == 9.0);
    OptVal<double> o3;
    o1 = o3;
    REQUIRE_FALSE(o1);
}

TEST_CASE("test copy"){
    OptVal<double> o1{9};
    OptVal<double> o2(o1);
    REQUIRE( *o1 == 9.0);
    REQUIRE( *o2 == 9.0);
}

TEST_CASE("test move") {
    OptVal<double> o1{1.2345};
    OptVal<double> o2 = std::move(o1);
    REQUIRE_FALSE(o1);
    REQUIRE(*o2 == 1.2345);
}

TEST_CASE("test dereference access"){
    OptVal<double> opt{1.1};
    REQUIRE(1.1 == *opt);
}

TEST_CASE("test check"){
    OptVal<double> o1{1.1};
    OptVal<double> o2;
    REQUIRE(o1);
    REQUIRE_FALSE(o2);
}

int main(int argc, char** argv) {
    constexpr auto numbits {sizeof(long)*8};
    std::cout << "we are on a " << numbits << " bit platform\n";
    Catch::Session().run(argc, argv);
    return 5;
}