// 09_value_categories_and_references.cpp
#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

/**
 * @brief Clarifies value categories: lvalue, prvalue, xvalue.
 *
 * @details
 * - **lvalue**: has identity, not movable.
 * - **prvalue**: pure rvalue (literal, temp).
 * - **xvalue**: expiring value (e.g., `std::move(x)`).
 * - **Variable name is always lvalue**, even if type is `T&&`.
 */
int main()
{
    int &&r1 = 10; // r1 is rvalue reference type

    cout << r1 << " " << &r1 << " " << sizeof(r1) << "\n";
    // Output: 10 <address> 4 → r1 has address → **lvalue expression**

    int *p = &r1; // OK: &r1 is valid → r1 is lvalue in this context

    int x = 1;
    int &y = x; // y is lvalue reference, but `y` is lvalue expression

    // Key: **Value category depends on expression**, not variable type

    return 0;
}