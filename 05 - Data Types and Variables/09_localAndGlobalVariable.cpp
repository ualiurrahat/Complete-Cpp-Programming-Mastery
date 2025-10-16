/**
 * @file 09_localAndGlobalVariable.cpp
 * @brief Demonstrates the difference between local and global variables in C++.
 *
 * Problem Statement:
 * ------------------
 * Write a program to illustrate how local variables and global variables work,
 * and how local variables can shadow (override) global ones within a specific scope.
 *
 * Key Concepts:
 * -------------
 * 1. **Global Variables:**
 *    - Declared **outside any function** (usually at the top of the file).
 *    - Accessible **from all functions** in the same file (and even other files using extern).
 *    - Have a **global scope** and **lifetime throughout the program execution**.
 *    - Default initialized to zero if not explicitly assigned.
 *
 * 2. **Local Variables:**
 *    - Declared **inside a function or block** (like inside main or a loop).
 *    - Exist only **within that specific scope** (destroyed once the function ends).
 *    - They **override global variables with the same name** (this is called shadowing).
 *
 * 3. **Variable Shadowing:**
 *    - When a local variable has the same name as a global variable,
 *      the local one takes precedence **within that function’s scope**.
 *    - To access the global variable in that case, use the **scope resolution operator (::)**.
 */

#include <iostream>
using namespace std;

// ---------------------- Global Variable ----------------------
int glo = 89; ///< Global variable: accessible across all functions

/**
 * @brief Prints the global variable.
 *
 * Demonstrates how functions can access and use global variables directly.
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */
void print()
{
    cout << "Global variable inside print(): " << glo << "\n";
}

/**
 * @brief Main function demonstrating local vs global variable behavior.
 *
 * @return int Returns 0 upon successful execution.
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */
int main()
{
    // ---------------------- Local Variable ----------------------
    int glo = 7; ///< Local variable shadows the global one inside main()

    cout << "Local variable inside main(): " << glo << "\n"; // Prints local value

    // Function call prints the global variable (since no local 'glo' inside print)
    print();

    // ---------------------- Accessing Global Variable Explicitly ----------------------
    cout << "Accessing global variable explicitly: " << ::glo << "\n";
    // The scope resolution operator (::) forces access to the global 'glo'
    // even though a local variable with the same name exists.

    return 0;
}

/**
 * Expected Output:
 * ----------------
 * Local variable inside main(): 7
 * Global variable inside print(): 89
 * Accessing global variable explicitly: 89
 */
