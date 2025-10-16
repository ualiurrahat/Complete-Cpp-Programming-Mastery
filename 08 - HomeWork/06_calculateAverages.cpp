/**
 * @file 06_calculateAverages.cpp
 * @brief Calculate different averages and ratios based on 5 input values.
 *
 * Problem Statement:
 * Given five floating-point numbers, compute:
 * 1. The overall average of all five numbers.
 * 2. The ratio of the sum of the first three numbers to the sum of the last two.
 * 3. The ratio of the average of the first three numbers to the average of the last two.
 * Finally, compute two-thirds of the ratio from step 2.
 */

#include <iostream>
using namespace std;

int main()
{
    double a1, a2, a3, a4, a5;

    // Input 5 numbers from the user
    cin >> a1 >> a2 >> a3 >> a4 >> a5;

    // ---------------------- Calculations ----------------------
    double avg1 = (a1 + a2 + a3 + a4 + a5) / 5.0; // A: Overall average
    double sum1 = (a1 + a2 + a3) / (a4 + a5);     // B: Ratio of first 3 sum to last 2 sum
    double first3_avg = (a1 + a2 + a3) / 3.0;     // Average of first 3
    double last2_avg = (a4 + a5) / 2.0;           // Average of last 2
    double avg2 = first3_avg / last2_avg;         // C: Ratio of averages

    // ---------------------- Output Results ----------------------
    cout << avg1 << "\n";
    cout << sum1 << "\n";
    cout << avg2 << "\n";
    cout << sum1 * 2.0 / 3.0 << "\n"; // Two-thirds of B

    return 0;
}
