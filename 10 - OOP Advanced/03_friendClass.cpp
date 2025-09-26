/**
 * @file 03_friendClass.cpp
 * @brief Demonstrates friend classes in C++.
 *
 * @details
 * A friend class can access private members of another class. This
 * example shows how the Calculator class is a friend of the Complex class,
 * and can access its private members.
 */

#include <iostream>
#include <string>
using namespace std;

// Forward declaration of Complex
class Complex;

/**
 * @class Calculator
 * @brief Demonstrates friend class functionality.
 */
class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    int sumRealPart(Complex, Complex);
    int sumComplexPart(Complex, Complex);
};

/**
 * @class Complex
 * @brief Represents a complex number with real and imaginary parts.
 */
class Complex
{
    int a; ///< Real part
    int b; ///< Imaginary part

    /// Declare Calculator as a friend class
    friend class Calculator;

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
};

// Definition of Calculator member functions
int Calculator::sumRealPart(Complex ob1, Complex ob2)
{
    return (ob1.a + ob2.a);
}

int Calculator::sumComplexPart(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}

int main()
{
    Complex o1, o2;
    o1.setNumber(1, 4);
    o2.setNumber(5, 9);

    Calculator cal;
    int result = cal.sumRealPart(o1, o2);
    cout << "The sum of real part of o1 and o2 is " << result << endl;

    int result2 = cal.sumComplexPart(o1, o2);
    cout << "The sum of complex part of o1 and o2 is " << result2 << endl;

    return 0;
}
