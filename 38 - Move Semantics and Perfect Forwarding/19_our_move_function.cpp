// 19_our_move_function.cpp
#include <iostream>
using namespace std;

/**
 * @brief Implements `OurMove` — a simplified version of `std::move`.
 *
 * @details
 * - Converts lvalue → xvalue (movable).
 * - Returns rvalue reference.
 * - Does **not** move — just changes value category.
 */
int &&OurMove(int &x)
{
    return static_cast<int &&>(x);
}

void f2(int &a) { cout << "f2() \n"; }
void f2(int &&a) { cout << "f2&&() \n"; }

void f1(int &a)
{
    cout << "f1() \n";
    f2(a);
}

void f1(int &&a)
{
    cout << "f1&&() \n";
    f2(OurMove(a)); // a (lvalue) → xvalue → binds to f2(int&&)
}

int main()
{
    f1(10); // f1&&() → f2&&()  Success!

    return 0;
}