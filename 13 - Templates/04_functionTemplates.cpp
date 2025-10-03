// 04_functionTemplates.cpp
// Templates and function templates with parameters

#include <iostream>
#include <string>

using namespace std;

// ---------------------- Function Template to Find Average ----------------------
template <class T1, class T2>
float findAverage(T1 a, T2 b)
{
    float avg = (a + b) / 2.0;
    return avg;
}

// ---------------------- Function Template to Swap ----------------------
template <class T>
void swapp(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// ---------------------- Main Function ----------------------
int main()
{
    // Using template function to find average
    float a = findAverage(5, 2.4);
    cout << "The average is " << a << endl;

    // Using template function to swap two numbers
    int x = 25, y = 8;
    swapp(x, y);
    cout << "Swapped values: " << x << " " << y << endl;

    return 0;
}
