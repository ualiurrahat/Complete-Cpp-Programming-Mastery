/**
 * @file 08_EmployeeSortingComparisons.cpp
 * @brief Demonstrates sorting Employee objects using:
 *        1. operator< (member)
 *        2. Functor (function object)
 *        3. Lambda function
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

class Employee
{
public:
    int id;
    int salary;
    string name;

    Employee(int id, int salary, string name) : id(id), salary(salary), name(name) {}

    /**
     * @brief Overloads '<' for lexicographical comparison.
     * @param c2 The other Employee to compare with.
     * @return true if this < c2 based on (id, salary, name)
     *
     * Uses std::tie to compare tuples efficiently.
     */
    bool operator<(const Employee &c2)
    {
        return std::tie(id, salary, name) < std::tie(c2.id, c2.salary, c2.name);
    }

    void print()
    {
        cout << id << " " << name << " " << salary << "\n";
    }
};

// Test 1: Using overloaded operator<
void test1()
{
    vector<Employee> emps;
    emps.push_back({9, 500, "ali"});
    emps.push_back({1, 1000, "mostafa"});
    emps.push_back({5, 700, "hani"});

    sort(emps.begin(), emps.end()); // Uses operator<

    for (auto &emp : emps)
        emp.print();
    // Output: sorted by id, then salary, then name
}

// Functor for sorting by ID
class EmployeeComparatorId
{
public:
    bool operator()(const Employee &c1, const Employee &c2)
    {
        return c1.id < c2.id;
    }
};

// Functor for sorting by Salary
class EmployeeComparatorSalary
{
public:
    bool operator()(const Employee &c1, const Employee &c2)
    {
        return c1.salary < c2.salary;
    }
};

// Test 2: Using functor
void test2()
{
    vector<Employee> emps;
    emps.push_back({9, 500, "ali"});
    emps.push_back({1, 1000, "mostafa"});
    emps.push_back({5, 700, "hani"});

    EmployeeComparatorSalary comparator;
    sort(emps.begin(), emps.end(), comparator);

    for (auto &emp : emps)
        emp.print();
    // Output: sorted by salary
}

// Test 3: Using lambda
void test3()
{
    vector<Employee> emps;
    emps.push_back({9, 500, "ali"});
    emps.push_back({1, 1000, "mostafa"});
    emps.push_back({5, 700, "hani"});

    sort(emps.begin(), emps.end(), [](const Employee &c1, const Employee &c2)
         { return c1.salary < c2.salary; });

    for (auto &emp : emps)
        emp.print();
    // Output: sorted by salary
}

int main()
{
    test3();
    return 0;
}