/**
 * @file 02_relationalOperators.cpp
 * @brief Demonstrates relational operators in C++.
 *
 * Operators covered:
 * ------------------
 * ==  (Equal to)
 * !=  (Not equal to)
 * >   (Greater than)
 * <   (Less than)
 * >=  (Greater than or equal to)
 * <=  (Less than or equal to)
 */

#include <iostream>
using namespace std;

int main()
{
    int x = 10, y = 20;

    cout << "x = " << x << ", y = " << y << endl;

    cout << "x == y: " << (x == y) << endl;
    cout << "x != y: " << (x != y) << endl;
    cout << "x > y : " << (x > y) << endl;
    cout << "x < y : " << (x < y) << endl;
    cout << "x >= y: " << (x >= y) << endl;
    cout << "x <= y: " << (x <= y) << endl;

    return 0;
}
