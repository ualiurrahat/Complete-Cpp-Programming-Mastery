/**
 * @file 04_AnotherImplementation.cpp
 * @brief Implementation of `go()` – manipulates the globals.
 */

#include "01_SumHeader.cpp"
#include "03_AnotherHeader.cpp"
#include <iostream>
using namespace std;

void go()
{
    visibile_anywere += 20;
    st_gl_per_include += 20; // this is *its own* copy

    for (int i = 0; i < 3; ++i)
        sum_1_n(10);

    cout << "st_gl_per_include=" << st_gl_per_include
         << " visibile_anywere=" << visibile_anywere << "\n";
}