/**
 * @file 03_characterMapping.cpp
 * @brief Replace characters in a string using a predefined mapping.
 *
 * @question
 * You are given two strings:
 * - `from` = "abcdefghijklmnopqrstuvwxyz0123456789"
 * - `to`   = "YZIMNESTODUAPWXHQFBRJKCGVL!@#$%^&*()"
 *
 * For each character in the input string, replace it with the corresponding
 * character from the mapping. Ignore uppercase letters.
 *
 * Example:
 * Input:
 * code123
 * Output:
 * DTUF!@#
 */

#include <iostream>
using namespace std;

int main()
{
    // Mapping from lowercase letters and digits to special characters
    string from = "abcdefghijklmnopqrstuvwxyz0123456789";
    string to = "YZIMNESTODUAPWXHQFBRJKCGVL!@#$%^&*()";

    char letterMap[150] = {0};

    // Build a lookup table for character mapping
    for (int index = 0; index < from.size(); ++index)
        letterMap[from[index]] = to[index];

    string str;
    cin >> str;

    // Replace characters using the mapping table
    for (int index = 0; index < str.size(); ++index)
    {
        // Ignore uppercase letters as per problem requirement
        if ('A' <= str[index] && str[index] <= 'Z')
            continue;

        str[index] = letterMap[str[index]];
    }

    cout << str;
    return 0;
}

/**
 * @example
 * Input:
 * hello123
 *
 * Output:
 * HQDDU!@#
 */
