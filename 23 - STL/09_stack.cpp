/**
 * @file 09_stack.cpp
 * @brief Demonstration of std::stack in C++ STL.
 *
 * Stack Data Structure:
 * - Also known as container adaptor.
 * - Needs an underlying container like array, vector, or linked list.
 * - Follows LIFO: Last In, First Out.
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<int> s;

    // Pushing elements onto the stack
    s.push(4);
    s.push(8);
    s.push(11);
    s.push(3);

    // Top element
    cout << s.top() << endl;

    // s.clear() is not supported in stack
    // Checking if stack is empty
    if (s.empty())
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }

    // Note: To print full stack, use a loop and pop elements (see GFG article)

    return 0;
}
