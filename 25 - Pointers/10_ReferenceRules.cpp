/**
 * @file 10_ReferenceRules.cpp
 * @brief Rules and restrictions of C++ references.
 *
 * Problem Statement:
 * Show what is NOT allowed with references to prevent common errors.
 *
 * New Topics Introduced:
 * - References **must be initialized** at declaration.
 * - Cannot rebind to another variable.
 * - Must refer to same type (no implicit conversion).
 * - Cannot be `nullptr`.
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int age = 55;
    int &ref = age;
    int another = 3;

    // ref = &another;     // ERROR: Cannot rebind
    // int &ref2;          // ERROR: Must initialize
    // int &ref2 = 3;      // ERROR: Must bind to variable
    // double val = 10;
    // int &ref3 = val;    // ERROR: Type mismatch

    return 0;
}