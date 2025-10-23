/**
 * @file 15_FoldExpressionSum.cpp
 * @brief Demonstrates fold expressions for summation in variadic templates.
 * 
 * This file introduces C++17 fold expressions to simplify variadic template processing.
 * 
 * New Topics Introduced:
 * - **Fold Expressions**: A C++17 feature to apply an operator (e.g., `+`) to a parameter pack without explicit recursion.
 * - **Unary vs. Binary Folds**: Unary folds (`args + ...`) require at least one argument; binary folds (`args + ... + 0`) handle empty packs.
 * - **Left vs. Right Folds**: Left folds (`... + args`) process from left to right; right folds (`args + ...`) process from right to left.
 * 
 * The code defines four summation functions using unary and binary, left and right fold expressions.
 */

#include <iostream>
using namespace std;

/**
 * @brief Sums arguments using a unary right fold.
 * @tparam Args Parameter pack of arguments.
 * @return Sum of arguments (requires at least one argument).
 */
template <typename... Args>
auto sum_unary_right_fold(Args... args) {
    return (args + ...); // Right fold: arg0 + (arg1 + (arg2 + ...))
}

/**
 * @brief Sums arguments using a binary right fold.
 * @tparam Args Parameter pack of arguments.
 * @return Sum of arguments (handles empty pack).
 */
template <typename... Args>
auto sum_binary_right_fold(Args... args) {
    return (args + ... + 0); // Right fold: arg0 + (arg1 + (arg2 + 0))
}

/**
 * @brief Sums arguments using a unary left fold.
 * @tparam Args Parameter pack of arguments.
 * @return Sum of arguments (requires at least one argument).
 */
template <typename... Args>
auto sum_unary_left_fold(Args... args) {
    return (... + args); // Left fold: ((arg0 + arg1) + arg2) + ...
}

/**
 * @brief Sums arguments using a binary left fold.
 * @tparam Args Parameter pack of arguments.
 * @return Sum of arguments (handles empty pack).
 */
template <typename... Args>
auto sum_binary_left_fold(Args... args) {
    return (0 + ... + args); // Left fold: ((0 + arg0) + arg1) + ...
}

/**
 * @brief Main function to test fold expression summation.
 * @return int Program exit status.
 */
int main() {
    cout << sum_unary_right_fold(1, 2, 3, 4) << "\n"; // Outputs 10
    cout << sum_binary_right_fold() << "\n";           // Outputs 0
    cout << sum_unary_left_fold(1, 2, 3, 4) << "\n";  // Outputs 10
    cout << sum_binary_left_fold() << "\n";            // Outputs 0
    return 0;
}