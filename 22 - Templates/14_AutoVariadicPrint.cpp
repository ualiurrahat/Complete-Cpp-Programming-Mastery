/**
 * @file 14_AutoVariadicPrint.cpp
 * @brief Demonstrates variadic templates with auto for parameter packs.
 * 
 * This file uses C++20's `auto` keyword in variadic templates for simpler syntax.
 * 
 * New Topics Introduced:
 * - **C++20 Auto in Parameter Packs**: Using `auto` instead of `typename T` for the first argument and `auto&...` for the parameter pack.
 * - **Simplified Template Syntax**: `auto` reduces boilerplate while maintaining type safety.
 * 
 * The `Print` function uses `auto` to handle the first argument and parameter pack, maintaining the same printing functionality.
 */

#include <iostream>
using namespace std;

/**
 * @brief Base case for variadic print.
 */
void Print() {
    cout << "\n";
}

/**
 * @brief Recursively prints arguments using auto for type deduction.
 * @param a First argument (type deduced by auto).
 * @param args Remaining arguments (type deduced by auto).
 */
template <typename T>
void Print(const T& a, const auto&... args) {
    int sz = sizeof...(args); // Count of remaining arguments
    cout << a;
    if (sz > 0) // Add comma only if more arguments remain
        cout << ", ";
    Print(args...); // Recurse with remaining arguments
}

/**
 * @brief Main function to test variadic printing with auto.
 * @return int Program exit status.
 */
int main() {
    Print(1, 2, 3, 4);             // Outputs: 1, 2, 3, 4
    Print("Mostafa", 'c', 5, 2.5); // Outputs: Mostafa, c, 5, 2.5
    return 0;
}