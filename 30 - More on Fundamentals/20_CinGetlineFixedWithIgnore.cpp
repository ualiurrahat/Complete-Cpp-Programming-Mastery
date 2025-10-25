/**
 * @file 20_CinGetlineFixedWithIgnore.cpp
 * @brief Correct way to mix `cin >>` and `getline()` using `cin.ignore()`.
 *
 * Solution:
 * - After `cin >> var`, call `cin.ignore(numeric_limits<streamsize>::max(), '\n')`
 * - This **discards everything** up to and including the next newline.
 * - Safe and standard practice.
 */

#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    int age;
    cout << "Enter your age: ";
    cin >> age;

    // Clear the input buffer up to newline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string full_name;
    cout << "Enter full name: ";
    getline(cin, full_name); // Now works correctly!

    cout << "Your age: " << age << "\n";
    cout << "Your name: '" << full_name << "'\n";

    cout << "Fixed using cin.ignore()!\n";

    return 0;
}