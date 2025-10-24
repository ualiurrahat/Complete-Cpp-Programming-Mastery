/**
 * @file 08_thisPointer.cpp
 * @brief Demonstrates the use of the `this` pointer in C++.
 *
 * The `this` pointer is an implicit pointer available in all non-static member functions.
 * It points to the current object which invokes the member function.
 * Using `this`, we can:
 * - Resolve naming conflicts between member variables and function parameters.
 * - Return the calling object itself (enabling method chaining).
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @class A
 * @brief Demonstrates usage of the `this` pointer.
 */
class A
{
    int a; ///< Data member representing an integer value.

public:
    /**
     * @brief Sets the value of `a` using the `this` pointer.
     *
     * @param a The integer value to assign to the member variable `a`.
     * @return A& Returns reference to the calling object (*this), enabling method chaining.
     *
     * @note `this` is a pointer to the object that invoked the method.
     * Dereferencing `this` (i.e., `*this`) returns the current object.
     */
    A &setValue(int a)
    {
        this->a = a;  // Resolving ambiguity between parameter 'a' and member variable 'a'
        return *this; // Returning the current object by reference
    }

    /**
     * @brief Prints the value of `a`.
     */
    void getValue()
    {
        cout << "Value of a is " << a << endl;
    }
};

int main()
{
    // Example 1: Normal usage of setValue() and getValue()
    A obj1;
    obj1.setValue(25); // Calls setValue() on obj1
    obj1.getValue();   // Displays: Value of a is 25

    // Example 2: Method chaining using return by reference
    A obj2;
    obj2.setValue(8).getValue();
    // Explanation:
    // - setValue(8) assigns value to obj2.a and returns *this (i.e., obj2 itself).
    // - Since it returns obj2, we can directly call getValue() on it.

    return 0;
}
