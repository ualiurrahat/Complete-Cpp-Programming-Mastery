/**
 * @file 01_vector.cpp
 * @brief Demonstration of vectors in C++ STL
 *
 * Difference between vector and array:
 * 1. Size of array is fixed but vector is dynamic.
 * 2. Can create copy of vector but not in array.
 * 3. Array cannot be returned by function but vector can.
 */

#include <iostream>
#include <vector>    // to use vectors
#include <algorithm> // to use sort, reverse

using namespace std;

/**
 * @brief Display all elements of a vector
 * @tparam T Type of vector
 * @param v Reference to vector
 *
 * @note Time complexity: O(n)
 * @note Space complexity: O(1)
 */
template <class T>
void display(vector<T> &v)
{
    cout << "\nDisplaying this vector: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " "; // same: cout << v.at(i) << " ";
    }
    cout << endl;
}

int main()
{
    // vector is like resizable array.

    // ways to create a vector.
    vector<int> vec; // integer type zero length vector.
    display(vec);    // there is no element in vec. so will show the message only.

    vector<int> vec1; // integer type zero length vector.

    // var to store info about vec1.
    int element, size;
    cout << "Enter the size of your vector: " << endl;
    cin >> size;

    // adding elements to vector.
    cout << "Enter elements to add to the vector: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> element;
        vec1.push_back(element); // storing element to the vector vec1.
    }

    // displaying user input vec1.
    cout << "user's input vector: ";
    display(vec1);
    cout << endl;

    // declaring an iterator to insert an element in the first place.
    vector<int>::iterator iter = vec1.begin();
    // note: if vec1={18,1,8,25,20} declared like this
    // then iteration use shows error.

    // inserting 420 as the first vector element.
    vec1.insert(iter, 420);

    cout << "vector elements after inserting an element: ";
    display(vec1);
    cout << endl;

    // inserting some more elements.
    vec1.insert(iter + 2, 200); // will insert 200 after the first two elements.
    cout << "inserting 200 after first two elements: ";
    display(vec1);
    cout << endl;

    // inserting one element several times.
    vec1.insert(iter, 3, 8); // keeping 8 for 3 times.
    cout << "inserting 8 three times in the beginning: ";
    display(vec1);
    cout << endl;

    // popping out the last element.
    vec1.pop_back();
    cout << "after popping out the last element: ";
    display(vec1);
    cout << endl;

    // sorting the vector vec1.
    cout << "vec1 before sorting: ";
    display(vec1);

    sort(vec1.begin(), vec1.end()); // takes two parameters: begin and end
    cout << endl
         << "vec1 after sorting: ";
    display(vec1);

    cout << endl;

    // reversing the vector vec1.
    cout << "vec1 before reversing: ";
    display(vec1);

    reverse(vec1.begin(), vec1.end()); // takes begin and end location
    cout << endl
         << "vec1 after reversing: ";
    display(vec1);

    cout << endl;

    vector<char> vec2(4); // 4 element character vector.
    vec2.push_back('m');
    vec2.push_back('o');
    vec2.push_back('h');
    vec2.push_back('o');
    display(vec2);

    vector<char> vec3(vec2); // 4 element character vector from vec2.
    display(vec3);

    vector<int> vec4(6, 25); // 6 element vector of 25s.
    display(vec4);

    // copy vector of vec1 in vec5
    vector<int> vec5 = vec1;
    display(vec5);

    cout << endl;
    cout << "size of vec5: " << vec5.size() << endl;

    return 0;
}
