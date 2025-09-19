/**
 * @file 04_assignmentOperators.cpp
 * @brief Demonstrates assignment operators in C++.
 *
 * Operators covered:
 * ------------------
 * =   (Simple assignment)
 * +=  (Add and assign)
 * -=  (Subtract and assign)
 * *=  (Multiply and assign)
 * /=  (Divide and assign)
 * %=  (Modulus and assign)
 * ++a  (Pre-increment)
 * a++  (Post-increment)
 * --a  (Pre-decrement)
 * a--  (Post-decrement)
 */

#include <iostream>
using namespace std;

int main()
{
    int a = 10;

    cout << "Initial a = " << a << endl;

    a += 5; // a = a + 5
    cout << "After a += 5 → " << a << endl;

    a -= 3; // a = a - 3
    cout << "After a -= 3 → " << a << endl;

    a *= 2; // a = a * 2
    cout << "After a *= 2 → " << a << endl;

    a /= 4; // a = a / 4
    cout << "After a /= 4 → " << a << endl;

    a %= 3; // a = a % 3
    cout << "After a %= 3 → " << a << endl;

    cout << "Pre-increment (++a): " << ++a << endl;
    cout << "Post-increment (a++): " << a++ << " (value after use: " << a << ")" << endl;

    cout << "Pre-decrement (--a): " << --a << endl;
    cout << "Post-decrement (a--): " << a-- << " (value after use: " << a << ")" << endl;

    return 0;
}
