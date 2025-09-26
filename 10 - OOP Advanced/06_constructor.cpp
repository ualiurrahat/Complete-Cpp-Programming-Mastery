/**
 * @file 06_constructor.cpp
 * @brief Demonstrates the concept of a Default Constructor in C++.
 *
 * A constructor is a special member function of a class that is automatically
 * invoked when an object is created. It has the same name as the class,
 * has no return type, and is typically used for initializing objects.
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
     * @brief Default constructor
     *
     * - A default constructor takes no parameters.
     * - Automatically called when an object is created.
     * - Initializes the object with fixed values.
     */
    Complex();

    /**
     * @brief Prints the complex number in standard form.
     */
    void PrintNum()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

// ---------------- Definition of Default Constructor ----------------
Complex::Complex()
{
    a = 10;
    b = 5;
}

// ------------------------------- Main -------------------------------
int main()
{
    // Creating an object invokes the default constructor automatically.
    Complex c1;
    c1.PrintNum(); // Output: Your number is 10 + 5i

    return 0;
}
