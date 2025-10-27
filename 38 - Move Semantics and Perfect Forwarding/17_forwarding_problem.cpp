// 17_forwarding_problem.cpp
#include <iostream>
using namespace std;

/**
 * @brief Demonstrates the "forwarding problem": rvalue reference becomes lvalue inside function.
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
    f1(10); // Expected: f1&&() → f2&&()
            // Actual:   f1&&() → f2()
            // We lost move semantics!

    return 0;
}