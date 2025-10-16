/**
 * @file 09_typecasting.cpp
 * @brief Demonstrates typecasting in C++
 *
 * -----------------------------
 * 📘 Typecasting in C++:
 * -----------------------------
 * - Typecasting is used to convert a variable from one data type to another.
 * - Two main ways in C++:
 *      1. C-style: (type)variable  → e.g., (float)a
 *      2. Function-style: type(variable) → e.g., float(a)
 *
 * -----------------------------
 * 🔹 When to use:
 * -----------------------------
 * - Prevent data loss while performing operations.
 * - Convert floating point to integer (removes decimal part).
 * - Convert small type to large type explicitly.
 */

#include <iostream>
using namespace std;

int main()
{
    int a = 3;
    float b = 45.32;

    cout << "The value of int a is: " << a << endl;
    cout << "The value of float a (C-style cast): " << (float)a << endl;
    cout << "The value of float a (function-style cast): " << float(a) << endl
         << endl;

    cout << "The value of float b is: " << b << endl;
    cout << "The value of int b (C-style cast): " << (int)b << endl;
    cout << "The value of int b (function-style cast): " << int(b) << endl
         << endl;

    int c = int(b); // Explicit conversion stored in new variable
    cout << "The value of int c is: " << c << endl
         << endl;

    // Demonstrating type effects in expressions
    cout << "int a + float b = " << a + b << "   (Result is float)" << endl;
    cout << "int a + (int)b = " << a + (int)b << "   (Result is int)" << endl;
    cout << "int a + int(b) = " << a + int(b) << "   (Result is int)" << endl;

    return 0;
}
