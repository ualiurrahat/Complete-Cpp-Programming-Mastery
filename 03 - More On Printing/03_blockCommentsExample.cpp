/**
 * @file 03_blockCommentsExample.cpp
 * @brief Demonstrates block (multi-line) comments to temporarily disable a block of code.
 *
 * @details
 * Block comments (/* ... * /) span multiple lines and are handy when you
 * want to hide several lines at once during testing.
 *
 * Problem statement:
 * - Print only "I am Rahat" while a larger block of output is commented out.
 *
 * Expected output:
 * I am Rahat
 *
 * @note Time complexity: O(1)
 * @note Space complexity: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    cout << "I am Rahat" << endl;

    /*
        The following block is commented out and will not run.
        It is often used to temporarily disable multiple lines while debugging.
        cout << endl;
        cout << "I was born in Gazipur\n";
        cout << "I graduated from Cairo Gopalganj Science and Technology University";
        cout << endl;
    */

    return 0;
}
