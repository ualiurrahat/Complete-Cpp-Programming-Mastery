/**
 * @file 06_pointerToObjectAndArrayOperator.cpp
 * @brief Demonstrates pointers to objects and usage of the arrow operator in C++.
 *
 * Problem Statement:
 * - Learn how to create objects using pointers.
 * - Understand the precedence of dereference and dot operators.
 * - Explore the arrow operator (`->`) as shorthand for pointer object access.
 */

#include <iostream>
using namespace std;

class Complex
{
    int a;
    int b;

public:
    /// @brief Sets real and imaginary parts of the complex number
    void setData(int x, int y)
    {
        a = x;
        b = y;
    }

    /// @brief Prints the complex number parts
    void getData()
    {
        cout << "The real part is " << a << endl;
        cout << "The imaginary part is " << b << endl;
    }
};

int main()
{
    // ---------------------- Direct Object Access ----------------------
    Complex c1;
    c1.setData(5, 7);
    c1.getData();

    // ---------------------- Object through Pointer ----------------------
    Complex d;
    Complex *ptr = &d;
    (*ptr).setData(3, 5); // Dereference pointer then use dot
    (*ptr).getData();

    // ---------------------- Using Arrow Operator ----------------------
    Complex *ptr2 = new Complex;
    ptr2->setData(9, -3); // Shorthand for (*ptr2).setData(...)
    ptr2->getData();

    delete ptr2; // Free dynamically allocated memory

    return 0;
}
