/**
 * @file 04_virtualFunctionInDetail.cpp
 * @brief Detailed demonstration of virtual functions in C++.
 *
 * Rules of Virtual Functions:
 * 1. Cannot be static.
 * 2. Accessed through object pointers.
 * 3. Can be a friend of another class.
 * 4. A base class virtual function may not be redefined in derived class.
 * 5. Declaring a function virtual in base does not force derived to override it.
 */

#include <iostream>
#include <string>
using namespace std;

/// Base class
class CWH
{
protected:
    string title;
    float rating;

public:
    CWH(string s, float r) : title(s), rating(r) {}

    /// Virtual function to be overridden
    virtual void display() {}
};

/// Derived class for Video content
class CWHVideo : public CWH
{
    float video_length;

public:
    CWHVideo(string s, float r, float length) : CWH(s, r), video_length(length) {}

    void display()
    {
        cout << "Video Title: " << title << endl;
        cout << "Rating: " << rating << " out of 5" << endl;
        cout << "Length: " << video_length << " minutes" << endl;
    }
};

/// Derived class for Text content
class CWHText : public CWH
{
    int words;

public:
    CWHText(string s, float r, int count) : CWH(s, r), words(count) {}

    void display()
    {
        cout << "Text Title: " << title << endl;
        cout << "Rating: " << rating << " out of 5" << endl;
        cout << "Word Count: " << words << endl;
    }
};

/**
 * @brief Main function demonstrating polymorphism using virtual functions.
 */
int main()
{
    // Objects
    CWHVideo cpp_video("C++ Tutorials", 4.8, 1080);
    CWHText cpp_text("C++ Text", 4.35, 388);

    // Base class pointer array
    CWH *tut[2];
    tut[0] = &cpp_video;
    tut[1] = &cpp_text;

    // Runtime polymorphism
    tut[0]->display();
    tut[1]->display();

    return 0;
}
