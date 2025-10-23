/**
 * @file 19_LogicalFoldExpressions.cpp
 * @brief Demonstrates fold expressions for logical operations and recursive variadic templates.
 * 
 * This file uses fold expressions and recursion to perform logical AND and OR operations on variadic arguments.
 * 
 * New Topics Introduced:
 * - **Logical Fold Expressions**: Using `&&` and `||` in fold expressions to compute logical results.
 * - **Recursive Variadic for Logical Operations**: Comparing recursion-based and fold-based implementations for logical operations.
 * - **Default Values for Empty Packs**: Logical folds need defaults (`true` for AND, `false` for OR) for empty argument lists.
 * 
 * The code implements `all` (AND) and `any` (OR) using fold expressions and `allVar` using recursion.
 */

#include <iostream>
using namespace std;

/**
 * @brief Base case for recursive variadic logical AND.
 * @return bool True for empty argument list.
 */
bool allVar() {
    return true;
}

/**
 * @brief Recursively computes logical AND of arguments.
 * @tparam T Type of the first argument.
 * @param t First argument.
 * @param args Remaining arguments.
 * @return bool Logical AND of all arguments.
 */
template <typename T>
bool allVar(T t, auto... args) {
    return t && allVar(args...); // Logical AND with recursion
}

/**
 * @brief Computes logical AND using a fold expression.
 * @param args Parameter pack of arguments.
 * @return bool Logical AND of all arguments (true for empty pack).
 */
bool all(auto... args) {
    return (... && args); // Unary left fold for AND
}

/**
 * @brief Computes logical OR using a fold expression.
 * @param args Parameter pack of arguments.
 * @return bool Logical OR of all arguments (false for empty pack).
 */
bool any(auto... args) {
    return (... || args); // Unary left fold for OR
}

/**
 * @brief Main function to test logical operations.
 * @return int Program exit status.
 */
int main() {
    cout << all(1, 1, 1) << "\n"; // Outputs 1 (true)
    cout << all(1, 0, 1) << "\n"; // Outputs 0 (false)
    cout << all() << "\n";        // Outputs 1 (true, empty pack)
    cout << any() << "\n";        // Outputs 0 (false, empty pack)
    return 0;
}