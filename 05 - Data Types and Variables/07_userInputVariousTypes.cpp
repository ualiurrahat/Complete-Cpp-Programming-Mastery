/**
 * @file 03_userInputVariousTypes.cpp
 * @brief Reads multiple types of user input: int, double, char, string.
 *
 * @details
 * - Demonstrates using `cin` for various types: int, double, char, string.
 * - Shows how to output all the information using `cout`.
 * - Note: `cin >>` reads input until whitespace for string.
 */

#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "Enter age: ";
    cin >> age;

    double weight;
    cout << "Enter weight: ";
    cin >> weight;

    char group;
    cout << "Enter group: ";
    cin >> group;

    string name;
    cout << "Enter name: ";
    cin >> name;

    // Display user information
    cout << "I am " << name << " belongs to group " << group << "\n";
    cout << "My weight " << weight << " and age " << age;

    return 0;
}
