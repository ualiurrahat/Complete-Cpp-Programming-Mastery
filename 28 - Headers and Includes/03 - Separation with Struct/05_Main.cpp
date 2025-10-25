/**
 * @file 05_Main.cpp
 * @brief Demo program that uses the globally allocated `Employee`.
 *
 * @note Only the header is needed; implementation is linked separately.
 */

#include <iostream>
#include "02_StructHeader.cpp"
using namespace std;

int main()
{
    emp_glob->Print(); // I am mostafa
    return 0;
}