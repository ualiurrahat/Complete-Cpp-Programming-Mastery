// 18_force_rvalue_with_static_cast.cpp
#include <iostream>
using namespace std;

/**
 * @brief Solves forwarding problem using `static_cast<T&&>(x)`
 */
void f2(int &a) { cout << "f2() \n"; }
void f2(int &&a) { cout << "f2&&() \n"; }

void f1(int &a)
{
    cout << "f1() \n";
    f2(a);
}

void f1(int &&a)
{
    cout << "f1&&() \n";
    f2(static_cast<int &&>(a)); // Force a to be treated as rvalue
}

int main()
{
    int x = 10;
    int &&xr = static_cast<int &&>(x); // xr is rvalue reference, but still lvalue by name

    f1(10); // f1&&() → f2&&()  Success!
    f1(xr); // f1() → f2()     xr is lvalue (has name)

    return 0;
}