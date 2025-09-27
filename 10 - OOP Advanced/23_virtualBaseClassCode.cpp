/*
Problem Statement:

Demonstrate Virtual Base Class in C++.

- Create a "Student" base class with roll number.
- Create a "Test" class (derived from Student) containing marks in Maths and Physics.
- Create a "Sports" class (derived from Student) containing a sports score.
- Create a "Result" class (derived from Test and Sports) which calculates
  and displays the total marks.

Key Point:
    - "Student" should be inherited as a virtual base class by "Test" and "Sports"
      to avoid ambiguity of multiple inheritance.

@note
Time Complexity: O(1) for function calls
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

/**
 * @brief Base class containing roll number.
 */
class Student
{
protected:
    int roll_number;

public:
    /// @brief Sets the student's roll number.
    void set_number(int a) { roll_number = a; }

    /// @brief Prints the student's roll number.
    void print_number()
    {
        cout << "Your roll number is " << roll_number << endl;
    }
};

/**
 * @brief Derived class representing marks in subjects.
 * @note Inherits Student as a virtual base class.
 */
class Test : public virtual Student
{
protected:
    float maths, physics;

public:
    void set_marks(float x, float y)
    {
        maths = x;
        physics = y;
    }

    void print_marks()
    {
        cout << "Your marks are:" << endl;
        cout << "Maths: " << maths << endl;
        cout << "Physics: " << physics << endl;
    }
};

/**
 * @brief Derived class representing sports performance.
 * @note Inherits Student as a virtual base class.
 */
class Sports : public virtual Student
{
protected:
    float score;

public:
    void set_score(float m) { score = m; }

    void print_score()
    {
        cout << "Your sports score: " << score << endl;
    }
};

/**
 * @brief Result class derived from both Test and Sports.
 * @note Demonstrates resolution of ambiguity by using virtual base classes.
 */
class Result : public Test, public Sports
{
private:
    float total;

public:
    /// @brief Displays the complete result (roll number, marks, sports score, and total).
    void display()
    {
        total = maths + physics + score;
        print_number();
        print_marks();
        print_score();
        cout << "Your total mark is: " << total << endl;
    }
};

int main()
{
    Result rahat;
    rahat.set_number(35);
    rahat.set_marks(98, 73.5);
    rahat.set_score(6);

    cout << "----- Student Result -----" << endl;
    rahat.display();

    return 0;
}
