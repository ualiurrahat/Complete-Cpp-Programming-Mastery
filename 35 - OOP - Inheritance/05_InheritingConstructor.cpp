// <DOCUMENT filename="05_InheritingConstructors.cpp">
#include <iostream>
#include <vector>
using namespace std;

/**
 * @file 05_InheritingConstructors.cpp
 * @brief Demonstrates C++11 constructor inheritance using `using Base::Base;`
 *
 * Key Concept: Avoid duplicating base class constructor logic in derived classes.
 *
 * Intuition:
 * - Class A has a constructor taking `x` and `y`
 * - Class B wants to reuse it without rewriting
 * - `using A::A;` brings all base constructors into derived scope
 *
 * Note: Only works in C++11 and later.
 */

class A
{
public:
    int x; ///< Public data member x
    int y; ///< Public data member y

    /**
     * @brief Constructs A with given x and optional y.
     *
     * @param x Value for member x
     * @param y Value for member y (default = 20)
     *
     * Uses member initializer list for efficiency.
     */
    A(int x, int y = 20) : x(x), y(y)
    {
        // No body needed — initialization done in list
    }
};

class B : public A
{
    int z; ///< B adds its own member

public:
    // Inherit ALL constructors from A
    // This includes: A(int), A(int, int)
    using A::A;

    // Note: Default constructor is NOT inherited automatically
    // We could define B() : A(0, 0), z(0) {} if needed
};

int main()
{
    B b(3); // Uses inherited constructor A(3, 20)

    cout << b.x << " " << b.y; // Output: 3 20
    // b.z is uninitialized — not set by inherited ctor

    return 0;
}