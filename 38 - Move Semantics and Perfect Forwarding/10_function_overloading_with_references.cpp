// 10_function_overloading_with_references.cpp
#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Demonstrates function overloading with lvalue and rvalue references.
 */
void f1(int &a) { cout << "f1(int &a)\n"; }
void f1(const int &a) { cout << "f1(const int &a)\n"; }

void f2(int &a) { cout << "f2(int &a)\n"; }
void f2(const int &a) { cout << "f2(const int &a)\n"; }
void f2(int &&a) { cout << "f2(int &&a)\n"; } // Preferred for prvalues

/**
 * @brief Shows overload resolution rules.
 *
 * @details
 * - prvalue prefers `int&&` over `const int&` → avoids copy.
 */
int main()
{
    int x = 1;
    int &y = x;
    const int z = 2;

    f1(x);  // f1(int &a)
    f1(y);  // f1(int &a)
    f1(z);  // f1(const int &a)
    f1(10); // f1(const int &a)

    f2(x);  // f2(int &a)
    f2(y);  // f2(int &a)
    f2(z);  // f2(const int &a)
    f2(10); // f2(int &&a) → **best match**

    return 0;
}