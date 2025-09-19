/**
 * @file 06_specialOperators.cpp
 * @brief Demonstrates special operators in C++ like sizeof and comma operator.
 */

#include <iostream>
using namespace std;

int main()
{
    // sizeof operator: tells the size of a data type in bytes
    cout << "Size of int = " << sizeof(int) << " bytes" << endl;
    cout << "Size of float = " << sizeof(float) << " bytes" << endl;
    cout << "Size of char = " << sizeof(char) << " bytes" << endl;
    cout << "Size of double = " << sizeof(double) << " bytes" << endl;

    // Comma operator: evaluates multiple expressions but returns the last one
    cout << endl
         << "Comma operator:" << endl;
    int a, b, sum;

    sum = (a = 20, b = 30, a + b); // sum takes result of last expression (a+b)
    cout << "Sum = " << sum << endl;

    return 0;
}
