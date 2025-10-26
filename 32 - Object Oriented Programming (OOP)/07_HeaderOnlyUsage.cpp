/**
 * @file 07_HeaderOnlyUsage.cpp
 * @brief Uses Rectangle class via header inclusion (clean separation).
 *
 * This is the **user's perspective**: include header, use class, no implementation visible.
 *
 * @section intuition Intuition
 * Promotes **modularity** and **reusability**.
 * Multiple files can include `rectangle.h` and link with `rectangle.cpp`.
 */

#include <iostream>
#include "rectangle.h" // Only interface needed
using namespace std;

int main()
{
    Rectangle r1;
    r1.SetWidth(5);
    r1.SetHeight(10);
    cout << r1.ComputeArea() << "\n"; // 50

    Rectangle r2(10, 3);
    cout << r2.ComputeArea() << "\n"; // 30
    r2.SetWidth(0);
    cout << r2.ComputeArea() << "\n"; // 0

    return 0;
}