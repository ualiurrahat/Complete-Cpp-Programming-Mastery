/**
 * @file 11_GenericVariadicSum.cpp
 * @brief Demonstrates generic variadic templates for summation.
 * 
 * This file extends variadic summation to handle different numeric types by introducing a template type parameter `T`.
 * 
 * New Topics Introduced:
 * - **Generic Type Parameter**: Using `typename T` to specify the type of the first argument and ensure consistent return type.
 * - **Type Deduction Issues**: Shows how mixed types (e.g., int and double) may lead to truncation unless explicitly specified.
 * 
 * The `Sum` function adds numbers of type `T`, with explicit type specification needed for accurate floating-point results.
 */

#include <iostream>
using namespace std;

/**
 * @brief Base case for generic variadic sum.
 * @tparam T The type of the sum (e.g., int, double).
 * @return T Returns 0 of type T.
 */
template <typename T>
T Sum() {
    return 0;
}

/**
 * @brief Recursively sums arguments of type T.
 * @tparam T The type of the sum and first argument.
 * @tparam Args Parameter pack for remaining arguments.
 * @param a First argument of type T.
 * @param args Remaining arguments.
 * @return T Sum of all arguments.
 */
template <typename T, typename... Args>
T Sum(T a, Args... args) {
    return a + Sum<T>(args...); // Add first argument and recurse with type T
}

/**
 * @brief Main function to test generic variadic sum.
 * @return int Program exit status.
 */
int main() {
    cout << Sum<int>(1, 2, 3, 4) << "\n";           // Outputs 10 (int)
    cout << Sum<double>(1.2, 2.3, 3.1, 4) << "\n";  // Outputs 10.6 (double)
    cout << Sum<int>(1, 2.3, 3.1, 4.2) << "\n";     // Outputs 10 (truncates to int)
    cout << Sum<double>(1, 2.3, 3.1, 4.2) << "\n";  // Outputs 10.6 (double)
    return 0;
}