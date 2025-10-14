/**
 * @file 06_printingQuotesFlowAndReturn.cpp
 * @brief Shows printing of strings, arithmetic, multi-line strings and demonstrates flow control.
 *
 * @details
 * This example mixes text, arithmetic and demonstrates that code AFTER return is not executed.
 * It also encourages reading code line-by-line and understanding program flow.
 *
 * Problem statement:
 * - Print a motivational quote, some arithmetic, and show a multi-line string.
 *
 * Expected output (approx):
 * If your dream only includes you, it’s too small
 *
 * 0
 * 70/10
 * 4
 *
 * Opportunities don't happen. You create them
 *
 * (then program ends)
 *
 * Note: The final cout after the 'return' is unreachable and will not show.
 *
 * @note Time complexity: O(1)
 * @note Space complexity: O(1)
 */

#include <iostream>
using namespace std;

// Go over code line by line!

int main()
{
    cout << "If your dream only includes you, it’s too small\n\n";

    // Evaluates to 30 + 20 + 10 - 10 - 20 - 30 = 0
    cout << 30 + 20 + 10 - 10 - 20 - 30 << endl;

    // The following line will print the literal "70/10"
    cout << "70/10" << "\n";

    // Evaluate arithmetic: 80 / 10 / 2 = 4
    cout << 80 / 10 / 2 << "\n";

    cout << "\nOpportunities don't happen. "
         << "You create them"
         << endl;

    // Block comment example (multi-line documentation or quote)
    /*
        Character cannot be developed in ease and quiet. Only through
        experience of trial and suffering can the soul be strengthened,
        ambition inspired, and success achieved
    */

    // Program returns here: subsequent statements are not executed.
    return 0;

    // Unreachable - will not be printed:
    cout << "\n\nDo one thing every day that scares you";
}
