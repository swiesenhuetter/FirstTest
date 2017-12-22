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
    REQUIRE( *o1.opt == 9.000);
    o2 = o1;
    REQUIRE( *o1.opt == 9.000);
    REQUIRE( *o2.opt == 9.000);
    OptVal<double> o3;
    o1 = o3;
    REQUIRE(o1.opt == nullptr);
}

TEST_CASE("test copy"){
    OptVal<double> o1{9};
    OptVal<double> o2(o1);
    REQUIRE( *o1.opt == 9.000);
    REQUIRE( *o2.opt == 9.000);
}

TEST_CASE("test move") {
    OptVal<double> o1{1.2345};
    OptVal<double> o2 = std::move(o1);
    REQUIRE(o1.opt == nullptr);
    REQUIRE(*o2.opt == 1.2345);
}

int main(int argc, char** argv) {
    constexpr auto numbits {sizeof(long)*8};
    std::cout << "we are on a " << numbits << " bit platform\n";
    Catch::Session().run(argc, argv);
    return 5;
}