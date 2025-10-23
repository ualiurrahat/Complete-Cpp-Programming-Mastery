/**
 * @file 10_VariadicSumRecursion.cpp
 * @brief Demonstrates recursive summation using variadic templates.
 * 
 * This file applies recursion to variadic templates to sum integers, mimicking the array summation from the previous file.
 * 
 * New Topics Introduced:
 * - **Recursive Variadic Templates**: Using recursion to process a parameter pack by handling one argument at a time.
 * - **Base Case for Variadic Templates**: A non-template overload (or template specialization) to terminate recursion.
 * - **Right Fold Expansion**: The recursive calls process arguments from left to right, equivalent to a right fold.
 * 
 * The `Sum` function recursively adds integers, with a base case for no arguments.
 */

#include <iostream>
using namespace std;

/**
 * @brief Base case for variadic sum recursion.
 * @return int Returns 0 when no arguments are provided.
 */
int Sum() {
    return 0;
}

/**
 * @brief Recursively sums integers using variadic templates.
 * @tparam Args Parameter pack for remaining arguments.
 * @param a First integer to add.
 * @param args Remaining arguments.
 * @return int Sum of all arguments.
 */
template <typename... Args>
int Sum(int a, Args... args) {
    return a + Sum(args...); // Add first argument and recurse
}

/**
 * @brief Main function to test variadic sum recursion.
 * @return int Program exit status.
 */
int main() {
    cout << Sum(1, 2, 3, 4); // Outputs 10 (1 + 2 + 3 + 4)
    // Recursion steps: 1 + Sum(2, 3, 4) -> 1 + 2 + Sum(3, 4) -> 1 + 2 + 3 + Sum(4) -> 1 + 2 + 3 + 4 + Sum()
    return 0;
}