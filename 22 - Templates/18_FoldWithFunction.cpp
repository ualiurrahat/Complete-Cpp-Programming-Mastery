/**
 * @file 18_FoldWithFunction.cpp
 * @brief Demonstrates fold expressions with a custom function.
 * 
 * This file shows how to use fold expressions with a user-defined function applied to each argument.
 * 
 * New Topics Introduced:
 * - **Fold Expressions with Functions**: Applying a function to each argument in a fold expression before combining results.
 * - **Function Parameters in Variadic Templates**: Passing a function as a template parameter to customize behavior.
 * 
 * The `sum_square` function applies a squaring function to each argument and sums the results using a fold expression.
 */

#include <iostream>
using namespace std;

/**
 * @brief Squares an integer.
 * @param x Input integer.
 * @return int Square of the input.
 */
int sq(int x) {
    return x * x;
}

/**
 * @brief Sums the results of applying a function to each argument using a binary right fold.
 * @tparam Function Type of the function to apply.
 * @param operation The function to apply to each argument.
 * @param args Parameter pack of arguments.
 * @return Sum of the function applied to each argument.
 */
template <typename Function>
auto sum_square(Function operation, auto... args) {
    return (operation(args) + ... + 0); // Apply function and sum results
}

/**
 * @brief Main function to test fold expression with a custom function.
 * @return int Program exit status.
 */
int main() {
    int val = sum_square(sq, 1, 2, 3, 4); // Outputs 30 (1^2 + 2^2 + 3^2 + 4^2 = 1 + 4 + 9 + 16)
    cout << val << "\n";
    return 0;
}