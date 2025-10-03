/**
 * @file 12_setExamples.cpp
 * @brief Example of set with user-defined data types.
 *
 * Notes:
 * - We need to provide a comparison function to store objects in sorted order.
 */

#include <iostream>
#include <string>
#include <set>
using namespace std;

class Person
{
public:
    int age;
    string name;
};

int main()
{
    // Example (will not compile without comparator):
    set<Person> people = {{22, "rahat"}, {25, "kabir"}, {32, "aslam"}};
    return 0;
}
