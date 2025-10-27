// 07_common_errors.cpp
#include <iostream>
#include <utility>
#include <string>
using namespace std;

/**
 * @brief Collection of common lvalue/prvalue mistakes and their fixes.
 */
int main()
{
    int salary = 100;

    // salary + 1 = 300;     // CE: salary+1 is prvalue
    // 200 = salary;        // CE: 200 is prvalue

    int &ref1 = salary; // OK
    ref1 = 20;

    const string &ref2 = "mostafa"; // OK: const ref extends lifetime
    // string &ref3 = "mostafa";     // CE: non-const ref to temporary

    // int *p1 = "mostafa";         // CE: different types

    // ++salary = 20;               // CE: ++salary is lvalue, but not assignable in this context
    // salary++ = 40;               // CE: salary++ is prvalue

    int arr[] = {1, 2, 3, 4};
    // arr = &salary;               // CE: array name not assignable

    int *p = arr;
    // p + 1 = arr;                 // CE: p+1 is prvalue
    *(p + 1) = 10; // OK: *(p+1) is lvalue

    p = &salary;
    // p = &(salary+1);             // CE: salary+1 is prvalue
    // &salary = 40;                // CE: &salary is prvalue
    // &salary = p;                 // CE: type mismatch

    cout << "arr[1] after modification: " << arr[1] << endl;

    return 0;
}