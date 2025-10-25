/**
 * @file 02_SumImplementation.cpp
 * @brief Source file – **definition** of `sum_1_n`.
 *
 * @note The implementation is compiled **once** into an object file.
 * @note It includes the header to get the declaration.
 */

#include "01_SumDeclaration.cpp" // use the header from the same sub-folder

int sum_1_n(int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += i;
    return sum;
}