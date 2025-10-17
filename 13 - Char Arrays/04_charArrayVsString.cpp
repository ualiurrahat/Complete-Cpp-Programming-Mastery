/**
 * @file 04_charArrayVsString.cpp
 * @brief Demonstrates difference between character arrays and string objects.
 */

#include <iostream>
using namespace std;

int main()
{
    // Integer array for comparison
    int numbers[5] = {1, 2, 3, 4, 5};

    // Character arrays
    char name1[5] = {'H', 'a', 'n', 'i'}; // Missing null terminator ('\0')
    char name2[5] = "Hani";               // Automatically adds '\0'

    // Using C++ string class (handles size, null, etc. automatically)
    string name3 = "Hani";

    cout << name1 << "\n"; // May print garbage (no '\0')
    cout << name2 << "\n"; // Safe output
    cout << name3 << "\n"; // Preferred modern way

    return 0;
}
