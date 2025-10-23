/**
 * @file 08_structAggregateInit.cpp
 * @brief Explains aggregate, copy, and direct initialization in C++.
 *
 * -------------------- Problem Statement --------------------
 * Demonstrate various initialization techniques:
 * - Aggregate initialization with structs
 * - Copy initialization
 * - Direct initialization
 * - Value initialization
 * -----------------------------------------------------------
 */

#include <iostream>
#include <cmath>
#include <map>
using namespace std;

// ---------------------- Structure Definition ----------------------
struct Employee
{
    int id;      // Uninitialized primitive -> garbage value
    string name; // Automatically calls string constructor -> ""
};

// ---------------------- Main Function ----------------------
int main()
{
    int ff = {}; // value initialization -> 0

    Employee e1;   // Default initialization (garbage for `id`)
    Employee e2(); // Function declaration (NOT object)
    Employee e3{}; // Value initialization -> id = 0, name = ""

    // Temporary (anonymous) object creation
    Employee();
    Employee{};

    Employee e4{10, "Mostafa"};           // Aggregate initialization
    char arr5[]{'h', 'e', 'l', 'l', 'o'}; // Aggregate initialization

    char arr1[] = "hello";   // Copy initialization
    char arr2[] = {"hello"}; // Copy initialization
    char arr3[]{"hello"};    // Direct initialization
    char arr4[]("hello");    // Direct initialization

    int x0;     // Default init -> garbage
    int x1 = 5; // Copy init
    int x2(5);  // Direct init
    int x3{5};  // Direct init

    int y1{}; // value init -> 0
    int y2(); // function declaration, not variable

    double z = 10;
    int z1 = z; // allowed (implicit narrowing)
    int z2{z};  // narrowing warning or error

    return 0;
}
