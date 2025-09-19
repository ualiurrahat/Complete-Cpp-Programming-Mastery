/**
 * @file 05_multiplicationTable.cpp
 * @brief Program to generate multiplication tables from 1 to n up to m terms.
 *
 * Problem Statement:
 * ------------------
 * Write a C++ program to print multiplication tables from 1 to `n`,
 * where each table goes up to `m` multiplications.
 *
 * Example:
 * --------
 * Input:
 *   n = 3
 *   m = 5
 *
 * Output:
 *   The multiplication table for 1 is given below:
 *   1 * 1 = 1
 *   1 * 2 = 2
 *   1 * 3 = 3
 *   1 * 4 = 4
 *   1 * 5 = 5
 *
 *   The multiplication table for 2 is given below:
 *   2 * 1 = 2
 *   2 * 2 = 4
 *   2 * 3 = 6
 *   2 * 4 = 8
 *   2 * 5 = 10
 *
 *   The multiplication table for 3 is given below:
 *   3 * 1 = 3
 *   3 * 2 = 6
 *   3 * 3 = 9
 *   3 * 4 = 12
 *   3 * 5 = 15
 */

#include <iostream>
using namespace std;

/**
 * @brief Prints multiplication tables from 1 to `num`, each up to `term` times.
 *
 * @param num  The maximum number to generate the table for.
 * @param term The highest multiplier for each table.
 *
 * @note Time Complexity: O(num * term)
 * @note Space Complexity: O(1)
 */
void mulTable(int num, int term)
{
    for (int j = 1; j <= num; j++)
    {
        cout << "The multiplication table for " << j << " is given below:" << endl;
        for (int i = 1; i <= term; i++)
        {
            cout << j << " * " << i << " = " << j * i << endl;
        }
        cout << endl;
    }
}

int main()
{
    int num, term;

    cout << "Enter the range of multiplication table (1 to number): ";
    cin >> num;

    cout << "Enter the highest term of multiplication table: ";
    cin >> term;

    mulTable(num, term);

    return 0;
}
