// <DOCUMENT filename="10_DynamicVsStaticCast.cpp">
#include <iostream>
using namespace std;

/**
 * @file 10_DynamicVsStaticCast.cpp
 * @brief `dynamic_cast` (safe, RTTI) vs `static_cast` (fast, unsafe).
 */

class A
{
public:
    virtual ~A() = default;
};
class B : public A
{
};
class C : public A
{
};
class D
{
};

void test()
{
    A *a = new B();

    B *b1 = dynamic_cast<B *>(a); // OK
    C *c1 = dynamic_cast<C *>(a); // nullptr
    // D* d1 = dynamic_cast<D*>(a); // Compile error

    B *b2 = static_cast<B *>(a); // OK
    C *c2 = static_cast<C *>(a); // Undefined behavior!
    // D* d2 = static_cast<D*>(a); // Compile error

    cout << b1 << " " << c1 << " " << b2 << " " << c2 << "\n";
    delete a;
}

int main()
{
    test();
    return 0;
}