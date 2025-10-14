/**
 * @file 02_printWithEndl.cpp
 * @brief Demonstrates how to print using `cout` and insert line breaks using `endl`.
 *
 * @details
 * The `endl` keyword adds a newline and flushes the output buffer.
 * It is a common way to separate lines in console output.
 */

#include <iostream>
using namespace std;

int main()
{
    cout << "I am Rahat";
    cout << endl;
    cout << "I was born in Gazipur";
    cout << "I graduated from Gopalganj Science and Technology University";
    cout << endl;

    return 0;
}

/*
---------------------- Explanation ----------------------

✅ endl
   - Short for "end line".
   - It moves the cursor to the next line (like pressing Enter).
   - Also flushes (clears) the output buffer.

✅ Output:
   I am Rahat
   I was born in GazipurI graduated from Gopalganj Science and Technology University

⚠️ Observation:
   - There is no newline between the last two sentences
     because no `endl` was inserted between them.

---------------------------------------------------------
*/
