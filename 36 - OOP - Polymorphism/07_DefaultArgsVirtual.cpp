// <DOCUMENT filename="07_DefaultArgsVirtual.cpp">
#include <iostream>
using namespace std;

/**
 * @file 07_DefaultArgsVirtual.cpp
 * @brief Pitfall: Default args are STATIC (from base class).
 *
 * Rule:
 * - Function signature (including defaults) resolved at **compile time**
 * - Body resolved at **runtime**
 * → Default comes from **pointer type**, not object type!
 */

class A
{
public:
    virtual void f1(int x = 1) { cout << x << " in A\n"; }
};

class B : public A
{
public:
    void f1(int x = 2) override { cout << x << " in B\n"; }
};

int main()
{
    A *a = new B();
    a->f1(); // 1 in B → default from A!
    delete a;
    return 0;
}