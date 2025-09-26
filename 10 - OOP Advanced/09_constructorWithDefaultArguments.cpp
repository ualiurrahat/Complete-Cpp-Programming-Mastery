/**
 * @file 09_constructorWithDefaultArguments.cpp
 * @brief Demonstrates Constructor with Default Arguments in C++.
 *
 * Default arguments: Values assigned in constructor declaration
 * that are automatically used if no value is provided for them
 * during object creation.
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
     * @brief Constructor with default argument
     * @param x Real part
     * @param y Imaginary part (default value = 25)
     */
    Complex(int x, int y = 25)
    {
        a = x;
        b = y;
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
    Complex c1(2, 5); // Both arguments provided
    c1.PrintNum();    // Output: 2 + 5i

    Complex c2(7); // Only one argument provided, b = 25 by default
    c2.PrintNum(); // Output: 7 + 25i

    return 0;
}
