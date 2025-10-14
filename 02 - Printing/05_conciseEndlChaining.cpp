/**
 * @file 05_conciseEndlChaining.cpp
 * @brief A compact version of multi-line output using a single cout statement.
 *
 * @details
 * Here, all output is written in one continuous chain using `<<` and `endl`.
 * This makes the code concise while producing the same result.
 */

#include <iostream>
using namespace std;

int main()
{
    cout << "I am Rahat"
         << endl
         << "I was born in Gazipur"
         << endl
         << "I graduated from Gopalganj Science and Technology University"
         << endl;

    return 0;
}

/*
---------------------- Explanation ----------------------

✅ Benefit:
   - All printing is done in one statement.
   - Easy to read and maintain.

✅ Output:
   I am Rahat
   I was born in Gazipur
   I graduated from Gopalganj Science and Technology University

---------------------------------------------------------
*/
