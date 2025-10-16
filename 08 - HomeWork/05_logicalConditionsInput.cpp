/**
 * @file 05_logicalConditionsInput.cpp
 * @brief Homework 2: Practice logical conditions with user input.
 *
 * The program reads three integers representing:
 *   - nb → number of boys
 *   - ng → number of girls
 *   - nt → number of teachers
 *
 * Then evaluates and prints various logical conditions to understand
 * **comparison** and **boolean expressions** in C++.
 */

#include <iostream>
using namespace std;

/**
 * @brief Entry point of the program.
 *
 * Reads three integers (nb, ng, nt) and prints results of different
 * logical expressions for practice.
 *
 * @return int Program exit status (0 = success).
 */
int main()
{
    int nb, ng, nt;
    cin >> nb >> ng >> nt; // Example input: 30 40 5

    // nb greater than 25
    cout << (nb > 25) << "\n"; // true if nb > 25

    // ng less than or equal to 30
    cout << (ng <= 30) << "\n"; // true if ng ≤ 30

    // nb > 20 and nt > 2 or ng > 30 and nt > 4
    cout << (nb > 20 && nt > 2 || ng > 30 && nt > 4) << "\n";

    // Either nb < 60 or ng < 70
    cout << (nb < 60 || ng < 70) << "\n";

    // Neither nb >= 60 nor ng >= 70
    cout << (!(nb >= 60) && !(ng >= 70)) << "\n";

    // nb is 10 more students than ng
    cout << (nb == ng + 10) << "\n";

    // Difference between nb and ng is more than 10 or nt > 5
    cout << (nb - ng > 10 || nt > 5) << "\n";

    // Either nb is 10 more students than ng or ng is 15 more than nb
    cout << (nb == ng + 10 || ng == nb + 15) << "\n";

    return 0;
}
