// Gran cantidad de este código fue generado por chatGPT
// Yo lo adapté para simplificarlo para la clase


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include "List.h"

using namespace std;


TEST_CASE("Let's grow some lists and compare them") {
    List L;
    L.append(9);
    

    L.append(3); L.append(5); L.append(4);
    CHECK(L.toString() == "9 3 5 4");

    L.insert(42,0);
    List M;
    M = L;
    CHECK(M == L);
    CHECK(L.toString() == "42 9 3 5 4");

    L.inverse();
    CHECK(L.toString() == "4 5 3 9 42");
    CHECK_FALSE(L == M);
    L.inverse();
    CHECK(L == M);
    CHECK(L.toString() == "42 9 3 5 4");


}
