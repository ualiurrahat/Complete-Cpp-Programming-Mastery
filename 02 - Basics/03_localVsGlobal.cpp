/**
 * @file 03_localVsGlobal.cpp
 * @brief Demonstrates difference between local and global variables.
 *
 * - Global variables: Declared outside functions, accessible everywhere.
 * - Local variables: Declared inside functions, override globals in scope.
 */

#include <iostream>
using namespace std;

int glo = 89; // Global variable

void print()
{
    cout << glo << "\n"; // Uses global variable
}

int main()
{
    int glo = 7;         // Local variable shadows global variable
    cout << glo << "\n"; // Prints local value
    print();             // Prints global value
    return 0;
}
