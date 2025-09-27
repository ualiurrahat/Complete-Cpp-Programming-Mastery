/**
 * @file 18_multiLevelInheritance.cpp
 * @brief Demonstrates Multilevel Inheritance in C++.
 *
 * @details
 * Multilevel inheritance occurs when:
 * - Class B is derived from Class A.
 * - Class C is derived from Class B.
 * This forms an inheritance path A → B → C.
 *
 * Example: Student → Exam → Result
 */

#include <iostream>
#include <string>
using namespace std;

// ---------------------- Base Class: Student ----------------------
class Student
{
private:
    int roll_number; ///< Roll number is private; accessed via public functions.

public:
    void set_roll_number(int num) { roll_number = num; }
    void get_roll_number() { cout << "Your roll number is " << roll_number << endl; }
};

// ---------------------- Derived Class: Exam ----------------------
class Exam : public Student
{
protected:
    float math;    ///< Marks in Mathematics
    float physics; ///< Marks in Physics

public:
    void set_marks(float m, float p)
    {
        math = m;
        physics = p;
    }
    void get_marks()
    {
        cout << "Marks in math are: " << math << endl;
        cout << "Marks in physics are: " << physics << endl;
    }
};

// ---------------------- Derived Class: Result ----------------------
class Result : public Exam
{
public:
    void display()
    {
        get_roll_number(); // from Student
        get_marks();       // from Exam
        cout << "Your percentage is " << (math + physics) / 2.0 << "%" << endl;
    }
};

// ---------------------- Main Function ----------------------
int main()
{
    Result rahat;

    // Step 1: Assign roll number (from Student class).
    rahat.set_roll_number(39);

    // Step 2: Assign subject marks (from Exam class).
    rahat.set_marks(74, 98);

    // Step 3: Display overall result (from Result class).
    rahat.display();

    return 0;
}
