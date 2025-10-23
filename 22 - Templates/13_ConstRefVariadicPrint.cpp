/**
 * @file 13_ConstRefVariadicPrint.cpp
 * @brief Demonstrates variadic templates with const references.
 * 
 * This file modifies the variadic print function to use const references for efficiency and safety.
 * 
 * New Topics Introduced:
 * - **Const References in Templates**: Using `const T&` to avoid copying arguments and ensure const-correctness.
 * - **Efficiency**: Passing by reference reduces overhead for large objects like strings.
 * 
 * The `Print` function prints arguments using const references to avoid unnecessary copies.
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
 * @brief Recursively prints arguments using const references.
 * @tparam T Type of the first argument.
 * @tparam Args Parameter pack for remaining arguments.
 * @param a First argument (const reference).
 * @param args Remaining arguments (const references).
 */
template <typename T, typename... Args>
void Print(const T& a, const Args&... args) {
    int sz = sizeof...(args); // Count of remaining arguments
    cout << a;
    if (sz > 0) // Add comma only if more arguments remain
        cout << ", ";
    Print(args...); // Recurse with remaining arguments
}

/**
 * @brief Main function to test variadic printing with const references.
 * @return int Program exit status.
 */
int main() {
    Print(1, 2, 3, 4);             // Outputs: 1, 2, 3, 4
    Print("Mostafa", 'c', 5, 2.5); // Outputs: Mostafa, c, 5, 2.5
    return 0;
}