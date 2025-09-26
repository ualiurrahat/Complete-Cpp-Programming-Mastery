/**
 * @file 01_class.cpp
 * @brief Demonstrates Class, Public and Private Access Modifiers in C++.
 *
 * Why use Classes instead of Structures?
 * ---------------------------------------
 * - In C++ structures, all members are public by default. This makes them less secure
 *   since data cannot be hidden.
 * - Functions cannot be added in structures, making them less powerful for OOP.
 * - Classes solve these problems by supporting:
 *      - Data hiding (private/protected members).
 *      - Member functions.
 *
 * Access Modifiers in C++:
 * -------------------------
 * 1. Public:
 *    - Accessible both inside and outside the class.
 *    - Accessed using the dot (.) operator.
 *
 * 2. Private:
 *    - Accessible only inside the class.
 *    - Not accessible directly by objects.
 *
 * Example program below demonstrates private and public access.
 */

#include <iostream>
using namespace std;

class Employee
{
private:
    int a, b, c; ///< Private members (cannot be accessed directly from outside)

public:
    int d, e; ///< Public members (accessible directly)

    /**
     * @brief Sets values of private members.
     * @param a1 First number.
     * @param b1 Second number.
     * @param c1 Third number.
     */
    void setData(int a1, int b1, int c1);

    /**
     * @brief Displays both private and public member values.
     */
    void getData();
};

// Function definition outside class using scope resolution
void Employee::setData(int a1, int b1, int c1)
{
    a = a1;
    b = b1;
    c = c1;
}

void Employee::getData()
{
    cout << "The value of a is " << a << endl;
    cout << "The value of b is " << b << endl;
    cout << "The value of c is " << c << endl;
    cout << "The value of d is " << d << endl;
    cout << "The value of e is " << e << endl;
}

int main()
{
    Employee rahat;
    rahat.setData(12, 24, 36);
    rahat.d = 25;
    rahat.e = 39;

    // The following will throw an error because 'a' is private:
    // rahat.a = 10;

    rahat.getData();

    return 0;
}
