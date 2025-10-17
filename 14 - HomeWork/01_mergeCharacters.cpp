/**
 * @file 01_mergeCharacters.cpp
 * @brief Merge two strings character by character alternately.
 *
 * @question
 * Given two strings `first` and `second`, merge them by alternating their characters.
 * If one string is longer, continue printing the remaining characters from that string.
 *
 * Example:
 * Input:
 * abc xy
 * Output:
 * axbyc
 */

#include <iostream>
using namespace std;

int main()
{
    string first, second;
    cin >> first >> second;

    // Find the maximum size between the two strings
    int maxSize = first.size();
    if (maxSize < second.size())
        maxSize = second.size();

    // Merge the two strings character by character
    for (int index = 0; index < maxSize; ++index)
    {
        if (index < first.size())
            cout << first[index];

        if (index < second.size())
            cout << second[index];
    }

    cout << "\n";
    return 0;
}

/**
 * @example
 * Input:
 * Rahat Ualiur
 *
 * Output:
 * RUaaahlaiutr
 */
