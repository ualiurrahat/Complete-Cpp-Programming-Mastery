/**
 * @file 01_userInputSingle.cpp
 * @brief Demonstrates user input using `cin` and simple arithmetic.
 *
 * @details
 * - `cin` reads value from the user and stores it in a variable.
 * - `cout` prints values to the console.
 * - Example: double your input and add 1.
 */

#include <iostream>
using namespace std;

int main()
{
    int num;

    // Prompt user to enter their lucky number
    cout << "Enter your lucky number\n";

    // Read user input
    cin >> num;

    // Display result
    cout << "********\n";
    cout << 2 * num + 1 << "\n"; // simple arithmetic: 2*num + 1

    return 0;
}
