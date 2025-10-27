// 06_array_pointer_lvalue.cpp
#include <iostream>
using namespace std;

/**
 * @brief Explores lvalue nature of arrays, pointers, and dereferencing.
 */
int main()
{
    int arr[] = {1, 2, 3, 4};

    // arr is non-modifiable lvalue (array name)
    // arr = &x;     // CE: array name not assignable
    int *p = arr; // decays to pointer to first element

    // p + 1 is prvalue (pointer arithmetic result)
    // p + 1 = arr;  // CE

    // *(p + 1) is lvalue → refers to arr[1]
    *(p + 1) = 10;

    int a = 10;
    p = &a; // &a is prvalue (address)
    // p = &(a+1);    // CE: a+1 is prvalue
    // &a = 40;       // CE: &a is prvalue

    // Exception: string literals are arrays → have address
    char *char_ptr = "mostafa";

    // "mostafa" is prvalue (temporary array)
    // string &ref = "mostafa";  // CE: non-const ref
    const string &ref2 = "mostafa"; // OK: binds to temporary

    cout << "arr[1]: " << arr[1] << endl;

    return 0;
}