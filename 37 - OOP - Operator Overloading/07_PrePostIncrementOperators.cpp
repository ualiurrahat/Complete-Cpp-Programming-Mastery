/**
 * @file 07_PrePostIncrementOperators.cpp
 * @brief Overloads prefix (++x) and postfix (x++) increment operators.
 *
 * Key Difference:
 *   - Prefix: increment then return reference
 *   - Postfix: return old value, then increment
 *   - Postfix takes 'int' parameter (convention, not used)
 */

#include <iostream>
#include <vector>
using namespace std;

class MyPair
{
private:
    int first, second;

public:
    MyPair(int first, int second) : first(first), second(second) {}

    void print()
    {
        cout << "(" << first << "," << second << ")\n";
    }

    int GetFirst() const { return first; }
    void SetFirst(int first) { this->first = first; }
    int GetSecond() const { return second; }
    void SetSecond(int second) { this->second = second; }

    /**
     * @brief Prefix increment: ++x
     * @return Reference to the modified object.
     *
     * Flow:
     *   1. Increment both values
     *   2. Return *this (modified)
     */
    MyPair &operator++()
    {
        ++first, ++second;
        return *this;
    }

    /**
     * @brief Postfix increment: x++
     * @param int Dummy parameter to distinguish from prefix.
     * @return Copy of the object **before** increment.
     *
     * Flow:
     *   1. Save current state (copy)
     *   2. Increment object
     *   3. Return the saved copy
     */
    MyPair operator++(int)
    {
        MyPair cpy = *this; // Save old value
        ++first, ++second;  // Increment
        return cpy;         // Return old value
    }
};

int main()
{
    MyPair x1(1, 2);
    (++x1).print(); // (2,3) → incremented immediately

    MyPair x2(1, 2);
    x2++.print(); // (1,2) → prints old value
    x2.print();   // (2,3) → now incremented

    return 0;
}