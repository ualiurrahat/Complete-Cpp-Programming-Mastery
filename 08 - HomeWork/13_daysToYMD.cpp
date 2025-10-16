/**
 * @file 13_daysToYMD.cpp
 * @brief Convert total days into years, months, and days.
 *
 * Assumptions:
 * - 1 year = 360 days
 * - 1 month = 30 days
 *
 * Example:
 * Input: 400
 * Output: 1 1 10  (1 year, 1 month, 10 days)
 */

#include <iostream>
using namespace std;

int main()
{
    int days;
    cin >> days;

    // Calculate years
    int years = days / 360;
    days = days % 360; // Remove complete years

    // Calculate months
    int months = days / 30;
    days = days % 30; // Remaining days

    cout << years << " " << months << " " << days << "\n";

    return 0;
}
