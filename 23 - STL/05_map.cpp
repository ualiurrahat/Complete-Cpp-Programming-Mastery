/**
 * @file 05_map.cpp
 * @brief Demonstration of std::map in C++ STL with display function and key existence check.
 *
 * - Vectors → Sequence containers (like arrays but dynamic).
 * - Pairs   → Store two heterogeneous objects.
 * - Maps    → Associative container storing key–value pairs (keys unique).
 * - Iterators → Point to container elements, used for traversal (begin() to end()).
 *
 * Use case:
 * - Need an ordered sequence? Use vector.
 * - Need key–value association with efficient lookup? Use map.
 */

#include <iostream>
#include <map>
#include <string>
using namespace std;

/**
 * @brief Display all key–value pairs in a map.
 * @param m Reference to the map<string,int>
 *
 * @note Time complexity: O(n)
 * @note Space complexity: O(1)
 */
void display(map<string, int> &m)
{
    map<string, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        cout << (*iter).first << " -- " << (*iter).second << endl;
    }
    cout << endl;
}

int main()
{
    map<string, int> age;
    age["ahnaf"] = 5;
    age["arwa"] = 3;
    age["ayash"] = 1;
    age["arisha"] = 2;
    age["ayaan"] = 11;

    display(age);

    // Behavior: accessing a non-existent key inserts it with default value (0 for int).
    cout << age["thisWasNotInserted"] << endl;

    // Now key "thisWasNotInserted" exists with value 0.
    display(age);

    // Checking key existence using find()
    if (age.find("rahat") != age.end())
    {
        cout << "rahat's age found" << endl;
    }
    else
    {
        cout << "rahat does not exist" << endl;
    }

    // Deleting a key-value pair using erase()
    age.erase("thisWasNotInserted");
    display(age);

    return 0;
}
