/**
 * @file 12_isPalindrome.cpp
 * @brief Problem: Check if an array is palindrome using recursion.
 * Two versions:
 * - v1: using start & end indices
 * - v2: using shifted array pointer
 */

#include <iostream>
using namespace std;

// Version 1: with start and end indices
bool is_palindrome_v1(int arr[], int start, int end)
{
    if (start >= end) // Base case: crossed middle
        return true;

    if (arr[start] != arr[end]) // If mismatch, not palindrome
        return false;

    return is_palindrome_v1(arr, start + 1, end - 1);
}

// Version 2: shift array pointer
bool is_palindrome_v2(int arr[], int end)
{
    if (end <= 0) // Base case: single element or empty
        return true;

    if (arr[0] != arr[end])
        return false;

    return is_palindrome_v2(arr + 1, end - 2);
}

int main()
{
    int arr[] = {1, 8, 2, 8, 1};

    cout << is_palindrome_v1(arr, 0, 4) << "\n";
    cout << is_palindrome_v2(arr, 4) << "\n";

    return 0;
}
