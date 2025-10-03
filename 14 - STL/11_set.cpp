/**
 * @file 11_set.cpp
 * @brief Demonstration of std::set in C++ STL.
 *
 * Topic: Set
 * Syntax: set<T> objectName;
 *
 * - Set is an associative container that contains a sorted set of unique objects of type key.
 * - Internally implemented using Red-Black Tree (RBT)
 * - User-defined data types require a comparison function to store in sorted order.
 *
 * Notes:
 * - set: sorted, unique elements, complexity O(log n)
 * - unordered_set: unsorted, uses HashSet, complexity O(1)
 */

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    set<int> s; // example: s = {10, 5, 30, 2} => s = {2, 5, 10, 30}
    s.insert(10);
    s.insert(5);
    s.insert(30);
    s.insert(2);
    s.insert(2); // duplicate insertion ignored
    cout << s.size() << endl;

    // checking if 8 and 2 exist in the set
    auto it = s.find(8);
    if (it != s.end())
        cout << "8 is present" << endl;
    else
        cout << "8 not present" << endl;

    it = s.find(2);
    if (it != s.end())
        cout << "2 is present" << endl;
    else
        cout << "2 not present" << endl;

    // count number of 2's
    int count = s.count(2);
    cout << count << endl;

    // displaying the set
    cout << "s = { ";
    for (it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << ", ";
    }
    cout << "}" << endl;

    // clearing the set
    s.clear();
    if (s.empty())
        cout << "set s is empty." << endl;
    else
        cout << "s is not empty." << endl;

    return 0;
}
