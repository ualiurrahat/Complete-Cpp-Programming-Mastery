/**
 * @file 04_chainedEndlPrinting.cpp
 * @brief Demonstrates chaining of `cout` statements using the insertion operator (`<<`).
 *
 * @details
 * C++ allows chaining multiple outputs in a single statement for cleaner code.
 */

#include <iostream>
using namespace std;

int main()
{
    cout << "I am Rahat" << endl
         << "I was born in Gazipur" << endl
         << "I graduated from Gopalganj Science and Technology University" << endl;

    return 0;
}

/*
---------------------- Explanation ----------------------

✅ Chaining:
   - The insertion operator `<<` can be used repeatedly in one statement.
   - Each `endl` moves output to a new line.

✅ Cleaner Output:
   - This method makes code shorter and more readable.

✅ Output:
   I am Rahat
   I was born in Gazipur
   I graduated from Gopalganj Science and Technology University

---------------------------------------------------------
*/
