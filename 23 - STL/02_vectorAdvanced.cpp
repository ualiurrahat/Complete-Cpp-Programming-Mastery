/**
 * @file 02_vectorAdvanced.cpp
 * @brief More operations on std::vector
 *
 * Syntax: std::vector<int> vector_name;
 *
 * 1. Vector is a sequence container. Also known as Dynamic Array or Array List.
 * 2. Its size can grow and shrink dynamically, no need to provide size in compile time.
 *
 * Element Access: at(), [], front(), back(), data()
 * Modifiers: insert(), emplace(), push_back(), emplace_back(),
 *            pop_back(), resize(), swap(), erase(), clear()
 *
 * note:
 * arr[index]: if index exceeds size of arr, then compiler shows error.
 * arr.at(index): if index is greater than size, then compiler shows exception (runtime).
 */

#include <iostream>
#include <vector>
#include <numeric>   // for accumulate, partial_sum
#include <algorithm> // for min_element, max_element

using namespace std;

int main()
{
    // ways of traversing a vector.
    vector<int> v = {1, 2, 3};

    // way 1: index-based loop
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // way 2: using iterator
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // way 3: using range-based loop
    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << endl;

    vector<int> v2 = {10, 20, 30};

    // swap two vectors.
    swap(v, v2);

    cout << "v: ";
    for (auto element : v)
        cout << element << " ";
    cout << endl;

    cout << "v2: ";
    for (auto element : v2)
        cout << element << " ";
    cout << endl;

    // sum of vector
    int sum1 = accumulate(v.begin(), v.end(), 0);
    cout << sum1 << endl;

    // max and min of vector
    int mx1 = *max_element(v.begin(), v.end());
    int mn1 = *min_element(v.begin(), v.end());

    cout << "max of v: " << mx1 << endl;
    cout << "min of v: " << mn1 << endl;

    // convert to prefix sum vector
    // ex: v={10,20,30} -> prefix_sum v = {10,30,60}
    partial_sum(v.begin(), v.end(), v.begin());
    for (auto element : v)
        cout << element << " ";
    cout << endl;

    return 0;
}
