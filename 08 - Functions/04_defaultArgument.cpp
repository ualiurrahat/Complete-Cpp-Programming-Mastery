/**
 * @file 04_defaultArguments.cpp
 * @brief Demonstrates default arguments in C++ functions.
 */

#include <iostream>
using namespace std;

/**
 * @brief Calculates simple interest.
 * @param money Principal amount
 * @param rate Rate of interest (default = 1.04)
 * @return Calculated simple interest
 */
int SI(int money, float rate = 1.04)
{
    return (money * rate) / 100;
}

int main()
{
    int money = 100000;
    float rateSpecialCases = 1.08;

    cout << "If you have Rs." << money
         << ", you'll get an SI of Rs." << SI(money) << " in a year.\n";

    cout << "Mr. Special Case: With Rs." << money
         << ", you'll get an SI of Rs." << SI(money, rateSpecialCases) << " in a year.\n";

    return 0;
}
