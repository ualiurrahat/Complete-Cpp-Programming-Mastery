/**
 * @file 03_combinedPrintWithEndlAndN.cpp
 * @brief Demonstrates printing with both `endl` and `\n` newline characters.
 *
 * @details
 * C++ provides two ways to move to a new line:
 *  - Using `endl` (flushes output buffer)
 *  - Using `\n` (faster, does not flush buffer)
 */

#include <iostream>
using namespace std;

int main()
{
    cout << "I am " << "Rahat" << endl
         << "I was born in Gazipur\n";
    cout << "I graduated from Gopalganj Science and Technology University";
    cout << endl;

    return 0;
}

/*
---------------------- Explanation ----------------------

✅ endl vs \n
   - `endl`: Inserts newline AND flushes the output buffer (slightly slower).
   - `\n`:   Inserts newline only (faster).

✅ Output:
   I am Rahat
   I was born in Gazipur
   I graduated from Gopalganj Science and Technology University

✅ Observation:
   - Here we combined both methods.
   - You can choose either depending on your needs.

---------------------------------------------------------
*/
