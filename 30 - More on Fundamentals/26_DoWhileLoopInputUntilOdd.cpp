/**
 * @file 26_DoWhileLoopInputUntilOdd.cpp
 * @brief Reads integers until an odd number is entered using do-while loop.
 *
 * Intuition:
 * - We need to read at least one number before checking condition
 * - do-while guarantees body executes once before condition check
 * - Loop continues as long as input is even
 *
 * Use Case: Input validation requiring at least one attempt
 */

#include <iostream>
using namespace std;

int main()
{
    int n;

    /**
     * @brief do-while loop: Body executes first, then condition is checked
     *
     * Step-by-step:
     * 1. Prompt and read n (cin >> n)
     * 2. Print the number
     * 3. Check if n is even (n % 2 == 0)
     * 4. If even, repeat loop
     * 5. If odd, exit loop
     */
    do
    {
        cin >> n;
        cout << n << "\n";
    } while (n % 2 == 0);

    // After loop: n is odd (or input failed)
    return 0;
}