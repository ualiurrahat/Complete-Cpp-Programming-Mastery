/**
 * @file 08_pair.cpp
 * @brief Introduction to std::pair in C++ STL.
 *
 * std::pair holds two values (possibly of different data types).
 * - Accessed using .first and .second
 * - Can be compared using relational operators (==, !=, <, >)
 */

#include <iostream>
#include <utility> // for pair
using namespace std;

int main()
{
    // Pair declaration
    pair<int, int> p1;
    p1 = {25, 8};

    // Pair declaration with initialization
    pair<int, int> p2 = {3, 9};
    pair<float, float> p3 = {1.8, 2.7};

    // Pair assigned as copy of another
    pair<int, int> p = p1;

    // Pair initialization with make_pair()
    pair<float, float> p4 = make_pair(25.7f, 8.25f);

    // Displaying pairs
    cout << "pair p1: " << p1.first << " " << p1.second << endl;
    cout << "pair p: " << p.first << " " << p.second << endl;
    cout << "pair p2: " << p2.first << " " << p2.second << endl;
    cout << "pair p3: " << p3.first << " " << p3.second << endl;
    cout << "pair p4: " << p4.first << " " << p4.second << endl;

    // Pair array
    pair<int, int> p5[4];

    // Input into pair array
    for (int i = 0; i < 4; i++)
    {
        cout << "Insert pair " << i + 1 << " elements: ";
        cin >> p5[i].first >> p5[i].second;
    }

    // Displaying pair array
    for (int i = 0; i < 4; i++)
    {
        cout << "Pair " << i + 1 << ": " << p5[i].first << " " << p5[i].second << endl;
    }

    // Operations on pairs
    cout << endl
         << "Comparing p and p1: ";
    if (p == p1)
        cout << "Equal\n";
    else
        cout << "Not equal\n";

    cout << "Comparing p1 and p2: ";
    if (p1 == p2)
        cout << "Equal\n";
    else
        cout << "Not equal\n";

    cout << endl
         << "Comparing p1 and p2 again (>): ";
    if (p1 > p2)
        cout << "p1 is greater\n";
    else
        cout << "p2 is greater\n";

    cout << endl
         << "Comparing p3 and p4 again (>): ";
    if (p3 > p4)
        cout << "p3 is greater\n";
    else
        cout << "p4 is greater\n";

    return 0;
}
