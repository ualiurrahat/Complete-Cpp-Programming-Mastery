/**
 * @file 10_queue.cpp
 * @brief Demonstration of std::queue in C++ STL.
 *
 * Queue:
 * - Container adaptor.
 * - Follows FIFO: First In, First Out.
 */

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    queue<int> q;

    // Pushing elements into the queue
    q.push(18);
    q.push(1);
    q.push(8);
    q.push(25);
    q.push(20);

    // Accessing front and back
    cout << q.front() << " ";
    cout << q.back() << endl;

    // Removing front element
    q.pop();
    cout << q.front() << endl;

    // Queue size
    cout << "size: " << q.size() << endl;

    return 0;
}
