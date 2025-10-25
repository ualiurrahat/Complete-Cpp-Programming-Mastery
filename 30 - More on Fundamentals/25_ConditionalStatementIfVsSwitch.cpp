/**
 * @file 25_ConditionalStatementsIfVsSwitch.cpp
 * @brief Demonstrates the difference between if-else chains and switch statements.
 *
 * This program compares two approaches to handling multiple integer conditions:
 * 1. Using nested if-else statements
 * 2. Using a switch statement with fall-through cases
 *
 * Key Learning:
 * - switch is more efficient and readable when comparing a single variable against constants
 * - Fall-through behavior in switch allows multiple cases to share code
 * - Default case acts like final 'else'
 */

#include <iostream>
using namespace std;

/**
 * @brief Handles input using if-else chain
 *
 * Reads an integer and prints specific messages based on its value.
 * Demonstrates verbose conditional logic with multiple else-if branches.
 */
void go1()
{
    int num;
    cin >> num;

    if (num == 1)
        cout << "1\n";
    else if (num == 100 || num == 1000)
        cout << "100 or 1000\n";
    else if (num == 200)
    {
        cout << "200\n";
        cout << "hmm\n";
    }
    else
        cout << "hmm\n";
}

/**
 * @brief Handles input using switch statement
 *
 * Same logic as go1(), but implemented with switch.
 * Uses fall-through (no break) for cases 100 and 1000.
 * Default case handles all unmatched values.
 */
void go2()
{
    int num;
    cin >> num;

    switch (num)
    {
    case 1:
        cout << "1\n";
        break;
    case 100:
    case 1000:
        cout << "100 or 1000\n";
        break;
    case 200:
        cout << "200\n"; // Falls through to default
    default:
        cout << "hmm\n";
    }
}

int main()
{
    // Execute if-else version
    go1();

    // Note: go2() is defined but not called in original main()
    // In a complete example, you might call both for comparison

    return 0;
}