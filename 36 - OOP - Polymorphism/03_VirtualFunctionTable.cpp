// <DOCUMENT filename="03_VirtualFunctionTable.cpp">
#include <iostream>
using namespace std;

/**
 * @file 03_VirtualFunctionTable.cpp
 * @brief Demonstrates vtable behavior and the importance of `virtual` in base.
 *
 * Key Lesson:
 * - `override` requires the base function to be `virtual`
 * - If base function is non-virtual → derived version HIDES it, does NOT override
 * - Only `virtual` functions are dispatched via vtable
 */

class A
{
public:
    virtual void f1() { cout << "A::f1\n"; }
    void f2() { cout << "A::f2\n"; } // Non-virtual
    void f3() { cout << "A::f3\n"; } // Non-virtual
    virtual ~A() = default;
};

class B : public A
{
public:
    void f1() override { cout << "B::f1\n"; } // OK: overrides virtual
    virtual void f2() { cout << "B::f2\n"; }  // Makes f2 virtual from B onward
    void f3() { cout << "B::f3\n"; }          // HIDING, not overriding!
    // override would be ERROR here
};

class C : public B
{
public:
    void f1() override { cout << "C::f1\n"; }
    void f2() override { cout << "C::f2\n"; } // OK: B made it virtual
    virtual void f3() { cout << "C::f3\n"; }  // Makes f3 virtual from C onward
};

class D : public C
{
public:
    void f1() override { cout << "D::f1\n"; }
    void f2() override { cout << "D::f2\n"; }
    void f3() override { cout << "D::f3\n"; } // OK: C made it virtual
};

int main()
{
    cout << "=== B* -> D object ===\n";
    B *d1 = new D();
    d1->f1(); // D::f1 → vtable
    d1->f2(); // D::f2 → vtable (B made virtual)
    d1->f3(); // D::f3 → vtable (C made virtual)
    cout << "\n";

    cout << "=== A* -> D object ===\n";
    A *d2 = new D();
    d2->f1(); // D::f1 → vtable
    d2->f2(); // A::f2 → NOT virtual in A → static binding!
    d2->f3(); // A::f3 → NOT virtual in A → static binding!
    cout << "\n";

    delete d1;
    delete d2;
    return 0;
}