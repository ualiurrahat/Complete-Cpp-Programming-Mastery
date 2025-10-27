/**
 * @file 01_BasicMemberOperatorPlus.cpp
 * @brief Demonstrates operator overloading using a member function for addition.
 *
 * This example shows how to overload the '+' operator as a **member function**.
 * The left operand becomes '*this', and the right operand is passed as a parameter.
 *
 * Intuition:
 *   - x + y → x.operator+(y)
 *   - The object on the left (x) calls the operator function.
 *   - This is the most natural way when one operand is of the class type.
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @class MyPair
 * @brief Represents a 2D point or pair of integers (first, second).
 */
class MyPair
{
private:
    int first;  ///< First coordinate/value
    int second; ///< Second coordinate/value

public:
    /**
     * @brief Constructor to initialize the pair.
     * @param first Initial value for the first element.
     * @param second Initial value for the second element.
     */
    MyPair(int first, int second) : first(first), second(second) {}

    /**
     * @brief Member function to add another MyPair (legacy style).
     * @param c2 The MyPair to add to the current object.
     * @return A new MyPair containing the sum.
     *
     * Note: This is kept for comparison but will be replaced by operator+.
     */
    MyPair Add(const MyPair &c2)
    {
        MyPair &c1 = *this;
        return MyPair(c1.GetFirst() + c2.GetFirst(), c1.GetSecond() + c2.GetSecond());
    }

    /**
     * @brief Overloads the '+' operator as a **member function**.
     * @param c2 The right-hand operand (MyPair to add).
     * @return A new MyPair with summed components.
     *
     * Flow:
     *   1. Access current object via '*this'
     *   2. Get values from both objects
     *   3. Return new object with sum
     */
    MyPair operator+(const MyPair &c2)
    {
        MyPair &c1 = *this;
        return MyPair(c1.GetFirst() + c2.GetFirst(), c1.GetSecond() + c2.GetSecond());
    }

    /**
     * @brief Prints the pair in format (first,second).
     */
    void print()
    {
        cout << "(" << first << "," << second << ")\n";
    }

    // Getter and Setter methods (const-correct)
    int GetFirst() const { return first; }
    void SetFirst(int first) { this->first = first; }
    int GetSecond() const { return second; }
    void SetSecond(int second) { this->second = second; }
};

int main()
{
    MyPair x(1, 2);
    MyPair y(10, 20);

    // Using member operator+: x + y calls x.operator+(y)
    MyPair z = x + y;
    z.print(); // Output: (11,22)

    return 0;
}