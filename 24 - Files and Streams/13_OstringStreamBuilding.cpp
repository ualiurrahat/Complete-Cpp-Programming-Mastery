/**
 * @file 13_OstringStreamBuilding.cpp
 * @brief Demonstrates building a string using ostringstream.
 *
 * This file introduces `ostringstream` for constructing strings from mixed data types.
 *
 * New Topics Introduced:
 * - **ostringstream Class**: Syntax: `ostringstream oss`. Builds a string by writing data with `<<`. Retrieve the result with `oss.str()`.
 * - **str() Function**: Syntax: `string str()`. Returns the constructed string from the `ostringstream`.
 * - **Use Case**: Useful for formatting output (e.g., logs, reports) before printing or storing.
 *
 * The program builds a string with a name, age, and text, then outputs it.
 */

#include <iostream>
#include <sstream>
using namespace std;

/**
 * @brief Main function to demonstrate building a string with ostringstream.
 * @note Time Complexity: O(n) where n is the length of the constructed string.
 * @note Space Complexity: O(n) for storing the string.
 * @return int Program exit status.
 */
int main() {
    ostringstream oss; // Create output string stream

    oss << "Mostafa "; // Add name
    oss << 50;         // Add age
    oss << " years old\n"; // Add text

    cout << oss.str(); // Output the constructed string
    return 0;
}