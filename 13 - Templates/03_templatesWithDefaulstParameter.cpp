// 03_templatesWithDefaultParameter.cpp
// Class templates with default parameters
#include <iostream>
#include <string>

using namespace std;

// Template class with default parameters
// If user doesn't provide type, defaults are int and float
template <class T1 = int, class T2 = float>
class Moho
{
public:
    T1 a;
    T2 b;

    // Constructor
    Moho(T1 x, T2 y)
    {
        a = x;
        b = y;
    }

    // Function to display values
    void display()
    {
        cout << "a = " << a << endl
             << "b = " << b << endl;
    }
};

int main()
{
    // Object using default parameters
    Moho<> ob(25, 8); // <> is empty because using defaults
    ob.display();
    cout << endl;

    // Object using user-defined parameters
    Moho<string, string> ob2("ami", "tumi");
    ob2.display();
    cout << endl;

    Moho<float, char> ob3('c', 'r');
    // 'c' as float: C++ will convert char to its ASCII float value
    ob3.display();

    return 0;
}
