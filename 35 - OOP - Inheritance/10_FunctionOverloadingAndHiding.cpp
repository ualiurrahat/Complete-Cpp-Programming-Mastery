// <DOCUMENT filename="10_FunctionOverloadingAndHiding.cpp">
#include <iostream>
#include <vector>
using namespace std;

/**
 * @file 10_FunctionOverloadingAndHiding.cpp
 * @brief Demonstrates function overloading vs. overriding vs. hiding.
 *
 * Key Insight:
 * - Overloading: same name, different parameters
 * - Overriding: same signature in derived class
 * - Hiding: derived class function hides ALL base versions with same name
 *
 * Here: B defines f1() with same names → hides A's versions
 */

class A
{
public:
    void f1() { cout << "A::f1\n"; }
    void f1(int x) { cout << "A::f1(x)\n"; }
    void f1(int x, int y) { cout << "A::f1(x,y)\n"; }
};

class B : public A
{
public:
    void f1() { cout << "B::f1\n"; }
    void f1(int x) { cout << "B::f1(x)\n"; }
    void f1(int x, int y) { cout << "B::f1(x,y)\n"; }
    // All A's f1 functions are now HIDDEN
};

int main()
{
    B *b1 = new B();
    b1->f1();     // B::f1
    b1->f1(1);    // B::f1(x)
    b1->f1(1, 2); // B::f1(x,y)

    // To call base: b1->A::f1();

    delete b1;
    return 0;
}