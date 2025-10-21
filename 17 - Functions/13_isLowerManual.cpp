/**
 * @problem_statement
 * Write a program that checks whether a given string contains only lowercase English letters.
 */

#include <iostream>
using namespace std;

/**
 * @brief Determines if all characters in a string are lowercase.
 *
 * @param str Input string.
 * @return true if all characters are lowercase.
 * @return false otherwise.
 *
 * @note Time complexity: O(n)
 * @note Space complexity: O(1)
 */
bool is_lower(string str)
{
    for (int i = 0; i < (int)str.size(); ++i)
    {
        bool lower = 'a' <= str[i] && str[i] <= 'z';
        if (!lower)
            return false; // Found a non-lowercase character
    }
    return true;
}

int main()
{
    cout << is_lower("abc") << "\n"; // Output: 1 (true)
    cout << is_lower("aBC") << "\n"; // Output: 0 (false)
    return 0;
}
