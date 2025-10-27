// 11_reference_collapsing_and_forwarding.cpp
#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Shows why rvalue references in templates become lvalues inside functions.
 */
void f2(int &a) { cout << "f2() \n"; }
void f2(int &&a) { cout << "f2&&() \n"; }

void f1(int &a)
{
    cout << "f1() \n";
    f2(a); // a is lvalue → calls f2(int&)
}

void f1(int &&a)
{
    cout << "f1&&() \n";
    f2(a); // a is named → lvalue → calls f2(int&), not f2(int&&)
}

int main()
{
    int x = 10;
    int &&xr = 20;

    f2(x);  // f2()
    f2(10); // f2&&()
    f1(x);  // f1() → f2()
    f1(10); // f1&&() → f2()  (not f2&&!)

    f2(xr); // f2(): xr is lvalue (has name)

    return 0;
}