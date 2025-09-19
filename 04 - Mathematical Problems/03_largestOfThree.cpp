/**
 * @file 03_largestOfThree.cpp
 * @brief Program to find the largest number among three integers.
 */

#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    while (true)
    {
        cout << "Enter three integers (0 0 0 to exit): ";
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0)
        {
            break; // exit loop
        }

        // Nested conditions to find the largest number
        if (a > b)
        {
            if (a > c)
                cout << "Largest = " << a << endl;
            else
                cout << "Largest = " << c << endl;
        }
        else
        {
            if (b > c)
                cout << "Largest = " << b << endl;
            else
                cout << "Largest = " << c << endl;
        }
    }

    return 0;
}
