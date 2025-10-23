/**
 * @file 07_VariadicWithFixedParams.cpp
 * @brief Demonstrates variadic templates with fixed parameters.
 * 
 * This file builds on variadic templates by combining them with fixed parameters (int and string) before the parameter pack.
 * 
 * New Topics Introduced:
 * - **Mixing Fixed and Variadic Parameters**: Variadic templates can be used with fixed parameters, where the fixed parameters are processed first, and the parameter pack handles the remaining arguments.
 * - **Parameter Pack Positioning**: The parameter pack (`Args... args`) is typically placed at the end of the parameter list to capture all remaining arguments.
 * 
 * The `Hello` function takes a fixed `int` and `string`, followed by a variadic parameter pack, and prints the fixed parameters along with the count of variadic arguments.
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Prints fixed parameters and the count of variadic arguments.
 * @tparam Args Parameter pack for additional arguments.
 * @param a Fixed integer parameter.
 * @param name Fixed string parameter.
 * @param args Variadic parameter pack.
 */
template <typename... Args>
void Hello(int a, string name, Args... args) {
    int sz = sizeof...(args); // Count of variadic arguments
    cout << a << " " << name << " " << sz << "\n";
}

/**
 * @brief Main function to test variadic templates with fixed parameters.
 * @return int Program exit status.
 */
int main() {
    Hello(1, "belal");            // No variadic arguments
    Hello(1, "belal", 2.5);       // 1 variadic argument
    Hello(1, "belal", 2.5, "Me"); // 2 variadic arguments
    return 0;
}