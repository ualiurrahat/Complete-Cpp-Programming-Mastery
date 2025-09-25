/**
 * @file 03_inlineFunction.cpp
 * @brief Demonstrates inline functions and behavior with static variables.
 */

#include <iostream>
using namespace std;

/**
 * @brief Inline function for summing two integers.
 * @note Inline functions are recommended for small, simple functions.
 */
inline int sum(int a, int b)
{
    return a + b;
}

/**
 * @brief Function that multiplies two numbers and uses a static variable.
 * @note Static variable retains its value between function calls.
 */
int prod(int a, int b)
{
    static int c = 0; // Executes only once, then retains value across calls.
    c = c + 1;
    return a * b + c;
}

/**
 * @brief Inline version of the same product function.
 * @note Inline with static variables is NOT recommended.
 */
inline int INLINEprod(int a, int b)
{
    static int c = 0;
    c = c + 1;
    return a * b + c;
}

int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Inline Sum Calls:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << sum(a, b) << endl;
    }
    cout << endl;

    cout << "Product (with static variable):\n";
    for (int i = 0; i < 5; i++)
    {
        cout << prod(a, b) << endl;
    }
    cout << endl;

    cout << "Inline Product (with static variable) [Not recommended]:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << INLINEprod(a, b) << endl;
    }

    return 0;
}
