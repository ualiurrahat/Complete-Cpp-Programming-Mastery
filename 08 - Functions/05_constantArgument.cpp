/**
 * @file 05_constantArgument.cpp
 * @brief Demonstrates constant arguments in functions.
 */

#include <iostream>
using namespace std;

/**
 * @brief Example function with constant arguments.
 * @note Function cannot modify arguments passed as constant.
 */
void swap(const int *a, const int *b)
{
    // This will not work as values are passed as constant pointers.
    const int *temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 33, b = 44;
    cout << "Before swap, a = " << a << ", b = " << b << endl;

    swap(&a, &b);

    cout << "After swap attempt, a = " << a << ", b = " << b << endl;
    return 0;
}
