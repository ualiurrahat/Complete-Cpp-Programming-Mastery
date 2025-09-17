/**
 * @file 05_boolVariable.cpp
 * @brief Demonstrates boolean data type in C++.
 *
 * - By default, `true` prints as 1 and `false` as 0.
 * - `boolalpha` manipulator makes them print as "true"/"false".
 */

#include <iostream>
using namespace std;

int main()
{
    cout << boolalpha;        // Enable true/false output
    cout << true << endl;     // Prints "true"
    cout << (25 < 8) << endl; // Prints "false"
    return 0;
}
