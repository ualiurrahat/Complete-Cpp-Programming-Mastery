/**
 * @file 03_ogicalOperators.cpp
 * @brief Demonstrates logical operators in C++.
 *
 * Operators covered:
 * ------------------
 * &&  (Logical AND)
 * ||  (Logical OR)
 * !   (Logical NOT)
 */

#include <iostream>
using namespace std;

int main()
{
    bool a = true, b = false;

    cout << "a = " << a << ", b = " << b << endl;

    cout << "a && b: " << (a && b) << endl;
    cout << "a || b: " << (a || b) << endl;
    cout << "!a    : " << (!a) << endl;
    cout << "!b    : " << (!b) << endl;

    return 0;
}
