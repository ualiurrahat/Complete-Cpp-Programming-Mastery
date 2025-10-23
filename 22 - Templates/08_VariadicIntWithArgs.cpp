/**
 * @file 08_VariadicIntWithArgs.cpp
 * @brief Demonstrates variadic templates with a single fixed integer parameter.
 * 
 * This file shows how variadic templates can be used with a single fixed parameter, focusing on the integer type.
 * 
 * New Topics Introduced:
 * - **Single Fixed Parameter with Variadic Pack**: A variadic template can have just one fixed parameter, with the parameter pack capturing all subsequent arguments.
 * - **Iterating Parameter Packs**: The code hints at using recursion to process parameter packs (though not implemented here).
 * 
 * The `Hello` function takes an integer and a variadic parameter pack, printing the integer and the count of additional arguments.
 */

#include <iostream>
using namespace std;

/**
 * @brief Prints a fixed integer and the count of variadic arguments.
 * @tparam Args Parameter pack for additional arguments.
 * @param a Fixed integer parameter.
 * @param args Variadic parameter pack.
 */
template <typename... Args>
void Hello(int a, Args... args) {
    int sz = sizeof...(args); // Count of variadic arguments
    cout << a << " " << sz << "\n";
}

/**
 * @brief Main function to test variadic templates with a fixed integer.
 * @return int Program exit status.
 */
int main() {
    Hello(1, 2, 3, 4, 5); // args = {2, 3, 4, 5}
    Hello(2, 3, 4, 5);    // args = {3, 4, 5}
    Hello(3, 4, 5);       // args = {4, 5}
    return 0;
}