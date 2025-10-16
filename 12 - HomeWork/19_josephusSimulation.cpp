/**
 * Problem:
 * Josephus problem: n people in a circle, every k-th person is removed
 * Simulate the order in which people are removed.
 *
 * Intuition:
 * - Use an array `is_removed` to mark removed people
 * - Start counting from last removed person
 * - Skip removed positions
 * - Handle large k using modulo with remaining alive
 *
 * Time complexity: O(n*k)
 * Space complexity: O(n)
 */

#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    bool is_removed[199] = {0}; // Track removed people
    int last_pos = 0;           // Start counting from first position

    // Simulate removal
    for (int t = 0; t < n; ++t)
    {
        int remaining_alive = n - t;
        int current_k;

        // Reduce large k using modulo
        if (k % remaining_alive == 0)
            current_k = remaining_alive;
        else
            current_k = k % remaining_alive;

        int step = 0;
        int last_person = -1;

        // Find current_k-th alive person
        while (step < current_k)
        {
            if (!is_removed[last_pos])
            {
                last_person = last_pos;
                step++;
            }
            last_pos = (last_pos + 1) % n; // Wrap around circle
        }

        // Remove person
        is_removed[last_person] = 1;
        cout << last_person + 1 << "\n"; // 1-based index
    }

    return 0;
}
