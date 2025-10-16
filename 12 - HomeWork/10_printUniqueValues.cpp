/**
 * Problem: Print all unique elements from an array in order of first appearance.
 *
 * Concepts and Logic:
 * - Use a boolean array to track visited elements.
 * - Avoid nested loops, making the algorithm efficient.
 * - Time complexity: O(n), Space complexity: O(maxValue)
 */

#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    int n;
    cin >> n;

    const int MAX = 500 + 1;
    int is_visited[MAX] = {0}; // Track visited elements

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        assert(0 <= value && value <= 500);

        if (!is_visited[value])
            cout << value << " ";

        is_visited[value] = 1; // Mark as visited
    }
    cout << "\n";

    return 0;
}
