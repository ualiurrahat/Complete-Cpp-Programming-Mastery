/**
 * @file 13_multiset.cpp
 * @brief Demonstration of std::multiset in C++ STL.
 *
 * - Unlike set, duplicate elements are allowed.
 */

#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    multiset<int> s; // e.g., s = {10,5,30,2} => s={2,2,2,5,10,30}
    s.insert(10);
    s.insert(5);
    s.insert(30);
    s.insert(2);
    s.insert(2);
    s.insert(2);
    cout << s.size() << endl;

    // checking if 8 and 2 exist in the multiset
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

    // display multiset
    cout << "s = { ";
    for (it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << ", ";
    }
    cout << "}" << endl;

    // clearing the multiset
    s.clear();
    if (s.empty())
        cout << "multiset s is empty." << endl;
    else
        cout << "multiset is not empty." << endl;

    return 0;
}
