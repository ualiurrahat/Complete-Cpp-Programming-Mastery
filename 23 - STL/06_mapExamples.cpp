/**
 * @file 06_mapExamples.cpp
 * @brief More examples of std::map usage in C++ STL.
 *
 * - map: key(unique) → value, ordered by key (ascending).
 * - multimap: key(not unique) → value.
 *
 * Functions used:
 * - insert(), size(), max_size(), empty()
 * - iteration with iterators
 * - access by key
 */

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    // Map declaration
    map<string, int> marksMap;
    marksMap["Rahat"] = 74;
    marksMap["Nasim"] = 84;
    marksMap["Arfan"] = 88;
    marksMap["Naeem"] = 94;

    // Insertion in map using insert()
    marksMap.insert({{"tofa", 85}, {"shihab", 79}});

    // Iterator for traversal
    map<string, int>::iterator iter;
    for (iter = marksMap.begin(); iter != marksMap.end(); iter++)
    {
        cout << (*iter).first << " " << (*iter).second << endl;
    }

    // Some function usage in map
    cout << "The size is " << marksMap.size() << endl;
    cout << "The max size is " << marksMap.max_size() << endl;
    cout << "The empty's return value is " << marksMap.empty() << endl
         << endl;

    // Another example: couples map
    map<string, string> couple;
    couple["mahbub"] = "amena";
    couple["mamun"] = "jhumi";
    couple["rasel"] = "rupa";

    couple.insert({{"shihab", "nafisa"}, {"adeeb", "jenia"}});

    map<string, string>::iterator i;
    for (i = couple.begin(); i != couple.end(); i++)
    {
        cout << (*i).first << " + " << (*i).second << endl;
    }

    // Access values by key
    cout << couple["rasel"] << endl;

    // Another map: ages
    map<string, int> age;
    age["Alice"] = 23;
    age["Bob"] = 18;
    age["Charlie"] = 28;
    age["Eve"] = 22;

    cout << age["Bob"] << endl; // Output: 18
    cout << age["Eve"] << endl; // Output: 22

    return 0;
}
