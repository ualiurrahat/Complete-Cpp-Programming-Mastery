/**
 * @file 14_protectedAccessModifier.cpp
 * @brief Demonstrates the concept of Protected Access Modifier in C++.
 *
 * Access Modifier Reference Table:
 * | Member Type        | Public Inheritance | Private Inheritance | Protected Inheritance |
 * |--------------------|--------------------|----------------------|-----------------------|
 * | Private members    | Not inherited      | Not inherited        | Not inherited         |
 * | Protected members  | Protected          | Private              | Protected             |
 * | Public members     | Public             | Private              | Protected             |
 *
 * @details
 * - Protected access modifier is similar to private.
 * - However, protected members **can be accessed by derived classes**, while private members cannot.
 */

#include <iostream>
#include <string>
using namespace std;

// ---------------------- Base Class ----------------------
class Base
{
protected:
    int a; ///< Example protected member, accessible in derived class.

private:
    int b; ///< Example private member, not accessible anywhere outside Base.
};

// ---------------------- Derived Class ----------------------
class Derived : protected Base
{
    // `a` from Base becomes protected here.
    // `b` remains inaccessible.
};

// ---------------------- Main Function ----------------------
int main()
{
    Base ob1;
    Derived ob2;

    // cout << ob2.a; ❌ Error: 'a' is protected, cannot access directly from outside.

    cout << "Protected members can only be accessed inside derived classes, not outside.\n";

    return 0;
}
