/**
 * @file 02_friendFunction.cpp
 * @brief Demonstrates friend functions in C++.
 *
 * @details
 * A friend function is not a member of the class but has the right to
 * access its private members. This example uses a friend function to
 * add two complex numbers.
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @class Complex
 * @brief Represents a complex number.
 */
class Complex
{
    int a; ///< Real part
    int b; ///< Imaginary part

public:
    void setNumber(int m, int n)
    {
        a = m;
        b = n;
    }

    void printNumber()
    {
        cout << "Your complex number is " << a << " + " << b << "i" << endl;
    }

    /// Friend function declaration
    friend Complex sumComplexNumber(Complex o1, Complex o2);
};

/**
 * @brief Friend function to sum two Complex objects.
 * @param ob1 First complex number
 * @param ob2 Second complex number
 * @return Complex object containing the sum
 *
 * @note As a friend, this function can access private data members of `Complex`.
 */
Complex sumComplexNumber(Complex ob1, Complex ob2)
{
    Complex ob3;
    ob3.setNumber((ob1.a + ob2.a), (ob1.b + ob2.b));
    return ob3;
}

int main()
{
    Complex c1, c2, sum;

    c1.setNumber(1, 4);
    c2.setNumber(3, 7);

    c1.printNumber();
    c2.printNumber();

    sum = sumComplexNumber(c1, c2);
    sum.printNumber();

    return 0;
}
