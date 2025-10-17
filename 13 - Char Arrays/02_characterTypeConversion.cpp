/**
 * @file 02_characterTypeConversion.cpp
 * @brief Identifies character type and converts uppercase to lowercase.
 *
 * Problem Statement:
 * - Check if a character is uppercase, lowercase, or digit.
 * - Convert uppercase to lowercase manually using ASCII manipulation.
 */

#include <iostream>
using namespace std;

int main()
{
    char ch1 = 'D'; // Initialize with a sample character

    // Check if character is uppercase letter (ASCII range: 65–90)
    if ('A' <= ch1 && ch1 <= 'Z')
    {
        cout << ch1 << " is an uppercase letter\n";

        // Convert uppercase → lowercase by shifting ASCII difference
        ch1 = ch1 - 'A' + 'a';
        cout << ch1 << " now is a lowercase letter\n";
    }
    // Check if character is lowercase letter (ASCII range: 97–122)
    else if ('a' <= ch1 && ch1 <= 'z')
        cout << ch1 << " is already a lowercase letter\n";

    // Check if character is a digit (ASCII range: 48–57)
    else if ('0' <= ch1 && ch1 <= '9')
        cout << ch1 << " is a digit\n";

    // Otherwise, not alphanumeric
    else
        cout << ch1 << " is neither a digit nor a letter\n";

    return 0;
}
