/**
 * @file 01_basicPrinting.cpp
 * @brief Demonstrates basic printing using `cout` without line breaks.
 *
 * @details
 * In this example, we print multiple sentences using `cout`.
 * However, since there are no line breaks (`endl` or `\n`),
 * the text will appear on the same line in the console.
 */

#include <iostream>  // Required for input/output operations
using namespace std; // Gives access to standard objects like cout and cin

/**
 * @brief The main function — entry point of the program.
 * @return int Returns 0 when execution completes successfully.
 * @note Time complexity: O(1)
 * @note Space complexity: O(1)
 */
int main()
{
    cout << "I am Rahat";
    cout << "I was born in Gazipur";
    cout << "I graduated from Gopalganj Science and Technology University";

    return 0;
}

/*
---------------------- Explanation ----------------------

✅ cout
   - Stands for "console output".
   - It is used to display information on the screen.

✅ Problem in this program:
   - All statements are printed continuously without space or new line.
   - Output will look like:
       I am RahatI was born in GazipurI graduated from Gopalganj Science and Technology University

✅ Why?
   - Because each cout statement prints directly after the previous one
     unless a newline or space is explicitly added.

---------------------------------------------------------
*/
