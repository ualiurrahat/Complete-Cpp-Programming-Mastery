#include <iostream>
#include <cmath>
using namespace std;

// A parameter is the variable which is part of  declaration
// a, b are parameters. 10 is default argument for b
void print(int a, int b = 10)
{
    cout << a << " " << b << "\n";
}

int main()
{
    // argument is an expression used when calling the method.
    int x = 2;

    // x, 5, 3*2+1 are arguments PASSED to print function
    print(x, 5);
    print(3 * 2 + 1, x);

    return 0;
}
