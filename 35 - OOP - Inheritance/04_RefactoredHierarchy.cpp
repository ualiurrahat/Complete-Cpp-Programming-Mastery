// <DOCUMENT filename="04_RefactoredHierarchy.cpp">
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @file 04_RefactoredHierarchy.cpp
 * @brief Final refactored design using proper inheritance.
 *
 * Achievements:
 * - Eliminated code duplication
 * - Common attributes in `Person`
 * - Specific behavior in `Student` and `Teacher`
 * - Encapsulation via setters
 *
 * Design Pattern: **Inheritance with Composition-ready structure**
 */

class Person
{
protected:
    string name;       ///< Full name
    string email;      ///< Contact email
    string address;    ///< Physical address
    string natioal_id; ///< National ID (typo preserved)

public:
    /**
     * @brief Validates email format (stub).
     * @return true always in demo
     */
    bool IsValidEmailFormat() { return true; }

    /**
     * @brief Safely sets the person's name.
     *
     * @param name New name (passed by const ref for efficiency)
     */
    void SetName(const string &name)
    {
        this->name = name;
    }
};

class Student : public Person
{
private:
    int starting_study_year = 0; ///< Enrollment year
    double GPA = 0.0;            ///< Academic average
    vector<int> studied_courses; ///< Courses completed

public:
    /**
     * @brief Records a course and its grade.
     *
     * @param course_id Unique course identifier
     * @param grade Obtained grade
     *
     * Future: store pair<course_id, grade> in vector
     */
    void AddCourseGrade(int course_id, double grade)
    {
        // Placeholder: will push to studied_courses + grade map
    }

    /**
     * @brief Prints name and GPA using inherited data.
     */
    void PrintGrades()
    {
        cout << name << " " << GPA << "\n";
    }

    /**
     * @brief Sets GPA with validation (future).
     *
     * @param gpa New GPA
     */
    void SetGpa(double gpa)
    {
        GPA = gpa;
    }
};

class Teacher : public Person
{
private:
    int starting_employement_year = 0; ///< Year hired
    double current_salary = 0.0;       ///< Current pay
    vector<int> teaching_courses;      ///< Courses assigned

public:
    /**
     * @brief Assigns a course to teach.
     *
     * @param course_id Course to add
     */
    void AddCourse(int course_id)
    {
        teaching_courses.push_back(course_id);
    }

    /**
     * @brief Updates teacher's salary.
     *
     * @param currentSalary New salary amount
     */
    void SetCurrentSalary(double currentSalary)
    {
        current_salary = currentSalary;
    }
};

int main()
{
    Student student;
    student.SetName("Ali Ahmed"); // Inherited setter
    student.SetGpa(3.5);
    student.PrintGrades(); // Output: Ali Ahmed 3.5

    Teacher teacher;
    teacher.SetName("Dr. Sara");
    teacher.SetCurrentSalary(5000.0);
    teacher.AddCourse(101);

    return 0;
}