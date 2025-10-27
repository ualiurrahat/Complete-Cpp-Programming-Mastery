// <DOCUMENT filename="02_VirtualFunctionsIntro.cpp">
#include <iostream>
#include <vector>
using namespace std;

/**
 * @file 02_VirtualFunctionsIntro.cpp
 * @brief Introduces `virtual` → enables **runtime polymorphism**.
 *
 * Key Fix:
 * - `virtual void print()` → vtable lookup at runtime
 * - `Person* p = new Student()` → calls `Student::print()`
 * - **Virtual destructor** prevents memory leaks
 *
 * Intuition:
 * "Call the version that matches the actual object, not the pointer type"
 */

class Person
{
public:
    virtual void print() { cout << "Person\n"; }
    virtual ~Person() { cout << "~Person\n"; } // MUST be virtual!
};

class Student : public Person
{
public:
    void print() override { cout << "Student\n"; }
    ~Student() override { cout << "~Student\n"; }
};

int main()
{
    Person *stud_ptr3 = new Student();
    stud_ptr3->print();         // Student → CORRECT!
    stud_ptr3->Person::print(); // Explicit base call

    delete stud_ptr3; // ~Student then ~Person → SAFE!

    return 0;
}

/*
Output:
Student
Person
~Student
~Person
*/