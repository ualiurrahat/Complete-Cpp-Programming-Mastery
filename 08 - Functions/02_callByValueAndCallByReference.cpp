/**
 * @file 02_callByValueAndCallByReference.cpp
 * @brief Demonstrates call by value, call by reference (using pointers), and call by reference (using reference variables) in C++.
 */

#include <iostream>
using namespace std;

/**
 * @brief Swaps two integers using call by value.
 * @param a First integer
 * @param b Second integer
 * @note The swap will NOT work as only copies of variables are passed.
 */
void valueSwap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

/**
 * @brief Swaps two integers using call by reference with pointers.
 * @param a Pointer to first integer
 * @param b Pointer to second integer
 */
void referenceSwap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Swaps two integers using reference variables.
 * @param a Reference to first integer
 * @param b Reference to second integer
 */
void referenceVarSwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a, b;
    cout << "Enter the value of num1: ";
    cin >> a;
    cout << "Enter the value of num2: ";
    cin >> b;

    cout << "Initial values: a = " << a << ", b = " << b << "\n\n";

    valueSwap(a, b);
    cout << "[Call by Value] After swap: a = " << a << ", b = " << b << "\n\n";

    referenceSwap(&a, &b);
    cout << "[Call by Reference (pointers)] After swap: a = " << a << ", b = " << b << "\n\n";

    referenceVarSwap(a, b);
    cout << "[Call by Reference (reference variables)] After swap: a = " << a << ", b = " << b << endl;

    return 0;
}
