// <DOCUMENT filename="09_InheritanceAccessSpecifiers.cpp">
#include <iostream>
#include <vector>
using namespace std;

/**
 * @file 09_InheritanceAccessSpecifiers.cpp
 * @brief Shows how inheritance type changes member accessibility.
 *
 * | Base Member | public inheritance | protected inheritance | private inheritance |
 * |-------------|--------------------|------------------------|---------------------|
 * | public      | public             | protected              | private             |
 * | protected   | protected          | protected              | private             |
 * | private     | inaccessible       | inaccessible           | inaccessible        |
 */

class A
{
public:
    int x = 1; ///< Public in A
protected:
    int y = 2; ///< Protected in A
private:
    int z = 3; ///< Private in A
};

class B : public A
{
    // x → public
    // y → protected
    // z → inaccessible
};

class C : protected A
{
    // x → protected
    // y → protected
    // z → inaccessible
};

class D : private A
{
    // x → private
    // y → private
    // z → inaccessible
};

int main()
{
    A a;
    a.x = 1; // OK
    // a.y = 2;     // ERROR: protected
    // a.z = 3;     // ERROR: private

    B b;
    b.x = 1; // OK: public inheritance
    // b.y = 2;     // ERROR: protected

    C c;
    // c.x = 1;     // ERROR: now protected
    // c.y = 2;     // ERROR

    D d;
    // d.x = 1;     // ERROR: now private

    return 0;
}