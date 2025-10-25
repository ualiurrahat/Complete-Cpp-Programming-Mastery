/**
 * @file 19_CinGetlineProblem.cpp
 * @brief Demonstrates the classic `cin >>` + `getline()` bug due to leftover newline.
 *
 * Problem:
 * - `cin >> age` reads the number, but **leaves the newline (`\n`)** in the input buffer.
 * - `getline()` reads **up to the next `\n`** → it sees the leftover `\n` and reads an **empty line**.
 *
 * Result: `full_name` becomes empty → **bug**.
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int age;
    cout << "Enter your age: ";
    cin >> age; // Reads "25", leaves "\n" in buffer

    string full_name;
    cout << "Enter full name: ";
    getline(cin, full_name); // Reads from current position to "\n" → empty string!

    // Output shows the bug
    cout << "Your age: " << age << "\n";
    cout << "Your name: '" << full_name << "' (length: " << full_name.length() << ")\n";

    cout << "\nBug: Name is empty because getline() consumed the leftover newline!\n";

    return 0;
}