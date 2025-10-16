/**
 * @file 01temperatureConverter.cpp
 * @brief Program to convert temperature between Celsius and Fahrenheit.
 *
 * This program demonstrates the use of basic arithmetic operations and user input/output
 * in C++. It first converts Celsius to Fahrenheit and then Fahrenheit to Celsius.
 */

#include <iostream>
using namespace std;

/**
 * @note
 * Formula:
 * - Fahrenheit = (Celsius × 1.8) + 32
 * - Celsius    = (Fahrenheit - 32) / 1.8
 */
int main()
{
    double fahrenheit, celsius;

    // Celsius → Fahrenheit
    cout << "Enter Celsius: ";
    cin >> celsius;

    fahrenheit = 1.8 * celsius + 32;
    cout << "Fahrenheit = " << fahrenheit << endl;

    // Fahrenheit → Celsius
    cout << "Enter Fahrenheit: ";
    cin >> fahrenheit;

    celsius = (fahrenheit - 32) / 1.8;
    cout << "Celsius = " << celsius << endl;

    return 0;
}
