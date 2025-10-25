/**
 * @file 03_Main.cpp
 * @brief Demo program that uses the separated `sum_1_n`.
 *
 * @note Only the header is needed; the::cout lives in <iostream>.
 */

#include <iostream>
#include "01_SumDeclaration.cpp" // header from the same sub-folder
using namespace std;

int main()
{
    cout << sum_1_n(5) << "\n"; // prints 10
    return 0;
}