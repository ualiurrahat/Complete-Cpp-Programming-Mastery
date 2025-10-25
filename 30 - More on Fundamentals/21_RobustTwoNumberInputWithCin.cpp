/**
 * @file 21_RobustTwoNumberInputWithCin.cpp
 * @brief Safely read two integers with input validation using `cin.fail()`.
 *
 * Key Techniques:
 * - `cin >> x >> y`: tries to parse two ints
 * - `cin.fail()`: true if parsing failed (non-number, EOF, etc.)
 * - `cin.clear()`: resets fail state
 * - `cin.ignore(...)`: discards bad input
 * - Loop until valid input
 */

#include <iostream>
#include <limits>
using namespace std;

/**
 * @brief Reads two integers with full validation.
 * @param x First output parameter
 * @param y Second output parameter
 */
void Read2Numbers(int &x, int &y)
{
    while (true)
    {
        cout << "Enter two integers (e.g., 10 20): ";
        cin >> x >> y;

        if (cin.fail())
        {
            cout << "Invalid input. Please try again.\n";
            cin.clear();                                         // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad line
        }
        else
        {
            // Success: consume the rest of the line (in case extra text)
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
}

int main()
{
    int a, b;
    Read2Numbers(a, b);
    cout << "You entered: " << a << " and " << b << "\n";
    return 0;
}