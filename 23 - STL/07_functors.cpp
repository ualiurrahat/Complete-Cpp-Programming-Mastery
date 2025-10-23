/**
 * @file 07_functors.cpp
 * @brief Demonstration of function objects (functors) in C++ STL.
 *
 * Function Object (Functor) = Function wrapped in a class so it can be used like an object.
 * Example: std::greater<int>() for sorting in descending order.
 */

#include <iostream>
#include <algorithm>  // for sort()
#include <functional> // for function objects
using namespace std;

int main()
{
    int arr[] = {18, 1, 8, 20, 13, 14, 25};

    // Sorting the array in ascending order
    sort(arr, arr + 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sorting the array in descending order using functor greater<int>()
    sort(arr, arr + 7, greater<int>());
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
