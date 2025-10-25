/**
 * @file 22_RobustTwoNumberInputWithStringStream.cpp
 * @brief Read entire line with `getline()`, then parse using `istringstream`.
 *
 * Advantages:
 * - No buffer mixing issues
 * - Full line control
 * - Easy to give feedback on exact input
 * - Works even with extra spaces/tabs
 */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/**
 * @brief Reads a full line and extracts two integers.
 * @param x First integer
 * @param y Second integer
 */
void Read2Numbers(int &x, int &y)
{
    string line;
    while (true)
    {
        cout << "Enter two integers on one line: ";
        getline(cin, line); // Read entire line

        istringstream iss(line);
        if (iss >> x >> y && iss.eof()) // Must extract exactly two ints, nothing left
            break;
        else
            cout << "Error: Please enter exactly two numbers. Try again.\n";
    }
}

int main()
{
    int a, b;
    Read2Numbers(a, b);
    cout << "Parsed: " << a << " and " << b << "\n";
    return 0;
}