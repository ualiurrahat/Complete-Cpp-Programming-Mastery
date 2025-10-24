/**
 * @file 09_Atexit_FunctionPointer.cpp
 * @brief Register function to run at program exit.
 *
 * Problem Statement:
 * Execute cleanup code when `main` ends.
 *
 * New Topics Introduced:
 * - `atexit(func)` → register exit handler
 * - Called in reverse order of registration
 * - Max 32 handlers (implementation-defined)
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <cstdlib>
using namespace std;

void ByeMsg() {
    cout << "Thanks for using our program!\n";
}

int main() {
    atexit(ByeMsg);
    cout << "Hello from main!\n";
    return 0;
}