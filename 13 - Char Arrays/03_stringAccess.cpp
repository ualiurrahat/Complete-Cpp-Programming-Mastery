/**
 * @file 03_stringAccess.cpp
 * @brief Demonstrates string size and accessing characters using indices.
 */

#include <iostream>
using namespace std;

int main()
{
    string name = "Hany"; // Declare and initialize string

    // Get string length using size() method
    int sz = name.size();
    cout << sz << "\n"; // Output: 4

    // Print full string
    cout << name << "\n";

    // Loop through each character using indices
    for (int i = 0; i < sz; ++i)
        cout << name[i]; // Strings behave like char arrays internally

    return 0;
}
