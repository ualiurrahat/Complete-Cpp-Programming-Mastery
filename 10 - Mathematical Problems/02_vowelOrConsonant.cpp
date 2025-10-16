/**
 * @file 02_vowelOrConsonant.cpp
 * @brief Program to check whether a character is a vowel, consonant, or other.
 */

#include <iostream>
using namespace std;

int main()
{
    char ch;

    while (true)
    {
        cout << "Enter character (0 to exit): ";
        cin >> ch;

        if (ch == '0')
        {
            break; // exit condition
        }
        else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            // Check vowels (both upper and lower case)
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {
                cout << "Vowel" << endl;
            }
            else
            {
                cout << "Consonant" << endl;
            }
        }
        else
        {
            cout << "Other characters" << endl;
        }
    }

    return 0;
}
