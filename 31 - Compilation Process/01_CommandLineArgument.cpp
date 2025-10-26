/**
 * @file 01_CommandLineArguments.cpp
 * @brief Demonstrates basic command-line argument parsing in C++.
 *
 * This program illustrates how command-line arguments are passed to a C++ program
 * via the `main` function parameters `argc` and `argv`. It prints the total number
 * of arguments and each argument string.
 *
 * @section intuition Intuition
 * When a program is executed from the terminal, the shell can pass additional
 * parameters (arguments). These are captured in `main(int argc, char* argv[])`.
 * - `argc`: Argument count (including the program name)
 * - `argv`: Array of C-style strings (char*) where:
 *   - argv[0] = program name
 *   - argv[1]...argv[argc-1] = user-provided arguments
 *
 * This is the **first step** in understanding compilation and execution flow —
 * how external input reaches your program.
 *
 * @section logic Logic & Flow
 * 1. Print total number of arguments (`argc`)
 * 2. Iterate from 0 to argc-1
 * 3. Print each `argv[i]` on a new line
 *
 * @note argv[0] is always the program path/name. Others depend on user input.
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    // Display total number of arguments including program name
    cout << argc << " arguments:" << "\n";

    // Loop through all arguments and print each one
    for (int i = 0; i < argc; ++i) {
        // argv[i] is a null-terminated C-string (char*)
        // cout handles it safely and prints until '\0'
        cout << argv[i] << "\n";
    }

    return 0;  // Successful termination
}