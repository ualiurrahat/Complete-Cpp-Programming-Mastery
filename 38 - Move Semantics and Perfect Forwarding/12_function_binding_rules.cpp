// 12_function_binding_rules.cpp
#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Comprehensive rules for binding arguments to parameter types.
 */
void f1(int a) { cout << "f1\n"; }
void f2(int &a) { cout << "f2\n"; }
void f3(const int &a) { cout << "f3\n"; }
void f4(int &&a) { cout << "f4\n"; }

int main()
{
    int x = 1;
    const int y = 2;
    int &z = x;
    int &&w = 10;

    f1(x), f1(y), f1(z), f1(w), f1(10); // All OK: copy

    f2(x), f2(z); // OK: modifiable lvalue
    // f2(y);           // CE: const
    // f2(10);          // CE: prvalue
    f2(w); // OK: w is lvalue (named)

    f3(x), f3(y), f3(z), f3(w), f3(10); // All OK: const ref

    // f4(x), f4(y), f4(z), f4(w);  // CE: cannot bind rvalue ref to lvalue
    f4(10); // OK: prvalue

    return 0;
}