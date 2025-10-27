// 03_reference_binding_rules.cpp
#include <iostream>
using namespace std;

/**
 * @brief Shows rules for binding references to different kinds of expressions.
 */
void f1(int a) {}        // Accepts prvalue or lvalue (by value)
void f2(int &a) {}       // Non-const lvalue reference
void f3(const int &a) {} // Const lvalue reference

/**
 * @brief Main function demonstrating reference binding rules.
 *
 * @details
 * - `f2(int&)` cannot bind to prvalues (temporaries).
 * - `f3(const int&)` can bind to prvalues, lvalues, and const lvalues.
 */
int main()
{
    int x = 1;
    const int y = 2;

    f1(10); // prvalue → copied
    f1(x);  // lvalue → copied
    f1(y);  // const lvalue → copied

    // f2(10);   // CE: cannot bind non-const lvalue ref to prvalue
    f2(x); // OK: x is modifiable lvalue
    // f2(y);    // CE: y is const

    f3(10); // OK: prvalue → binds to temporary
    f3(x);  // OK: lvalue
    f3(y);  // OK: const lvalue

    return 0;
}