/**
 * @file 04_list.cpp
 * @brief Demonstration of List in C++ STL
 *
 * - List is a bidirectional linear list.
 * - Provides efficient deletion and insertion operations.
 * - Used when insertion/deletion is frequent.
 * - Internally implemented as a doubly linked list.
 */

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

/**
 * @brief Display elements of a list
 * @param li Reference to list<int>
 */
void display(list<int> &li)
{
    cout << "Displaying this list: ";
    list<int>::iterator it;
    for (it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    // way 1
    list<int> l1;
    l1.assign({18, 1, 8, 20, 25});
    display(l1);

    // way 2
    list<int> l2 = {20, 1, 13, 14, 14};
    display(l2);

    // way 3
    list<int> l3;
    l3.push_back(10);
    l3.push_back(20);
    l3.push_back(30);
    l3.push_back(40);
    l3.push_back(50);
    display(l3);

    // way 4
    list<int> l4(3); // list with 3 size
    list<int>::iterator iter = l4.begin();
    *iter = 2020;
    iter++;
    *iter = 2040;
    iter++;
    *iter = 2060;
    display(l4);

    // sorting list
    l1.sort();
    cout << "list1 after sorting....";
    display(l1);

    // removing element from list
    l2.remove(14); // removes all 14s from l2
    cout << "list2 after removing 14....";
    display(l2);

    // popping elements
    l3.pop_back();
    cout << "list3 after popping last element...";
    display(l3);

    l4.pop_front();
    cout << "list4 after popping first element....";
    display(l4);

    // merging lists
    l1.merge(l2);
    cout << "list1 after merging with list2....";
    display(l1);

    l1.sort();
    display(l1);

    cout << l1.size() << endl;

    return 0;
}
