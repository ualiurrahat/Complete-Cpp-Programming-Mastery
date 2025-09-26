/**
 * @file 12_copyConstructor.cpp
 * @brief Demonstrates the concept of a Copy Constructor in C++.
 *
 * A copy constructor is used to create a new object as a copy of an existing object.
 * If the programmer does not define one, the compiler provides a default version.
 */

#include <iostream>
using namespace std;

/**
 * @class Number
 * @brief Represents a number and demonstrates copy constructor behavior.
 */
class Number
{
    int a; ///< Integer value

public:
    /// Default constructor
    Number()
    {
        a = 0;
    }

    /// Parameterized constructor
    Number(int num)
    {
        a = num;
    }

    /**
     * @brief Copy constructor
     * @param obj Another object of class Number to copy from
     */
    Number(Number &obj)
    {
        cout << "Copy constructor called!!!" << endl;
        a = obj.a;
    }

    /// Displays the value of 'a'
    void display()
    {
        cout << "The number for this object is " << a << endl;
    }
};

// ------------------------------- Main -------------------------------
int main()
{
    Number x, y, z(45), z2;

    // Default and parameterized constructors called here
    x.display(); // Output: 0
    y.display(); // Output: 0
    z.display(); // Output: 45

    // Copy constructor called explicitly
    Number z1(z);
    z1.display();

    // Assignment operator used (not copy constructor)
    z2 = z;
    z2.display();

    // Copy constructor called during initialization
    Number z3 = z;
    z3.display();

    return 0;
}
