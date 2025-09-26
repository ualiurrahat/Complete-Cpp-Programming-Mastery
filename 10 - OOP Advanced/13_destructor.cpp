/**
 * @file 13_destructor.cpp
 * @brief Demonstrates the concept of a Destructor in C++.
 *
 * A destructor is a special member function that is called automatically
 * when an object goes out of scope. It never takes parameters or returns values.
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @class Num
 * @brief Demonstrates constructor and destructor behavior with static counter.
 */
class Num
{
public:
    static int count; ///< Static counter to track number of objects

    /// Constructor increments count
    Num()
    {
        count++;
        cout << "Constructor was called for object no: " << count << endl;
    }

    /// Destructor decrements count
    ~Num()
    {
        cout << "Destructor was called for object no: " << count << endl;
        count--;
    }
};

// Initialize static variable
int Num::count = 0;

// ------------------------------- Main -------------------------------
int main()
{
    cout << "We are inside main function." << endl;

    cout << "Creating object n1: " << endl;
    Num n1; // Constructor called here

    {
        cout << "Entering this block" << endl;
        cout << "Creating two more objects." << endl;

        Num n2, n3; // Constructors for n2 and n3
        cout << "Exiting this block" << endl;
    }
    // Destructors for n3 and n2 are automatically called here (end of block scope)

    cout << "Back to main function." << endl;
    // Destructor for n1 will be called at the end of main()

    return 0;
}
