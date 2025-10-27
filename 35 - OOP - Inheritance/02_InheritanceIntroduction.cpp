// <DOCUMENT filename="02_InheritanceIntroduction.cpp">
#include <iostream>
#include <string>
using namespace std;

/**
 * @file 02_InheritanceIntroduction.cpp
 * @brief Demonstrates basic inheritance: Student IS-A Person.
 *
 * Key Concepts:
 * - Inheritance allows code reuse
 * - Derived class (Student) gains access to base class (Person) members
 * - Base class can be used independently
 *
 * Intuition:
 * Every student is a person → share name/email logic.
 * But not every person is a student → Person shouldn't have GPA.
 */

class Person
{
public:
    string name = "Mostafa";     ///< Default name for demo
    string email = "most@gmail"; ///< Default email

    /**
     * @brief Placeholder email validator.
     *
     * In real system: check '@', domain, length, etc.
     *
     * @return true (always for demo)
     */
    bool IsValidEmailFormat()
    {
        return true;
    }
};

class Student : public Person
{
private:
    double GPA = 0.0; ///< Student's academic performance

public:
    /**
     * @brief Prints student's name and GPA.
     *
     * Uses inherited `name` from Person.
     * Demonstrates how derived class accesses base members.
     */
    void PrintGrades()
    {
        cout << name << " GPA=" << GPA << "\n";
    }

    /**
     * @brief Sets the student's GPA.
     *
     * @param gpa New GPA value (0.0 - 4.0 typically)
     */
    void SetGpa(double gpa)
    {
        GPA = gpa;
    }
};

int main()
{
    Student student;

    // --- DEMO: Student IS-A Person ---
    student.SetGpa(3.5);          // Set student-specific data
    student.IsValidEmailFormat(); // Inherited from Person
    student.PrintGrades();        // Uses inherited 'name'

    // Output: Mostafa GPA=3.5

    // --- DEMO: Person is NOT necessarily a Student ---
    Person person;
    person.IsValidEmailFormat(); // Works fine
    // person.PrintGrades(); // COMPILER ERROR: Person has no such method
    // person.SetGpa(4.0);   // COMPILER ERROR: Not available

    return 0;
}