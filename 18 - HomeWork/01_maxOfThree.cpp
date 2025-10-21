/**
 * @file 01_maxOfThree.cpp
 * @brief Program to find the maximum of three numbers using a user-defined function.
 */

#include <iostream>
using namespace std;

/**
 * @brief Returns the maximum among three integers.
 *
 * @param first  First number
 * @param second Second number
 * @param third  Third number
 * @return int   The largest number among the three
 *
 * @note Time Complexity: O(3)
 * @note Space Complexity: O(1)
 */
int max_of_three(int first, int second, int third)
{
    // Initialize the max value as the first number
    int max_value = first;

    // Compare with the second number
    if (second > max_value)
        max_value = second;

    // Compare with the third number
    if (third > max_value)
        max_value = third;

    // Return the final maximum number
    return max_value;
}

int main()
{
    int a, b, c;

    cout << "Enter three integers: ";
    cin >> a >> b >> c;

    // Call the function and store the result
    int result = max_of_three(a, b, c);

    cout << "The maximum number is: " << result << "\n";

    return 0;
}
