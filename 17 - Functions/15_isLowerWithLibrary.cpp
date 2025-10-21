/**
 * @problem_statement
 * Rewrite the lowercase-checking program using standard library character functions (islower).
 */

#include <iostream>
#include <cctype> // Required for islower()
using namespace std;

/**
 * @brief Checks if all characters in the string are lowercase using library function islower().
 *
 * @param str Input string.
 * @return true if all characters are lowercase.
 * @return false otherwise.
 *
 * @note Time complexity: O(n)
 * @note Space complexity: O(1)
 */
bool is_lower(const string &str)
{
    for (int i = 0; i < (int)str.size(); ++i)
        if (!islower(str[i]))
            return false;
    return true;
}

int main()
{
    cout << is_lower("abc") << "\n"; // Output: 1
    cout << is_lower("aBC") << "\n"; // Output: 0
    return 0;
}
