// <DOCUMENT filename="01_NonPolymorphicBehavior.cpp">
#include <iostream>
#include <vector>
using namespace std;

/**
 * @file 01_NonPolymorphicBehavior.cpp
 * @brief Demonstrates the PROBLEM: No polymorphism without `virtual`.
 *
 * Key Issue:
 * - Calling `print()` via `Person*` pointing to `Student` → calls `Person::print()`
 * - This is **static binding** (compile-time)
 * - Leads to **incorrect behavior** and **memory leaks** on delete
 *
 * Intuition:
 * We want "treat Student as Person, but behave like Student"
 * → Requires **dynamic binding** via `virtual`
 */

class Person
{
public:
    /** @brief Non-virtual: always calls Person version */
    void print() { cout << "Person\n"; }
    ~Person() { cout << "~Person\n"; }
};

class Student : public Person
{
public:
    void print() { cout << "Student\n"; }
    ~Student() { cout << "~Student\n"; }
};

int main()
{
    Person person;
    Student stud;

    person.print(); // Person
    stud.print();   // Student

    // --- Pointers: No polymorphism ---
    Person *per_ptr = &person;
    Student *stud_ptr1 = &stud;
    Person *stud_ptr2 = &stud;
    Person *stud_ptr3 = new Student(); // 3rd object

    per_ptr->print();   // Person
    stud_ptr1->print(); // Student
    stud_ptr2->print(); // Person → WRONG! Should be Student
    stud_ptr3->print(); // Person → WRONG!

    delete stud_ptr3; // MEMORY LEAK: ~Student never called!
    // Only ~Person runs → undefined behavior

    return 0;
}
/*
Output:
Person
Student
Person
Student
Person
Person
~Person        ← from new Student() → LEAK!
~Student       ← from stud
~Person        ← from stud
~Person        ← from person
*/