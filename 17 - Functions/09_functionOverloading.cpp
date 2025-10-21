/**
 * @file 09_functionOverloading.cpp
 * @brief Demonstrate function overloading in C++.
 *
 * @question
 * Show how multiple functions with the same name can work with different parameter types.
 */

#include <iostream>
using namespace std;

// Overloaded functions with different parameter lists
int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}

int add(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    cout << add(2, 3) << "\n";     // Uses int version
    cout << add(2.0, 3.5) << "\n"; // Uses double version

    return 0;
}
