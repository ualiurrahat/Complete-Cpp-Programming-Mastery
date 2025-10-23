/**
 * @file 12_VariadicPrint.cpp
 * @brief Demonstrates recursive variadic templates for printing arguments.
 * 
 * This file shows how to use variadic templates to print arguments of different types with comma separation.
 * 
 * New Topics Introduced:
 * - **Pretty Printing with Variadic Templates**: Using recursion to format output with commas, avoiding an extra comma at the end.
 * - **Conditional Output**: Using `sizeof...(args)` to control formatting based on the number of remaining arguments.
 * 
 * The `Print` function recursively prints arguments, adding commas between them and a newline at the end.
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
 * @brief Recursively prints arguments with comma separation.
 * @tparam T Type of the first argument.
 * @tparam Args Parameter pack for remaining arguments.
 * @param a First argument to print.
 * @param args Remaining arguments.
 */
template <typename T, typename... Args>
void Print(T a, Args... args) {
    int sz = sizeof...(args); // Count of remaining arguments
    cout << a;
    if (sz > 0) // Add comma only if more arguments remain
        cout << ", ";
    Print(args...); // Recurse with remaining arguments
}

/**
 * @brief Main function to test variadic printing.
 * @return int Program exit status.
 */
int main() {
    Print(1, 2, 3, 4);             // Outputs: 1, 2, 3, 4
    Print("Mostafa", 'c', 5, 2.5); // Outputs: Mostafa, c, 5, 2.5
    return 0;
}