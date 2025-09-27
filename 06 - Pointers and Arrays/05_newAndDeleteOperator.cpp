/**
 * @file 05_newAndDeleteOperator.cpp
 * @brief Demonstrates the use of new and delete operators in C++ for dynamic memory allocation and deallocation.
 *
 * Problem Statement:
 * - Understand how to use `new` operator to allocate memory for single variables and arrays.
 * - Demonstrate initialization of dynamically allocated memory.
 * - Show how to release memory using `delete` and `delete[]`.
 * - Explore behavior of pointers after memory deallocation.
 */

#include <iostream>
using namespace std;

int main()
{
    // ---------------------- Basic Pointer Example ----------------------
    int r = 25;
    int *ptr = &r;
    cout << "The value at address ptr is " << (*ptr) << endl;

    // ---------------------- Using new Operator ----------------------
    // Allocate memory dynamically and initialize values
    int *ptr2 = new int(29);
    float *ptr3 = new float(8.25);

    cout << "The value at address ptr2 is " << (*ptr2) << endl;
    cout << "The value at address ptr3 is " << (*ptr3) << endl;

    // Dynamically allocate an array
    int *arr = new int[3];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    cout << "The value of arr[0] is " << arr[0] << endl;
    cout << "The value of arr[1] is " << arr[1] << endl;
    cout << "The value of arr[2] is " << arr[2] << endl;

    // ---------------------- Using delete Operator ----------------------
    // Release dynamically allocated array
    delete[] arr;

    cout << "After delete[] arr:" << endl;
    cout << "arr[0] = " << arr[0] << " (garbage value)" << endl;
    cout << "arr[1] = " << arr[1] << " (garbage value)" << endl;
    cout << "arr[2] = " << arr[2] << " (garbage value)" << endl;

    // Release memory allocated to single variables
    delete ptr2;
    delete ptr3;

    cout << "After deleting ptr2 and ptr3, accessing them is undefined behavior." << endl;

    return 0;
}
