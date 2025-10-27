/**
 * @file 14_CopyAssignmentOperator.cpp
 * @brief Implements deep copy via copy constructor and assignment operator.
 *
 * Rule of Three:
 *   - Destructor
 *   - Copy constructor
 *   - Copy assignment operator
 *
 * Critical when class manages raw pointers.
 */

#include <iostream>
#include <vector>
using namespace std;

class Base
{
public:
    // Base has trivial destructor and copy
};

class B : public Base
{
private:
    int *val; ///< Dynamically allocated integer

public:
    /// Destructor: free memory
    ~B()
    {
        delete val;
        val = nullptr;
    }

    /// Constructor: allocate and initialize
    B(int x) : val(new int)
    {
        *val = x;
    }

    /// Copy constructor: deep copy
    B(const B &another) : val(new int)
    {
        *val = *another.val;
    }

    /**
     * @brief Copy assignment operator.
     * @param another Object to copy from.
     * @return Reference to this object.
     *
     * Handles:
     *   - Self-assignment
     *   - Parent class assignment
     *   - Deep copy of pointer
     */
    B &operator=(const B &another)
    {
        if (this == &another)
            return *this; // Self-assignment guard

        Base::operator=(another); // Call parent assignment

        *val = *another.val; // Deep copy
        return *this;
    }

    // Optional: disable assignment
    // B &operator=(const B &) = delete;
};

int main()
{
    B b1(10);
    B b2 = b1; // Copy constructor
    b2 = b1;   // Assignment operator

    return 0;
}