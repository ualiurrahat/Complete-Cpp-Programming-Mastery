// 02_templatesWithMultipleParameters.cpp
// Class templates with multiple parameters
#include <iostream>
#include <string>

using namespace std;

/*
CLASS TEMPLATE WITH MULTIPLE PARAMETERS:
template <class T1, class T2, ...>
{
    // code
}
*/

template <class T1, class T2>
class MyClass
{
public:
    T1 data1;
    T2 data2;

    // Constructor
    MyClass(T1 a, T2 b)
    {
        data1 = a;
        data2 = b;
    }

    // Function to display both data members
    void display()
    {
        cout << data1 << endl;
        cout << data2 << endl;
    }
};

int main()
{
    MyClass<int, char> obj(8, 't');
    obj.display();

    MyClass<int, int> obj2(25, 8);
    obj2.display();

    MyClass<string, string> obj3("muhit", "moho");
    obj3.display();

    return 0;
}
