/**
 * @file 01_unreachableAfterReturn.cpp
 * @brief Demonstrates that code after `return` in main() is unreachable.
 *
 * @details
 * This file shows a common beginner mistake: placing code after `return 0;`.
 * Anything after `return` in the same function will never execute.
 *
 * Problem statement:
 * - Print "I am Rahat" and then demonstrate that subsequent cout statements
 *   placed after a `return` won't execute.
 *
 * Example expected output:
 * I am Rahat
 *
 * @note Time complexity: O(1)
 * @note Space complexity: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    // This will be printed
    cout << "I am Rahat" << endl;

    // Program returns here and ends execution of main.
    // Any code placed after this 'return' is unreachable.
    return 0;

    // UNREACHABLE CODE (will never execute) - common beginner error.
    // The compiler won't run these statements because main() already returned.
    cout << endl;
    cout << "I was born in Gazipur\n";
    cout << "I graduated from Gopalganj Science and Technology University";
    cout << endl;
}
