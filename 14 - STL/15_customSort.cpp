/**
 * @file 15_customSort.cpp
 * @brief Sorting using custom comparison functions.
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// descending sort for integers
bool descending(int a, int b)
{
    return a > b;
}

// ascending sort based on string length
bool ascending(string &a, string &b)
{
    return a.size() < b.size();
}

int main()
{
    int arr[4] = {9, 5, 7, 10};

    // sorting in descending order
    sort(arr, arr + 4, descending);
    for (int i = 0; i < 4; i++)
        cout << arr[i] << " ";
    cout << endl;

    // sorting strings by length
    string str[4] = {"Violet", "Blue", "Red", "Green"};
    sort(str, str + 4, ascending);
    for (int i = 0; i < 4; i++)
        cout << str[i] << " ";
    cout << endl;

    return 0;
}
