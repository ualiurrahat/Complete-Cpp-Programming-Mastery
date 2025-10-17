/**
 * @file 02_characterFrequency.cpp
 * @brief Count frequency of lowercase letters in a given string.
 *
 * @question
 * Given a string containing lowercase English letters, count how many times
 * each character appears and print them in alphabetical order.
 *
 * Example:
 * Input:
 * aabccc
 * Output:
 * a 2
 * b 1
 * c 3
 */

#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int frequency[150] = {0}; // Initialize all elements to zero

    // Count frequency of each character
    for (int index = 0; index < str.size(); ++index)
        frequency[str[index]]++;

    // Print frequency of each lowercase character
    for (int ch = 'a'; ch <= 'z'; ++ch)
    {
        if (frequency[ch])
            cout << (char)ch << " " << frequency[ch] << "\n";
    }

    return 0;
}

/**
 * @example
 * Input:
 * banana
 *
 * Output:
 * a 3
 * b 1
 * n 2
 */
