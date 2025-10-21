/**
 * @problem_statement
 * Write a program to demonstrate the difference between local, global, and static variables in C++.
 */

#include <iostream>
using namespace std;

// -------------------------- Global variables --------------------------
int global_val{9};
int g2;                      // Default initialized to 0
int g3{};                    // Also initialized to 0
int g4 = ++global_val;       // Increments global_val before assigning
int static global_sval = 10; // Static global variable

/**
 * @brief Demonstrates local and static local variable behavior.
 *
 * @note Time complexity: O(1)
 * @note Space complexity: O(1)
 */
void fun()
{
    int i1{0};        // Local variable (resets every call)
    static int si{0}; // Static variable (retains value between calls)
    ++i1;
    ++si;
    global_val += 10;

    cout << i1 << " " << si << " " << global_val << "\n";
}

int main()
{
    fun(), fun(), fun();
    cout << global_val << "\n";

    /*
        Explanation:
        1st call: i1=1, si=1, global_val=20
        2nd call: i1=1, si=2, global_val=30
        3rd call: i1=1, si=3, global_val=40
        Final output:
        1 1 20
        1 2 30
        1 3 40
        40
    */
    return 0;
}
