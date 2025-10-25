/**
 * @file 24_PeekNextCharacter.cpp
 * @brief Use `cin.peek()` to inspect the next character **without consuming** it.
 *
 * Use Cases:
 * - Detect if input is number vs letter
 * - Conditional parsing
 * - Build custom input routines
 *
 * Warning: `peek()` returns `EOF` if no character available
 */

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    cout << "Enter something: ";

    // Look at next character without removing it
    int next_char = cin.peek();

    if (next_char == EOF)
        cout << "No input available (EOF).\n";
    else if (isdigit(next_char))
        cout << "Next input is a digit: '" << (char)next_char << "'\n";
    else if (isalpha(next_char))
        cout << "Next input is a letter: '" << (char)next_char << "'\n";
    else
        cout << "Next input is something else: '" << (char)next_char << "'\n";

    // Now consume the full line
    string line;
    getline(cin, line);
    cout << "You entered: '" << line << "'\n";

    return 0;
}