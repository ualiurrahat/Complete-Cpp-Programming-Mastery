/**
 * @file 03_multipleDataTypes.cpp
 * @brief Demonstrates multiple C++ data types: int, double, char, bool, string.
 *
 * @details
 * - int: integer numbers
 * - double: floating point numbers
 * - char: single character
 * - bool: true/false
 * - string: sequence of characters
 */

#include <iostream>
using namespace std;

int main()
{
    double weight = -92.5;      // negative decimal
    char group = 'd';           // single character
    bool is_male = true;        // boolean true
    bool like_football = false; // boolean false
    int age = 55;               // integer
    string name = "mostafa";    // text

    // Print information
    cout << "I am " << age << " years old\n";
    cout << "My weight is " << weight << "\n";

    cout << "My name is " << name
         << " and group " << group << "\n"
         << "Is male? " << is_male << ", Likes football? " << like_football << "\n";

    return 0;
}
