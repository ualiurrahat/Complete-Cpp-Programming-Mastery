/**
 * @file 07_printUsingNewlineCharacter.cpp
 * @brief Demonstrates using only newline character `\n` for printing on separate lines.
 *
 * @details
 * The `\n` character moves the cursor to a new line without flushing the buffer.
 * It is faster than `endl` and is commonly used in competitive programming.
 */

#include <iostream>
using namespace std;

int main()
{
    cout << "I am Rahat\nI was born in Gazipur\nI graduated from Gopalganj Science and Technology University\n";

    return 0;
}

/*
---------------------- Explanation ----------------------

✅ \n (newline character):
   - Adds a new line after the text.
   - Does not flush the buffer → more efficient.

✅ Output:
   I am Rahat
   I was born in Gazipur
   I graduated from Gopalganj Science and Technology University

✅ Best Practice:
   - Use `\n` when printing many lines quickly (e.g., in competitive coding).
   - Use `endl` when you want to ensure the output is immediately displayed.

---------------------------------------------------------
*/
