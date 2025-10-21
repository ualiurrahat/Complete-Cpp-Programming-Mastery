/**
 * @file 08_functionTypeConversion.cpp
 * @brief Demonstrate type conversion in function calls.
 *
 * @question
 * Show how implicit type conversion can occur when passing arguments to a function.
 */

#include <iostream>
#include <cstdlib>
using namespace std;

/**
 * @brief Add two integers
 * @param a first integer
 * @param b second integer
 * @return int sum of two integers
 */
int add(int a, int b)
{
    return a + b;
}

int main()
{
    cout << add(2, 3) << "\n";   // Exact match (int, int)
    cout << add(2, 3.5) << "\n"; // 3.5 is implicitly converted to 3 (int)

    // So output: 5 and 5
    return 0;
}
