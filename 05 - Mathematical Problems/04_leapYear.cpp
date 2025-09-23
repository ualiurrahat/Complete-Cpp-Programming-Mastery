/**
 * @file 04_leapYear.cpp
 * @brief Program to check whether a given year is a leap year.
 *
 * Leap year rules:
 * - Divisible by 400 → Leap year
 * - Divisible by 4 but not divisible by 100 → Leap year
 * - Otherwise → Not a leap year
 */

#include <iostream>
using namespace std;

int main()
{
    int year;

    while (1)
    {
        cout << "Enter year (0 to exit): ";
        cin >> year;

        if (year == 0)
        {
            cout << "Exiting program..." << endl;
            break;
        }

        // Leap year condition check
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        {
            cout << year << " is a Leap Year ✅" << endl;
        }
        else
        {
            cout << year << " is NOT a Leap Year ❌" << endl;
        }
    }

    return 0;
}

/**
 * Example Run:
 * Input: 2000
 * Output: 2000 is a Leap Year ✅
 *
 * Input: 1900
 * Output: 1900 is NOT a Leap Year ❌
 *
 * Input: 2024
 * Output: 2024 is a Leap Year ✅
 */
