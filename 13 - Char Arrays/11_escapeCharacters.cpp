/**
 * @file 11_escapeCharacters.cpp
 * @brief Demonstrates usage of escape characters in C++ strings.
 *
 * Problem Statement:
 * Print messages using escape sequences like tab (`\t`), newline (`\n`),
 * and double quotes (`\"`).
 */

#include <iostream>
using namespace std;

int main()
{
    // Escape characters are special sequences starting with '\'
    cout << "hello\tworld\n";                  // '\t' creates a tab space, '\n' adds a newline
    cout << "\0";                              // Null character, not visibly printed
    cout << "Let's print a double quote \"  "; // Prints double quote using \"

    return 0;
}

/**
 * @example
 * Output:
 * hello   world
 * Let's print a double quote "
 */
