/**
 * @problem_statement
 * Create a simple employee management system with options to add, print, delete, and update employee records.
 */

#include <iostream>
using namespace std;

// -------------------------- Global variables --------------------------
const int MAX = 10000;
string names[MAX];
int ages[MAX];
double salaries[MAX];
char genders[MAX];
int added = 0; // Number of employees

/**
 * @brief Displays the main menu and reads the user's choice.
 * @return int The selected menu option.
 */
int menu()
{
    int choice = -1;
    while (choice == -1)
    {
        cout << "\nEnter your choice:\n";
        cout << "1) Add new employee\n";
        cout << "2) Print all employees\n";
        cout << "3) Delete by age\n";
        cout << "4) Update Salary by name\n";
        cout << "5) Exit\n";
        cin >> choice;

        if (!(1 <= choice && choice <= 5))
        {
            cout << "Invalid choice. Try again.\n";
            choice = -1;
        }
    }
    return choice;
}

/**
 * @brief Reads and stores a new employee's details.
 */
void read_employee()
{
    cout << "Enter name: ";
    cin >> names[added];
    cout << "Enter age: ";
    cin >> ages[added];
    cout << "Enter salary: ";
    cin >> salaries[added];
    cout << "Enter gender (M/F): ";
    cin >> genders[added];
    ++added;
}

/**
 * @brief Prints all employee records that are not deleted.
 */
void print_employees()
{
    cout << "****************************\n";
    for (int i = 0; i < added; ++i)
        if (ages[i] != -1)
            cout << names[i] << " " << ages[i] << " " << salaries[i] << " " << genders[i] << "\n";
}

/**
 * @brief Deletes employees whose age falls in a given range.
 */
void delete_by_age()
{
    cout << "Enter start and end age: ";
    int start, end;
    cin >> start >> end;

    for (int i = 0; i < added; ++i)
        if (start <= ages[i] && ages[i] <= end)
            ages[i] = -1; // Lazy delete
}

/**
 * @brief Updates the salary of an employee identified by name.
 */
void update_salary_by_name()
{
    cout << "Enter the name and salary: ";
    string name;
    int salary;
    cin >> name >> salary;

    bool is_found = false;
    for (int i = 0; i < added; ++i)
        if (ages[i] != -1 && names[i] == name)
        {
            is_found = true;
            salaries[i] = salary;
            break;
        }

    if (!is_found)
        cout << "No employee with this name!\n";
}

/**
 * @brief Controls the flow of the entire employee system.
 */
void employee_system()
{
    while (true)
    {
        int choice = menu();
        if (choice == 1)
            read_employee();
        else if (choice == 2)
            print_employees();
        else if (choice == 3)
            delete_by_age();
        else if (choice == 4)
            update_salary_by_name();
        else
            break;
    }
}

int main()
{
    employee_system();
    return 0;
}
