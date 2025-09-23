/**
 * @file 07_floatingPointLiterals.cpp
 * @brief Demonstrates floating-point literals and their default types in C++
 *
 * -----------------------------
 * 📘 Floating-point literals in C++
 * -----------------------------
 * - By default, any floating-point literal like `34.4` is of type `double`.
 * - To specify the type explicitly:
 *      - `f` or `F` → float literal (e.g., 34.4f)
 *      - `l` or `L` → long double literal (e.g., 34.4L)
 *
 * -----------------------------
 * 🔹 sizeof operator:
 * -----------------------------
 * - Used to check the memory size (in bytes) of a data type or literal.
 * - sizeof(34.4) → double
 * - sizeof(34.4f) or sizeof(34.4F) → float
 * - sizeof(34.4l) or sizeof(34.4L) → long double
 */

#include <iostream>
using namespace std;

int main()
{
    float d = 34.4;       // 34.4 is double, implicitly converted to float
    long double e = 34.4; // 34.4 is double, implicitly converted to long double

    cout << "The value of float d is " << d << endl;
    cout << "The value of long double e is " << e << endl;

    // Demonstrating the type sizes of floating-point literals
    cout << "The sizeof 34.4  is: " << sizeof(34.4) << endl;  // double
    cout << "The sizeof 34.4f is: " << sizeof(34.4f) << endl; // float
    cout << "The sizeof 34.4F is: " << sizeof(34.4F) << endl; // float
    cout << "The sizeof 34.4l is: " << sizeof(34.4l) << endl; // long double
    cout << "The sizeof 34.4L is: " << sizeof(34.4L) << endl; // long double

    return 0;
}
