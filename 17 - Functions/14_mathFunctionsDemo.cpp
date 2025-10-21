/**
 * @problem_statement
 * Demonstrate the use of standard mathematical and character functions in C++.
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
    // -------------------- Absolute and rounding functions --------------------
    cout << abs(-2) << "\n";     // 2
    cout << fabs(-2.4) << "\n";  // 2.4
    cout << ceil(2.4) << "\n";   // 3
    cout << floor(2.4) << "\n";  // 2
    cout << round(2.4) << "\n";  // 2
    cout << round(2.6) << "\n";  // 3
    cout << round(-2.6) << "\n"; // -3
    cout << ceil(-2.4) << "\n";  // -2
    cout << floor(-2.4) << "\n"; // -3
    cout << sqrt(16) << "\n";    // 4

    // -------------------- Character checking functions --------------------
    cout << isalpha('A') << "\n";       // Non-zero (true)
    cout << isalpha('#') << "\n";       // 0 (false)
    cout << isdigit('3') << "\n";       // 1 (true)
    cout << isupper('A') << "\n";       // Non-zero (true)
    cout << (char)tolower('X') << "\n"; // x
    cout << (char)toupper('x') << "\n"; // X

    // -------------------- Math and random functions --------------------
    cout << max(5, 9) << "\n";   // 9
    cout << pow(2, 4) << "\n";   // 16
    cout << log2(16) << "\n";    // 4
    cout << log10(1000) << "\n"; // 3

    cout << (double)rand() / RAND_MAX << "\n"; // Random value between 0 and 1

    return 0;
}
