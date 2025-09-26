/**
 * @file 07_parameterizedConstructor.cpp
 * @brief Demonstrates the concept of a Parameterized Constructor in C++.
 *
 * A parameterized constructor allows passing arguments while creating an object.
 * This enables direct initialization of object data members.
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @class Complex
 * @brief Represents a complex number with real and imaginary parts.
 */
class Complex
{
    int a; ///< Real part
    int b; ///< Imaginary part

public:
    /**
     * @brief Parameterized constructor
     * @param x Real part
     * @param y Imaginary part
     */
    Complex(int x, int y);

    /**
     * @brief Prints the complex number in standard form.
     */
    void PrintNum()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

// ---------------- Definition of Parameterized Constructor ----------------
Complex::Complex(int x, int y)
{
    a = x;
    b = y;
}

// ------------------------------- Main -------------------------------
int main()
{
    // Implicit call
    Complex c1(4, 5);
    c1.PrintNum(); // Output: Your number is 4 + 5i

    // Explicit call
    Complex c2 = Complex(9, 7);
    c2.PrintNum(); // Output: Your number is 9 + 7i

    return 0;
}
