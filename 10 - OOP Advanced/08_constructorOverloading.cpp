/**
 * @file 08_constructorOverloading.cpp
 * @brief Demonstrates the concept of Constructor Overloading in C++.
 *
 * Constructor Overloading: A class can have multiple constructors
 * with different parameter lists. Depending on the arguments
 * provided during object creation, the appropriate constructor is called.
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
    /// Two-parameter constructor
    Complex(int x, int y)
    {
        a = x;
        b = y;
    }

    /// Mono-parameter constructor
    Complex(int x)
    {
        a = x;
        b = 0;
    }

    /// Default constructor
    Complex()
    {
        a = 0;
        b = 0;
    }

    /// Prints the complex number
    void PrintNum()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

// ------------------------------- Main -------------------------------
int main()
{
    Complex c1(2, 5); // Calls two-parameter constructor
    c1.PrintNum();    // Output: 2 + 5i

    Complex c2(7); // Calls mono-parameter constructor
    c2.PrintNum(); // Output: 7 + 0i

    Complex c3;    // Calls default constructor
    c3.PrintNum(); // Output: 0 + 0i

    return 0;
}
