/**
 * @file 23_WhitespaceSkippingWithSkipws.cpp
 * @brief Demonstrates `skipws` (default) vs `noskipws` in stream extraction.
 *
 * - `skipws` (default): skips all whitespace (space, tab, newline) before reading
 * - `noskipws`: reads **every character**, including whitespace
 *
 * Use `noskipws` when you need to preserve layout (e.g., parsing formatted files)
 */

#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    // Input string with leading spaces
    istringstream iss("  123");

    char a, b, c;

    // Default: skipws → skips spaces
    iss >> skipws >> a >> b >> c;
    cout << "With skipws: '" << a << b << c << "'\n"; // 123

    // Reset stream
    iss.clear();
    iss.seekg(0);

    // noskipws: reads spaces too
    iss >> noskipws >> a >> b >> c;
    cout << "With noskipws: ";
    cout << "'" << a << "'" // space
         << "'" << b << "'" // space
         << "'" << c << "'" // '1'
         << "\n";

    cout << "noskipws reads raw characters — useful for exact parsing.\n";

    return 0;
}