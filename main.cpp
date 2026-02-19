// Tu Nombre
// Programa cliente que hace pruebas a la clase List implementada
// con arreglo dinámico


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include "List.hpp"

using namespace std;




TEST_CASE("Testing the inverse function...") {
    List L;
    // populate the list
    L.append(42); L.append(9); L.append(3); L.append(5); L.append(4);
    CHECK(L.toString() == "42 9 3 5 4");

    // invert and check
    L.inverse();
    CHECK(L.toString() == "4 5 3 9 42");


    // check that inverte  works with an empty list!
    List M;
    M.inverse();
    CHECK(M.toString() == "");

}

TEST_CASE("Testing the remove odd function...") {
    // You write the assertions!

}