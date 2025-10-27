// <DOCUMENT filename="03_ProtectedAccessDemo.cpp">
#include <iostream>
#include <string>
using namespace std;

/**
 * @file 03_ProtectedAccessDemo.cpp
 * @brief Shows the role of `protected` members in inheritance.
 *
 * Key Points:
 * - `private`: Only current class
 * - `protected`: Current class + derived classes
 * - `public`: Everyone
 *
 * Intuition:
 * We want derived classes (Student, Teacher) to access `name`, `email`
 * But outsiders should NOT modify them directly.
 */

class Person
{
protected:
    // Accessible in derived classes, but hidden from main()
    string name = "Mostafa";     ///< Protected: inherited but not public
    string email = "most@gmail"; ///< Protected: safe from external access

public:
    /**
     * @brief Email format checker (inherited by children).
     *
     * @return true (demo version)
     */
    bool IsValidEmailFormat()
    {
        return true;
    }
};

class Student : public Person
{
private:
    double GPA = 0.0; ///< Private to Student only

public:
    /**
     * @brief Displays name (from Person) and GPA.
     *
     * Proves that `name` is accessible inside derived class.
     */
    void PrintGrades()
    {
        // name is protected → visible here!
        cout << name << " GPA=" << GPA << "\n";
    }

    /**
     * @brief Updates student's GPA.
     *
     * @param gpa New grade point average
     */
    void SetGpa(double gpa)
    {
        GPA = gpa;
    }
};

int main()
{
    Student student;

    student.SetGpa(3.5);
    student.IsValidEmailFormat(); // Public method from base
    student.PrintGrades();        // Uses protected `name`

    Person person;
    // person.name;    // ERROR: 'name' is protected
    // person.email;   // ERROR: Not accessible outside
    person.IsValidEmailFormat(); // OK: public method

    return 0;
}