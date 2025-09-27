/*
Problem Statement:

Initialization Lists in C++ Constructors

- The initialization list allows data members to be initialized before the constructor body runs.
- Syntax:
    Constructor(arguments) : member1(val1), member2(val2) {
        // constructor body
    }

Key Points:
1. Members are initialized in the order they are declared in the class,
   not in the order they appear in the initialization list.
2. If a member depends on another, initialize carefully.
3. Initialization lists are more efficient for const or reference members
   since they cannot be reassigned inside the constructor body.

Example Problem:
    Demonstrate different ways of using initialization lists
    and explain why declaration order matters.

@note
Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

/**
 * @brief Class demonstrating initialization lists.
 */
class Test
{
    int a; ///< Declared first, so always initialized before b
    int b;

public:
    /**
     * @brief Constructor demonstrating initialization lists.
     * @param i value for 'a'
     * @param j value for 'b'
     */
    Test(int i, int j) : a(i), b(j)
    {
        cout << "Constructor executed." << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }

    // Other valid examples (uncomment to test):
    // Test(int i, int j) : a(i), b(i+j) {}
    // Test(int i, int j) : a(i), b(a+j) {}
    // Test(int i, int j) : a(i), b(j*2) {}
    // Test(int i, int j) : a(i), b(j+1) {}
};

int main()
{
    // Create object with initialization list
    Test t(25, 8);

    return 0;
}
