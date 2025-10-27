/**
 * @file 03_FriendOperatorPlus.cpp
 * @brief Uses 'friend' to allow global operator+ to access private members.
 *
 * Problem with global operator+: Needs access to private data.
 * Solution: Declare operator+ as a **friend** inside the class.
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

    /**
     * @brief Declares global operator+ as a friend.
     *
     * This grants direct access to 'first' and 'second' without getters.
     */
    friend MyPair operator+(const MyPair &c1, const MyPair &c2);
};

/**
 * @brief Friend function: can access private members directly.
 */
MyPair operator+(const MyPair &c1, const MyPair &c2)
{
    return MyPair(c1.first + c2.first, c1.second + c2.second);
}

int main()
{
    MyPair x(1, 2);
    MyPair y(10, 20);

    MyPair z = x + y;
    z.print(); // (11,22)

    return 0;
}