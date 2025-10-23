// 01_templates.cpp
// Templates in C++
// We are creating a template class that can handle vectors of any data type
// and compute the dot product of two vectors.

#include <iostream>
#include <string>

using namespace std;

// ---------------------- Template Class Definition ----------------------
template <class T> // T represents a generic data type
class Vector
{
public:
    int size;
    T *arr;

    // Constructor to create a vector of given size
    Vector(int m)
    {
        size = m;
        arr = new T[size];
    }

    // Function to calculate the dot product of two vectors
    T dotProduct(Vector &v) // Using reference to avoid unnecessary copy
    {
        T sum = 0;
        for (int i = 0; i < size; i++)
        {
            // Both vectors should have equal size
            sum += this->arr[i] * v.arr[i];
        }
        return sum;
    }
};

// ---------------------- Main Function ----------------------
int main()
{
    // Integer vectors
    Vector<int> v1(3);
    v1.arr[0] = 4;
    v1.arr[1] = 3;
    v1.arr[2] = 1;

    Vector<int> v2(3);
    v2.arr[0] = 1;
    v2.arr[1] = 0;
    v2.arr[2] = 1;

    int dotInt = v1.dotProduct(v2);
    cout << "Dot product of integer vectors: " << dotInt << endl;

    // Float vectors
    Vector<float> v3(3);
    v3.arr[0] = 1.4;
    v3.arr[1] = 3.3;
    v3.arr[2] = 0.1;

    Vector<float> v4(3);
    v4.arr[0] = 0.1;
    v4.arr[1] = 1.9;
    v4.arr[2] = 4.1;

    float dotFloat = v3.dotProduct(v4);
    cout << "Dot product of float vectors: " << dotFloat << endl;

    return 0;
}
