/**
 * @file 09_functionOverloading.cpp
 * @brief Demonstrates function overloading with different datatypes.
 */

#include <iostream>
using namespace std;

void print(int)
{
    cout << "You passed an integer.\n";
}

void print(float)
{
    cout << "You passed a float.\n";
}

void print(double)
{
    cout << "You passed a double.\n";
}

void print(long double)
{
    cout << "You passed a long double.\n";
}

int main()
{
    print(3);
    print(3.3f);
    print(3.3);
    print(3.3l);

    return 0;
}
