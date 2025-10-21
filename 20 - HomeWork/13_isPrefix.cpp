/**
 * @file 13_isPrefix.cpp
 * @brief Problem: Check if one string is prefix of another recursively.
 */

#include <iostream>
using namespace std;

/**
 * @brief Recursively check if 'prefix' matches 'main' string up to start_pos
 * @param main The main string
 * @param prefix The prefix string
 * @param start_pos Current index being checked (default 0)
 * @return true if prefix matches, false otherwise
 */
bool is_prefix(string main, string prefix, int start_pos = 0)
{
    if (start_pos == prefix.size()) // Checked all prefix chars
        return true;

    if (main[start_pos] != prefix[start_pos]) // Mismatch
        return false;

    return is_prefix(main, prefix, start_pos + 1);
}

int main()
{
    cout << is_prefix("abcdefg", "abcd", 3) << "\n"; // true (1)
    cout << is_prefix("abcdefg", "", 3) << "\n";     // empty prefix -> true
    cout << is_prefix("abcdefg", "abd", 3) << "\n";  // mismatch -> false (0)

    return 0;
}
