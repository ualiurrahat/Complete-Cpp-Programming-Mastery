/**
 * @file 01_introToFunction.cpp
 * @brief Demonstrates functions in C++.
 *
 * A function is a block of reusable code that performs a specific task.
 * - Function prototype declares the function.
 * - Function definition implements it.
 * - Functions help modularize and reuse code.
 *
 * @note Time Complexity: O(1) (for sum)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

// Function prototype (declaration)
int sum(int a, int b);

int main()
{
    int num1, num2;

    cout << "Enter the value of num1: ";
    cin >> num1;

    cout << "Enter the value of num2: ";
    cin >> num2;

    // Function call
    cout << "Sum = " << sum(num1, num2) << endl;

    return 0;
}

// Function definition
int sum(int a, int b)
{
    return a + b;
}
