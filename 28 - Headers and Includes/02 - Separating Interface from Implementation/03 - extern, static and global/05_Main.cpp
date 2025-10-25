/**
 * @file 05_Main.cpp
 * @brief Entry point – shows how the three translation units interact.
 *
 * @note `st_gl_per_include` exists **three times**: in `main.cpp`, `sum.cpp`, and `another.cpp`.
 */

#include <iostream>
#include "01_SumHeader.cpp"
#include "03_AnotherHeader.cpp"
using namespace std;

int main()
{
    visibile_anywere += 40;
    st_gl_per_include += 40; // main's own copy

    for (int i = 0; i < 3; ++i)
        sum_1_n(10);

    go();

    cout << "st_gl_per_include=" << st_gl_per_include
         << " visibile_anywere=" << visibile_anywere << "\n";

    return 0;
}