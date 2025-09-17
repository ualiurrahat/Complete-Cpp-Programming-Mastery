/**
 * @file 02_dataTypes.cpp
 * @brief Demonstrates built-in data types in C++.
 *
 * Common Data Types:
 * - int       : Usually 4 bytes, stores whole numbers.
 * - char      : 1 byte, stores single character.
 * - float     : 4 bytes, stores decimal numbers (6–7 digits precision).
 * - double    : 8 bytes, higher precision decimals.
 * - bool      : 1 byte, stores true(1)/false(0).
 *
 * Note: Sizes may vary depending on compiler/system.
 */

#include <iostream>
using namespace std;

int main()
{
    int a = 3, b = 5;
    char c = 'm';
    float d = 3.3;
    bool isTrue = true, isFalse = false;

    cout << a << b << "\n"; // Prints without space
    cout << "The value of int a is " << a << ".\n";
    cout << "The value of int b is " << b << ".\n";
    cout << "The value of char c is " << c << ".\n";
    cout << "The value of float d is " << d << ".\n";
    cout << "The value of bool isTrue is " << isTrue << ".\n";
    cout << "The value of bool isFalse is " << isFalse << ".\n";

    return 0;
}
