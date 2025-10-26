/**
 * @file 09_MyNumberBasic.cpp
 * @brief Demonstrates basic class with dynamic memory and default constructor.
 *
 * - `val1` is a pointer to heap-allocated `int`
 * - Constructor allocates memory and initializes both members
 * - Destructor frees the memory (commented out in original — now active)
 * - Shows object creation and assignment (shallow copy danger!)
 *
 * @warning Assignment `b = a` performs **shallow copy** → double delete → crash!
 */

#include <iostream>
#include <vector>
using namespace std;

class MyNumber
{
private:
    int *val1; ///< Pointer to heap-allocated integer
    int val2;  ///< Regular integer member (stored on object)

public:
    /** @brief Parameterized constructor with default arguments. */
    MyNumber(int x = 3, int y = 5)
    {
        cout << "Normal constructor called\n";
        val1 = new int; // Allocate on heap
        *val1 = x;
        val2 = y;
    }

    /** @brief Destructor – frees dynamically allocated memory. */
    ~MyNumber()
    {
        delete val1; // Prevents memory leak
        cout << "Destructor: memory freed for val1\n";
    }

    /** @brief Prints value and memory address of both members. */
    void PrintValueAndAddress() const
    {
        cout << "val1: value=" << *val1 << " address=" << val1 << "\n";
        cout << "val2: value=" << val2 << " address=" << &val2 << "\n\n";
    }
};

int main()
{
    MyNumber a;         // default: (3,5)
    MyNumber b(10, 20); // explicit: (10,20)

    a.PrintValueAndAddress();
    b.PrintValueAndAddress();

    b = a; // DANGER: shallow copy! val1 now points to same memory
    b.PrintValueAndAddress();

    // Program will crash here due to double delete!
    return 0;
}