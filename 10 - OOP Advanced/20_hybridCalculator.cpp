/*
Problem Statement:

Create 2 classes:
    1. SimpleCalculator - Takes input of 2 numbers using a utility function
       and performs +, -, *, / and displays the results using another function.
    2. ScientificCalculator - Takes input of 1 number using a utility function
       and performs any four scientific operations of your choice and displays
       the results using another function.

Create another class HybridCalculator and inherit it using these 2 classes:
    Q1. What type of Inheritance are you using?
        → Multiple Inheritance
    Q2. Which mode of Inheritance are you using?
        → Public Inheritance
    Q3. Create an object of HybridCalculator and display results of both calculators.
    Q4. How is code reusability implemented?
        → By reusing member functions from base classes in the derived class.

@note
Time Complexity: O(1) for each operation
Space Complexity: O(1)
*/

#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief A basic calculator that performs simple arithmetic operations.
 */
class SimpleCalculator
{
protected:
    int a, b;

public:
    /// @brief Takes two integer inputs from the user.
    void userInput1()
    {
        cout << "Enter two numbers: ";
        cin >> a >> b;
    }

    /// @brief Adds two integers.
    int add(int x, int y) { return x + y; }

    /// @brief Subtracts two integers.
    int subtract(int x, int y) { return x - y; }

    /// @brief Multiplies two integers.
    int multiply(int x, int y) { return x * y; }

    /// @brief Divides two integers.
    float division(int x, int y) { return (float)x / y; }

    /// @brief Displays the results of arithmetic operations.
    void display1()
    {
        cout << "Addition: " << add(a, b) << endl;
        cout << "Subtraction: " << subtract(a, b) << endl;
        cout << "Multiplication: " << multiply(a, b) << endl;
        cout << "Division: " << division(a, b) << endl;
    }
};

/**
 * @brief A calculator that performs scientific operations on one number.
 */
class ScientificCalculator
{
protected:
    double num;

public:
    /// @brief Takes one number as input from the user.
    void userInput2()
    {
        cout << "Enter a number: ";
        cin >> num;
    }

    /// @brief Calculates sine of a number.
    double sinValue(double x) { return sin(x); }

    /// @brief Calculates exponential of a number.
    double exponentialValue(double x) { return exp(x); }

    /// @brief Calculates square root of a number.
    double squareRoot(double x) { return sqrt(x); }

    /// @brief Calculates natural logarithm of a number.
    double logValue(double x) { return log(x); }

    /// @brief Displays results of scientific operations.
    void display2()
    {
        cout << "Sine: " << sinValue(num) << endl;
        cout << "Square Root: " << squareRoot(num) << endl;
        cout << "Logarithm: " << logValue(num) << endl;
        cout << "Exponential: " << exponentialValue(num) << endl;
    }
};

/**
 * @brief A hybrid calculator combining both simple and scientific calculators.
 * @note Demonstrates Multiple Inheritance.
 */
class HybridCalculator : public SimpleCalculator, public ScientificCalculator
{
    // Inherits all functionality directly.
};

int main()
{
    cout << "----- Simple Calculator -----" << endl;
    SimpleCalculator sc;
    sc.userInput1();
    sc.display1();

    cout << "\n----- Scientific Calculator -----" << endl;
    ScientificCalculator sci;
    sci.userInput2();
    sci.display2();

    cout << "\n----- Hybrid Calculator -----" << endl;
    HybridCalculator hc;
    hc.userInput1();
    hc.display1();
    hc.userInput2();
    hc.display2();

    return 0;
}
