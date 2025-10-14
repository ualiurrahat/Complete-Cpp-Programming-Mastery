/**
 * @file 02_commentingOutCodeLine.cpp
 * @brief Demonstrates single-line comments and how to "disable" lines of code.
 *
 * @details
 * Use `//` to comment out single lines. This is useful when debugging or
 * when you want to temporarily disable certain lines of output or logic.
 *
 * Problem statement:
 * - Print "I am Rahat" and "I graduated..." while the middle line is commented out.
 *
 * Expected output:
 * I am Rahat
 * I graduated from Cairo Gopalganj Science and Technology University
 *
 * @note Time complexity: O(1)
 * @note Space complexity: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    cout << "I am Rahat" << endl;

    // The following line is commented out and will not execute:
    // cout << "I was born in Gazipur\n";

    cout << "I graduated from Cairo Gopalganj Science and Technology University" << endl;

    // return indicates successful termination
    return 0;
}
