/**
 * @file 06_VariadicTemplateBasics.cpp
 * @brief Demonstrates basic variadic templates in C++.
 *
 * This file introduces variadic templates, a C++11 feature that allows functions to accept a variable number of arguments of different types.
 *
 * New Topics Introduced:
 * - **Variadic Templates**: Templates that can take any number of arguments using the `typename... Args` syntax.
 * - **Parameter Pack**: A template parameter pack (`typename... Args`) represents zero or more types.
 * - **Function Parameter Pack**: The `args...` in the function parameter list represents the actual arguments passed.
 * - **sizeof...(args)**: Operator to count the number of arguments in a parameter pack.
 * - **__PRETTY_FUNCTION__**: A compiler-specific macro to display the function signature for debugging.
 *
 * The `Hello` function prints the number of arguments and the function signature. It shows how variadic templates can handle different types and numbers of arguments.
 */

#include <iostream>
using namespace std;

/**
 * @brief Prints the number of arguments and function signature using variadic templates.
 * @tparam SomeArgs Parameter pack representing zero or more argument types.
 * @param args Function parameter pack containing the arguments.
 */
template <typename... SomeArgs>
void Hello(SomeArgs... args)
{
    // sizeof...(args) counts the number of arguments in the pack
    int sz = sizeof...(args);
    cout << sz << " " << __PRETTY_FUNCTION__ << "\n";
}

/**
 * @brief Main function to test the variadic template function.
 * @return int Program exit status.
 */
int main()
{
    // Test cases with different numbers and types of arguments
    Hello(1, 2, 3, 4);        // 4 arguments: integers
    Hello("Mostafa", 5, 2.5); // 3 arguments: string, int, double
    Hello('c');               // 1 argument: char
    Hello();                  // 0 arguments
    return 0;
}