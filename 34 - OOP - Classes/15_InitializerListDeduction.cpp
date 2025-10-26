/**
 * @file 15_InitializerListDeduction.cpp
 * @brief Rules for `auto` with braced initializers.
 *
 * - `{1,2}` → `std::initializer_list<int>`
 * - `{1,2.0}` → **error**: cannot deduce common type
 * - `{3}` → `std::initializer_list<int>`
 * - `{3}` with **single element** and C++14 → `int` if using `auto x{3}`
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    auto x1 = {1, 2}; // std::initializer_list<int>
    // auto x2 = {1, 2.0};  // ERROR: no common type
    // auto x3{1, 2};       // ERROR: not single element
    auto x4 = {3}; // initializer_list<int>
    auto x5{3};    // int (C++14 direct-list-init with single element)

    cout << "x5 = " << x5 << " (type: int)\n";

    return 0;
}