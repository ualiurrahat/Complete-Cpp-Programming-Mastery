/**
 * @file 01_charAsciiValues.cpp
 * @brief Demonstrates ASCII values of characters and their conversions.
 *
 * Problem Statement:
 * - Display ASCII integer values of uppercase and lowercase letters.
 * - Show relationship between characters and their numeric codes.
 */

#include <iostream>
using namespace std;

int main()
{
    // Declare a character and store 'A'
    char ch1 = 'A';

    // Convert character to integer (ASCII value)
    int ch_value = ch1;

    // Print ASCII value of 'A'
    cout << ch_value << "\n";

    // Display ASCII values of several uppercase characters
    cout << (int)'A' << "\n";
    cout << (int)'B' << "\n";
    cout << (int)'C' << "\n";
    cout << (int)'Z' << "\n";

    // Calculate last uppercase ASCII using formula: 'A' + 26 - 1 = 'Z'
    cout << (int)'A' + 26 - 1 << "\n";

    // Assign ASCII number 90 (which represents 'Z') to char variable
    char ch2 = 90;
    cout << ch2 << "\n"; // prints Z

    cout << "***\n";

    // Display ASCII values of lowercase characters
    cout << (int)'a' << "\n";
    cout << (int)'b' << "\n";
    cout << (int)'c' << "\n";
    cout << (int)'z' << "\n";
    cout << (int)'a' + 26 - 1 << "\n"; // last lowercase ASCII

    // Compare characters based on ASCII values ('A' < 'a' is true)
    cout << ('A' < 'a') << "\n";

    return 0;
}
