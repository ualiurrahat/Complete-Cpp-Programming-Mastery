/**
 * @file 07_structQueue.cpp
 * @brief Demonstrates a queue data structure using struct.
 *
 * -------------------- Problem Statement --------------------
 * Implement a simple queue supporting:
 * 1. Add to end (enqueue)
 * 2. Add to front
 * 3. Remove from front (dequeue)
 * 4. Print all elements
 * -----------------------------------------------------------
 */

#include <iostream>
using namespace std;

// ---------------------- Queue Structure ----------------------
struct queue
{
    int arr[100]; // Static array for storing elements
    int len;      // Current length

    // Constructor to initialize queue
    queue()
    {
        len = 0;
    }

    // Add element to the end
    void add_end(int value)
    {
        arr[len++] = value;
    }

    // Add element to the front by shifting right
    void add_front(int value)
    {
        for (int i = len - 1; i >= 0; --i)
            arr[i + 1] = arr[i];
        arr[0] = value;
        len++;
    }

    // Remove element from front
    int remove_front()
    {
        int ret = arr[0];
        for (int i = 1; i < len; ++i)
            arr[i - 1] = arr[i];
        --len;
        return ret;
    }

    // Print queue contents
    void print()
    {
        for (int i = 0; i < len; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

// ---------------------- Main Function ----------------------
int main()
{
    queue my_queue;

    my_queue.add_end(10);
    my_queue.add_end(20);
    my_queue.add_end(30);
    my_queue.print();

    my_queue.add_front(1);
    my_queue.add_front(4);
    my_queue.print();

    cout << my_queue.remove_front() << "\n";
    my_queue.print();

    return 0;
}
