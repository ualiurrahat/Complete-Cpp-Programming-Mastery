/**
 * @file 01_guessRuntimeOutput.cpp
 * @brief Homework 1: Guess the runtime output of the code.
 *
 * @details
 * Step through the code line by line before running it.
 * Compare your prediction with actual output.
 *
 * Key concepts:
 * - Order of execution
 * - Mixing numbers and strings
 * - Unreachable code after return
 *
 * Expected output:
 *
 * Guess the output
 * ---
 * 25
 * 14/2
 * 7
 * endlPractice makes perfect
 */

#include <iostream>
using namespace std;

int main()
{
    cout << "\n\nGuess the "
         << "output\n---\n";

    cout << 10 + 20 - 5 << endl;        // 25
    cout << "14/2" << "\n";             // printed as string
    cout << 17 - 10 << "\n";            // 7
    cout << "endl";                     // printed literally
    cout << "\nPractice makes perfect"; // new line + string

    // This line will never execute as it's after return
    return 0;

    cout << "\n\nBye\n\n"; // unreachable
}
