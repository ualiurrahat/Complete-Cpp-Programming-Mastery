/**
 * @file 01_arrayOfObject2.cpp
 * @brief Demonstrates passing objects as function arguments in C++.
 *
 * @details
 * This program defines a `Complex` class representing complex numbers.
 * Objects of this class can be passed as function arguments to perform
 * operations such as addition of complex numbers.
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
     * @brief Set the real and imaginary values of the complex number.
     * @param e Real part
     * @param f Imaginary part
     */
    void setData(int e, int f)
    {
        a = e;
        b = f;
    }

    /**
     * @brief Assigns the sum of two complex numbers to the current object.
     * @param ob1 First complex number
     * @param ob2 Second complex number
     *
     * @details This function demonstrates how objects can be passed
     * as arguments and used inside another object.
     */
    void setDataBySum(Complex ob1, Complex ob2)
    {
        a = ob1.a + ob2.a;
        b = ob1.b + ob2.b;
    }

    /**
     * @brief Displays the complex number in standard form.
     */
    void displayNumber()
    {
        cout << "Your complex number is: " << a << " + " << b << "i" << endl;
    }
};

int main()
{
    Complex c1, c2, c3;

    // Set and display first complex number
    c1.setData(1, 2);
    c1.displayNumber();

    // Set and display second complex number
    c2.setData(3, 4);
    c2.displayNumber();

    // Create third complex number as sum of c1 and c2
    c3.setDataBySum(c1, c2);
    c3.displayNumber();

    return 0;
}
