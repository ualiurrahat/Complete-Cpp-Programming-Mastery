/**
 * @file enum.cpp
 * @brief Demonstrates enums in C++.
 *
 * Enum assigns names to integral constants (by default starting from 0).
 * Improves code readability.
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    // Defining an enumeration
    enum Tomodachi
    {
        Niki,
        Chirag,
        Aryaman
    };

    cout << "Enum Values:" << endl;
    cout << "Niki: " << Niki << endl;       // 0
    cout << "Chirag: " << Chirag << endl;   // 1
    cout << "Aryaman: " << Aryaman << endl; // 2

    // Enum variables
    Tomodachi m1 = Niki, m2 = Chirag, m3 = Aryaman;
    cout << "\nEnum Variables:" << endl;
    cout << "m1: " << m1 << endl;
    cout << "m2: " << m2 << endl;
    cout << "m3: " << m3 << endl;

    return 0;
}
