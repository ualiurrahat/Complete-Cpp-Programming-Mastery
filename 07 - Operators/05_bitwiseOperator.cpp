/**
 * @file bitwiseOperators.cpp
 * @brief Demonstrates bitwise operators in C++.
 *
 * Operators covered:
 * ------------------
 * &   (Bitwise AND)
 * |   (Bitwise OR)
 * ^   (Bitwise XOR)
 * ~   (Bitwise NOT)
 * <<  (Left shift)
 * >>  (Right shift)
 */

#include <iostream>
using namespace std;

int main()
{
    int a = 6; // 0110 in binary
    int b = 3; // 0011 in binary

    cout << "a = " << a << ", b = " << b << endl;

    cout << "a & b : " << (a & b) << endl;  // 0010 = 2
    cout << "a | b : " << (a | b) << endl;  // 0111 = 7
    cout << "a ^ b : " << (a ^ b) << endl;  // 0101 = 5
    cout << "~a    : " << (~a) << endl;     // bitwise NOT
    cout << "a << 1: " << (a << 1) << endl; // 1100 = 12
    cout << "a >> 1: " << (a >> 1) << endl; // 0011 = 3

    return 0;
}
