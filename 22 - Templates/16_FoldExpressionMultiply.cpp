/**
 * @file 16_FoldExpressionMultiply.cpp
 * @brief Demonstrates fold expressions for multiplication in variadic templates.
 * 
 * This file applies fold expressions to multiplication, showing how they work with a different operator.
 * 
 * New Topics Introduced:
 * - **Fold Expressions with Multiplication**: Using `*` in fold expressions to multiply arguments.
 * - **Operator-Specific Behavior**: Multiplication fold expressions behave similarly to addition but compute products.
 * 
 * The code defines four multiplication functions using unary and binary, left and right fold expressions.
 */

#include <iostream>
using namespace std;

/**
 * @brief Multiplies arguments using a unary right fold.
 * @tparam Args Parameter pack of arguments.
 * @return Product of arguments (requires at least one argument).
 */
template <typename... Args>
auto multiply_unary_right_fold(Args... args) {
    return (args * ...); // Right fold: arg0 * (arg1 * (arg2 * ...))
}

/**
 * @brief Multiplies arguments using a binary right fold.
 * @tparam Args Parameter pack of arguments.
 * @return Product of arguments (handles empty pack).
 */
template <typename... Args>
auto multiply_binary_right_fold(Args... args) {
    return (args * ... * 1); // Right fold: arg0 * (arg1 * (arg2 * 1))
}

/**
 * @brief Multiplies arguments using a unary left fold.
 * @tparam Args Parameter pack of arguments.
 * @return Product of arguments (requires at least one argument).
 */
template <typename... Args>
auto multiply_unary_left_fold(Args... args) {
    return (... * args); // Left fold: ((arg0 * arg1) * arg2) * ...
}

/**
 * @brief Multiplies arguments using a binary left fold.
 * @tparam Args Parameter pack of arguments.
 * @return Product of arguments (handles empty pack).
 */
template <typename... Args>
auto multiply_binary_left_fold(Args... args) {
    return (1 * ... * args); // Left fold: ((1 * arg0) * arg1) * ...
}

/**
 * @brief Main function to test fold expression multiplication.
 * @return int Program exit status.
 */
int main() {
    cout << multiply_unary_left_fold(1, 2, 3, 4) << "\n"; // Outputs 24
    return 0;
}