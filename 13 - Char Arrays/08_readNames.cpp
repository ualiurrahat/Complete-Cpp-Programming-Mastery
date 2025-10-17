/**
 * @file 08_readNames.cpp
 * @brief Demonstrates reading full lines and character arrays using getline in C++.
 *
 * Problem Statement:
 * Read two names from input: one using `getline` for string and another using `cin.getline`
 * for a character array, then print them both.
 */

#include <iostream>
using namespace std;

int main()
{
    string name1;
    getline(cin, name1); // Reads a full line including spaces into 'name1'
    cout << name1 << "\n";

    char name2[50];
    cin.getline(name2, 50); // Reads up to 49 characters (stops at newline)
    cout << name2 << "\n";

    return 0;
}

/**
 * @example
 * Input:
 * Mostafa Saad
 * Hello World
 *
 * Output:
 * Mostafa Saad
 * Hello World
 */
