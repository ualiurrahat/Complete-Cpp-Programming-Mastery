/**
 * @file 01_lambda_basic_definition.cpp
 * @brief Demonstrates basic lambda function syntax and comparison with regular functions.
 *
 * This file introduces the concept of lambda expressions in C++.
 * We define a regular function `fsum1` and two lambda equivalents `fsum2` and `fsum3`.
 * Key learning points:
 * - Lambda syntax: `[](parameters) { body }`
 * - Semicolon required after lambda definition
 * - Return type deduction vs explicit specification
 */

#include <iostream>
using namespace std;

int fsum1(int x, int y)
{
    return x + y;
}

int main()
{
    // Lambda with no capture, auto return type (deduced as int)
    auto fsum2 = [](int x, int y)
    {
        return x + y; // Return type deduced from expression (int)
    }; // Semicolon required after lambda definition!

    cout << fsum1(3, 6) << " " << fsum2(3, 6) << "\n"; // Output: 9 9

    // Explicit return type using trailing return type syntax
    // Without -> int, this would cause compilation error due to conflicting return types
    auto fsum3 = [](int x, int y) -> int
    {
        if (true)
            return 2.5; // Truncated to int: 2 (warning in practice)
        return x + y;   // int return
    };

    // Note: Returning braced-init-list {x,y,x+y} is invalid for non-class return types
    // auto fsum4 = [](int x, int y) { return {x, y, x+y}; }; // Compilation error

    return 0;
}