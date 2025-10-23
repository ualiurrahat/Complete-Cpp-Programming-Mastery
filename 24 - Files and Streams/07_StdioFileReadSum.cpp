/**
 * @file 07_StdioFileReadSum.cpp
 * @brief Demonstrates reading integers from a file using freopen and computing their sum.
 *
 * This file builds on `freopen` by reading two integers from a file and outputting their sum to `stdout`.
 *
 * New Topics Introduced:
 * - **Reading with cin after freopen**: After redirecting `stdin` to a file, `cin` reads from the file instead of the keyboard.
 * - **Use Case**: Simplifies reading input from files in competitive programming scenarios where input is provided in a file.
 *
 * The program redirects `stdin` to "read_file.txt", reads two integers, and prints their sum to `stdout` (which could also be redirected).
 */

#include <iostream>
using namespace std;

/**
 * @brief Main function to read integers from a file and compute their sum.
 * @note Time Complexity: O(1) for reading two integers and computing their sum.
 * @note Space Complexity: O(1) for fixed-size variables.
 * @return int Program exit status.
 */
int main() {
    // Redirect standard input to read from a file
    freopen("read_file.txt", "rt", stdin);

    int x, y;
    cin >> x >> y; // Read two integers from the file
    cout << x + y; // Output their sum

    return 0;
}