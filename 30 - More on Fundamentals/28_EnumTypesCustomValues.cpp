/**
 * @file 28_EnumTypesCustomValues.cpp
 * @brief Illustrates enum usage with implicit and explicit values.
 *
 * Key Points:
 * - Default enum starts at 0
 * - Can assign custom starting values
 * - Gaps in values are allowed
 * - Underlying type is int by default
 */

#include <iostream>
using namespace std;

int main()
{
    /**
     * @brief Basic enum with default values: RED=0, GREEN=1, BLUE=2
     */
    enum color
    {
        RED,
        GREEN,
        BLUE
    }; // 0, 1, 2

    color r = RED;
    cout << r << "\n"; // Output: 0

    r = color(2);      // Explicit cast to BLUE
    cout << r << "\n"; // Output: 2

    /**
     * @brief Enum with explicit start: JAN=1, FEB=2, MAR=3, APR=4
     */
    enum months1
    {
        JAN = 1,
        FEB,
        MAR,
        APR
    };

    /**
     * @brief Enum with mixed values: Feb=2, Mar=3, Apr=4
     */
    enum months2
    {
        Feb = 2,
        Mar,
        Apr = 4
    };

    cout << Mar << "\n"; // Output: 3 (Mar follows Feb)

    return 0;
}