/**
 * @file 11_ReturnByValue.cpp
 * @brief Demonstrates return-by-value and lifetime of local variables.
 *
 * Problem Statement:
 * Show that local variables are destroyed after function ends.
 * Returned value is copied to caller.
 *
 * New Topics Introduced:
 * - **Stack vs Heap**
 * - **Local variable lifetime**: Ends when function returns.
 * - **Copy on return**
 *
 * @warning Never return reference to local variable!
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

int get_number() {
    int x = 20;
    cout << &x << "\n";  // Address in function
    return x;            // x destroyed after return
}

int main() {
    int y = get_number();
    cout << &y << "\n";  // Different address
    return 0;
}