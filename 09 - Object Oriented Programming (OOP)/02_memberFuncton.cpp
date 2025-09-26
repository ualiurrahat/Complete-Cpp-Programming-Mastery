/**
 * @file 02_memberFunction.cpp
 * @brief Demonstrates Nesting of Member Functions in C++.
 *
 * Nesting of Member Functions:
 * -----------------------------
 * - If one member function is called inside another member function of the same class,
 *   it is called *nesting of member functions*.
 * - This improves encapsulation since helper functions can be called internally,
 *   reducing direct calls in `main()`.
 *
 * Example:
 * - Class Binary validates whether a string is binary.
 * - Uses a nested call: `ones_complement()` calls `check_binary()`.
 */

#include <iostream>
#include <string>
using namespace std;

class Binary
{
    string s; ///< Binary string input from user

public:
    /// Reads a binary string from user input
    void read();

    /// Checks whether the string is valid binary (only 0s and 1s)
    void check_binary();

    /// Converts the binary string into its one's complement
    void ones_complement();

    /// Displays the current string
    void display();
};

// Function to read a binary number
void Binary::read()
{
    cout << "Enter a binary number: ";
    cin >> s;
}

// Function to check if number is in binary format
void Binary::check_binary()
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrect binary format!" << endl;
            exit(0); // Exit program if invalid input
        }
    }
}

// Function to generate one's complement of binary number
void Binary::ones_complement()
{
    check_binary(); // Nested function call
    for (int i = 0; i < s.length(); i++)
    {
        s.at(i) = (s.at(i) == '0') ? '1' : '0';
    }
}

// Function to display the binary number
void Binary::display()
{
    cout << "Binary number: " << s << endl;
}

int main()
{
    Binary b; // Create object of Binary class
    b.read(); // Input binary number

    b.display();         // Show original
    b.ones_complement(); // Convert to one's complement
    b.display();         // Show modified

    return 0;
}
