/**
 * @file 06_functionTypes.cpp
 * @brief Demonstrate multiple types of functions in C++.
 *
 * @question
 * Show examples of:
 * - Function returning a value
 * - Function returning nothing (void)
 * - Functions without parameters
 */

#include <iostream>
using namespace std;

// Function that returns an integer
int lucky_number()
{
    return 13;
}

// Example function that returns nothing
void print_sum(int a, int b)
{
    cout << a + b << "\n";
}

int main()
{
    // lucky_number returns 13
    cout << lucky_number() << "\n";

    // print_sum prints result directly (no return)
    print_sum(2, -5);

    return 0;
}
