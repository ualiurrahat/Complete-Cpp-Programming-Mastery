/**
 * Problem: Check if an array is a palindrome.
 *
 * Concepts:
 * - An array is palindrome if it reads the same forwards and backwards.
 * - Compare elements from left and right moving towards the center.
 * - Time complexity: O(n), Space complexity: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    int arr[999]; // Array size should be at least N
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    // Check palindrome by comparing left and right
    for (int i = 0; i < N / 2; i++)
    {
        if (arr[i] != arr[N - 1 - i])
        {
            cout << "NO\n";
            return 0; // Early exit if not palindrome
        }
    }

    cout << "YES\n";
    return 0;
}
