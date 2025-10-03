// 05_templateFunctionOverloading.cpp
// Overloading template function

#include <iostream>
#include <string>

using namespace std;

// ---------------------- Template Class ----------------------
template <class T>
class Rahat
{
public:
    T data;

    Rahat(T a)
    {
        data = a;
    }

    void display();
};

// Defining display function outside template class
template <class T>
void Rahat<T>::display()
{
    cout << data << endl;
}

// ---------------------- Function Overloading ----------------------
void func(int a)
{
    cout << "I am func() exact int match: " << a << endl;
}

template <class T>
void func(T a)
{
    cout << "I am templated func(): " << a << endl;
}

// Another template function
template <class T>
void func1(T a)
{
    cout << "I am templated func1(): " << a << endl;
}

// ---------------------- Main Function ----------------------
int main()
{
    Rahat<int> i(25);
    cout << i.data << endl;
    i.display();

    // Testing template function overloading
    func(4);    // exact match with func(int a)
    func(4.2);  // calls template func()
    func1(4.2); // calls template func1()

    return 0;
}
