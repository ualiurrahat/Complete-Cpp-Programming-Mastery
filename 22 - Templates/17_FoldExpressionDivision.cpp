/**
 * @file 17_FoldExpressionDivision.cpp
 * @brief Demonstrates fold expressions for division in variadic templates.
 * 
 * This file explores fold expressions with the division operator, highlighting differences between left and right folds.
 * 
 * New Topics Introduced:
 * - **Fold Expressions with Division**: Division is non-associative, so left and right folds produce different results.
 * - **Integer vs. Floating-Point Division**: Integer division truncates, while floating-point division preserves precision.
 * - **Potential Runtime Errors**: Right folds with division can cause division by zero in certain cases.
 * 
 * The code defines division functions using left and right fold expressions and tests them with integer and floating-point inputs.
 */

#include <iostream>
using namespace std;

/**
 * @brief Divides arguments using a right fold.
 * @param args Parameter pack of arguments.
 * @return Result of right-fold division.
 */
auto div_right(auto... args) {
    return (args / ...); // Right fold: arg0 / (arg1 / (arg2 / ...))
}

/**
 * @brief Divides arguments using a left fold.
 * @param args Parameter pack of arguments.
 * @return Result of left-fold division.
 */
auto div_left(auto... args) {
    return (... / args); // Left fold: ((arg0 / arg1) / arg2) / ...
}

/**
 * @brief Main function to test fold expression division.
 * @return int Program exit status.
 */
int main() {
    cout << div_left(1.0, 2.0, 3.0, 4.0) << "\n";  // Outputs 0.0416667 (((1/2)/3)/4)
    cout << div_right(1.0, 2.0, 3.0, 4.0) << "\n"; // Outputs 0.375 (1/(2/(3/4)))
    cout << div_left(1, 2, 3, 4) << "\n";          // Outputs 0 (integer division)
    // cout << div_right(1, 2, 3, 4);              // Runtime error: division by zero
    return 0;
}