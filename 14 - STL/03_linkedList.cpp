/**
 * @file 03_linkedlist.cpp
 * @brief Demonstration of Linked List in C++ STL
 *
 * - Singly linked list (forward_list): Each node has data + address of next node.
 * - Doubly linked list (list): Each node has prev + data + next.
 * - Last node always points to NULL.
 */

#include <iostream>
#include <forward_list> // singly linked list
#include <list>         // doubly linked list

using namespace std;

/**
 * @brief Display elements of a forward_list
 * @param li Reference to forward_list<int>
 */
void display(forward_list<int> &li)
{
    cout << "Displaying this linked list: ";
    forward_list<int>::iterator it;
    for (it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    // Singly LL
    forward_list<int> l1 = {2, 5, 6, 7}; // 2 is head of l1, 7 is tail

    // printing the first element
    cout << l1.front() << endl;

    // printing whole l1
    display(l1);

    // creating another single linked list.
    forward_list<int> l2;
    l2.assign({3, 8, 9, 13});

    cout << l2.front() << endl;
    l2.push_front(10);
    cout << l2.front() << endl;

    return 0;
}
