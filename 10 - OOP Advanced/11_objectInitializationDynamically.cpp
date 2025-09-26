/**
 * @file 11_objectInitializationDynamically.cpp
 * @brief Demonstrates dynamic initialization of objects using constructors in C++.
 *
 * Dynamic initialization means initializing objects at runtime.
 * This is especially useful when the input data can vary in type or format.
 *
 * Example:
 *  - User may provide interest rate as `0.05` (float)
 *  - Or as `5` (integer, meaning 5%)
 * The compiler decides at runtime which constructor to call based on data type.
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @class BankDeposit
 * @brief Represents a bank deposit with principal, time, and interest rate.
 */
class BankDeposit
{
    int capital;        ///< Principal amount invested
    int year;           ///< Time period of investment
    float interestRate; ///< Interest rate (float or converted from int)
    float returnValue;  ///< Final return value after applying interest

public:
    BankDeposit() {}; ///< Default constructor (needed for flexibility)

    /**
     * @brief Constructor accepting interest rate as a float (e.g., 0.05 for 5%)
     */
    BankDeposit(int c, int y, float r);

    /**
     * @brief Constructor accepting interest rate as an integer percentage (e.g., 5 for 5%)
     */
    BankDeposit(int c, int y, int r);

    /**
     * @brief Displays deposit details including final return value.
     */
    void show();
};

// -------------------- Constructor Definitions --------------------

BankDeposit::BankDeposit(int c, int y, float r)
{
    capital = c;
    year = y;
    interestRate = r;
    returnValue = capital;

    for (int i = 0; i < y; i++)
    {
        returnValue = returnValue * (1 + interestRate);
    }
}

BankDeposit::BankDeposit(int c, int y, int r)
{
    capital = c;
    year = y;
    interestRate = float(r) / 100; // Convert integer percentage to decimal
    returnValue = capital;

    for (int i = 0; i < y; i++)
    {
        returnValue = returnValue * (1 + interestRate);
    }
}

// -------------------- Member Function --------------------
void BankDeposit::show()
{
    cout << "Capital amount : " << capital << endl
         << "Period of investment: " << year << " years" << endl
         << "Return Value : " << returnValue << endl;
}

// ------------------------------- Main -------------------------------
int main()
{
    BankDeposit ac1;

    int c, y;
    float r;

    cout << "Enter capital amount, time, and interest rate: " << endl;
    cout << "(Example: 100 1 0.05 or 100 1 5)" << endl;
    cin >> c >> y >> r;

    // Compiler decides at runtime which constructor to call:
    // - If r is float (0.05) → float constructor is called
    // - If r is int (5) → int constructor is called
    ac1 = BankDeposit(c, y, r);

    ac1.show();

    return 0;
}
