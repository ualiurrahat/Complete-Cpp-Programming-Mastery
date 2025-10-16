/**
 * @file 06_switchVowelCheck.cpp
 * @brief Program to check whether a character is a vowel using switch-case.
 *
 * Problem Statement:
 * ------------------
 * Write a C++ program that takes a character as input and checks if it is a vowel.
 * - The program should repeatedly ask for input until the user enters '0'.
 * - Both uppercase and lowercase letters should be supported.
 *
 * Example:
 * --------
 * Input:
 *   a
 *   b
 *   O
 *   0
 *
 * Output:
 *   vowel
 *   not vowel
 *   vowel
 *
 */

#include <iostream>
#include <cctype> // for tolower()
using namespace std;

/**
 * @brief Checks whether a given character is a vowel.
 *
 * @param ch Input character.
 * @return true if vowel, false otherwise.
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */
bool isVowel(char ch)
{
    ch = tolower(ch); // convert to lowercase for uniformity
    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

int main()
{
    char ch;

    while (true)
    {
        cout << "Enter a character (0 to exit): ";
        cin >> ch;

        if (ch == '0')
        {
            break;
        }

        if (isVowel(ch))
        {
            cout << "vowel" << endl;
        }
        else
        {
            cout << "not vowel" << endl;
        }
    }

    return 0;
}
