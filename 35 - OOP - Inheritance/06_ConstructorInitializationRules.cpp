// <DOCUMENT filename="06_ConstructorInitializationRules.cpp">
#include <iostream>
#include <string>
using namespace std;

/**
 * @file 06_ConstructorInitializationRules.cpp
 * @brief Shows constructor/destructor order and member initialization rules.
 *
 * Key Rules:
 * 1. Base class constructor runs BEFORE derived
 * 2. Member initializer list is the ONLY place to initialize base class
 * 3. You cannot call base constructor inside derived body
 * 4. Destructors run in reverse order
 *
 * Common Mistake: Trying to initialize base members in derived body → too late!
 */

class Person
{
protected:
    string name; ///< Protected: accessible in derived classes

public:
    /** @brief Default constructor */
    Person() : name("most")
    {
        cout << "Person Default Constructor\n";
    }

    /** @brief Parameterized constructor */
    Person(string name) : name(name)
    {
        cout << "Person 2nd Constructor\n";
    }

    /** @brief Destructor */
    ~Person()
    {
        cout << "Person Destructor\n";
    }
};

class Student : public Person
{
private:
    double gpa; ///< Student's GPA

public:
    /**
     * @brief Default constructor for Student.
     *
     * Note: `name = "hani"` is allowed here because `name` is protected.
     * But this is BAD practice — base should control its own data.
     */
    Student()
    {
        cout << "Student Default Constructor\n";
        gpa = 0;
        name = "hani"; // OK, but not ideal — base already set name!
    }

    /**
     * @brief Constructor with GPA.
     *
     * Uses member initializer list to:
     * - Call Person(string) → sets name = "Ali"
     * - Initialize gpa
     */
    Student(double gpa) : Person("Ali"), gpa(gpa)
    {
        cout << "Student 2nd Constructor\n";
    }

    ~Student()
    {
        cout << "Student Destructor\n";
    }
};

int main()
{
    cout << "=== Creating student1 (default) ===\n";
    Student student1;
    // Output order:
    // Person Default Constructor
    // Student Default Constructor
    // Student Destructor
    // Person Destructor

    cout << "\n=== Creating student2(3.0) ===\n";
    Student student2(3.0);
    // Output:
    // Person 2nd Constructor
    // Student 2nd Constructor
    // Student Destructor
    // Person Destructor

    return 0;
}