/**
 * @file 08_scopeResolutionOperator.cpp
 * @brief Demonstrates the use of the Scope Resolution Operator (::) in C++
 *
 * -----------------------------
 * 📘 What is the Scope Resolution Operator (::)?
 * -----------------------------
 * - The scope resolution operator (::) is used in C++ to access a variable, function,
 *   or class that exists in a specific scope.
 * - It is most commonly used to:
 *      1. Access global variables when there is a local variable with the same name.
 *      2. Define class member functions outside the class.
 *      3. Access static members of a class.
 *
 * -----------------------------
 * 🔹 In this example:
 * -----------------------------
 * - We declare a global variable `c`.
 * - Inside `main()`, we declare a local variable `c` which hides the global one.
 * - To access the global `c`, we use the scope resolution operator `::c`.
 */

#include <iostream>
using namespace std;

int c = 44; // Global variable

int main()
{
    int a, b;

    cout << "Enter the value of int a: ";
    cin >> a;

    cout << "Enter the value of int b: ";
    cin >> b;

    int c = a + b; // Local variable 'c' shadows the global 'c'

    cout << "The value of local int c is: " << c << endl;

    // Using scope resolution operator (::) to access the global variable 'c'
    cout << "The value of global int c is: " << ::c << endl;

    // ⚠️ If no global 'c' is defined, ::c will cause an error.
    return 0;
}
