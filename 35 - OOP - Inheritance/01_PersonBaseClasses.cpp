// <DOCUMENT filename="01_PersonBaseClasses.cpp">
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @file 01_PersonBaseClasses.cpp
 * @brief Defines foundational Person-like classes (Student and Teacher) with common attributes.
 *
 * This file introduces the concept of shared data members (name, email, etc.)
 * that will later be refactored into a common base class using inheritance.
 *
 * Intuition: Both students and teachers have personal information and email validation.
 * Instead of duplicating code, we will extract common parts into a `Person` base class.
 *
 * Current state: Duplicated attributes and email validation logic.
 */

class Student
{
private:
    string name;       ///< Student's full name
    string email;      ///< Student's email address
    string address;    ///< Home address
    string natioal_id; ///< National ID (note: typo in original)

    int starting_study_year;     ///< Year the student began studies
    double GPA;                  ///< Current Grade Point Average
    vector<int> studied_courses; ///< List of course IDs the student has taken

public:
    /**
     * @brief Checks if the email follows a valid format.
     *
     * Currently a placeholder. In future versions, this will validate:
     * - Presence of '@'
     * - Domain after '@'
     * - No invalid characters
     *
     * @return true if format is valid, false otherwise
     */
    bool IsValidEmailFormat();

    /**
     * @brief Records a grade for a specific course.
     *
     * @param course_id Unique identifier for the course
     * @param grade Numerical grade (e.g., 3.7)
     */
    void AddCourseGrade(int course_id, double grade);

    /**
     * @brief Prints all grades for the student.
     *
     * Output format: "CourseID: Grade"
     */
    void PrintGrades();
};

class Teacher
{
private:
    string name;       ///< Teacher's full name
    string email;      ///< Teacher's email address
    string address;    ///< Home or office address
    string natioal_id; ///< National ID (typo preserved from original)

    int starting_employement_year; ///< Year employment began
    double current_salary;         ///< Current monthly/yearly salary
    vector<int> teaching_courses;  ///< List of course IDs currently teaching

public:
    /**
     * @brief Validates teacher's email format.
     *
     * Identical logic to Student's version — duplication to be removed via inheritance.
     *
     * @return true if valid format
     */
    bool IsValidEmailFormat();

    /**
     * @brief Assigns a course to the teacher for teaching.
     *
     * @param course_id ID of the course to teach
     */
    void AddCourse(int course_id);
};

/* Function implementations are intentionally empty in this version
   to focus on class design and future refactoring using inheritance. */

int main()
{
    // No execution yet — this file defines structure only.
    return 0;
}