/**
 * @problem_statement
 * Write a program to demonstrate the difference between pass-by-value and pass-by-reference in C++.
 *
 * The program should include:
 * 1. A function that modifies one argument by value and another by reference.
 * 2. A function that reads values into variables using both normal and reference parameters.
 */

#include <iostream>
using namespace std;

/**
 * @brief Increments one variable by value and another by reference.
 *
 * @param a (int) Passed by value — changes inside the function will NOT affect the original variable.
 * @param b (int&) Passed by reference — changes inside the function WILL affect the original variable.
 *
 * @note Time complexity: O(1)
 * @note Space complexity: O(1)
 */
void change(int a, int &b)
{
    a++; // This increment affects only the local copy.
    b++; // This increment affects the original variable since 'b' is passed by reference.
}

/**
 * @brief Reads values into parameters using references and value passing.
 *
 * @param x (int) Passed by value — user input won't update the original variable.
 * @param y (int&) Passed by reference — user input WILL update the original variable.
 * @param str (string&) Passed by reference — user input WILL be stored in the original string.
 *
 * @note Time complexity: O(1)
 * @note Space complexity: O(1)
 */
void read(int x, int &y, string &str)
{
    cin >> x >> y >> str; // Only y and str will store new values to their original variables.
}

int main()
{
    int a = 1, b = 1;

    // Function call: 'a' passed by value, 'b' passed by reference.
    change(a, b);

    // 'a' remains unchanged, 'b' increments by 1.
    cout << a << " " << b << "\n"; // Output: 1 2

    string name;

    // 'a' will not update since it's passed by value. 'b' and 'name' will change.
    read(a, b, name);

    cout << a << " " << b << " " << name << "\n";
    return 0;
}
