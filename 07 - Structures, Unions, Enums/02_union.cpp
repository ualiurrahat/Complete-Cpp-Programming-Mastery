/**
 * @file 02_union.cpp
 * @brief Demonstrates use of unions in C++.
 *
 * Union allows storing different data types in the same memory location.
 * Only one member can hold a value at a time (others will be overwritten).
 * Useful for memory-efficient programming.
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: Equal to size of the largest member
 */

#include <iostream>
using namespace std;

union Currency
{
    int cash;
    char label;
    float dolla;
};

int main()
{
    Currency c1;

    c1.cash = 4342;
    c1.label = 'A';  // overwrites cash
    c1.dolla = 60.5; // overwrites both cash and label

    cout << "Current Union Value (dolla): " << c1.dolla << endl;

    c1.label = 'B'; // overwrites dolla
    cout << "Current Union Value (label): " << c1.label << endl;

    c1.cash = 1234; // overwrites label
    cout << "Current Union Value (cash): " << c1.cash << endl;

    return 0;
}
