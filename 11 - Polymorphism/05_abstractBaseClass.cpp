/**
 * @file 05_abstractBaseClass.cpp
 * @brief Demonstration of Abstract Base Class and Pure Virtual Function in C++.
 *
 * - An Abstract Base Class is a class with at least one pure virtual function.
 * - Pure Virtual Function: Declared by assigning 0 (`virtual void func() = 0;`).
 * - Such classes cannot create objects but can have pointers to derived class objects.
 * - Any derived class must override the pure virtual function, otherwise it becomes abstract as well.
 */

#include <iostream>
#include <string>
using namespace std;

/// Abstract Base Class
class CWH
{
protected:
    string title;
    float rating;

public:
    /// Constructor to initialize base attributes
    CWH(string s, float r) : title(s), rating(r) {}

    /// Pure virtual function (must be overridden in derived classes)
    virtual void display() = 0;
};

/// Derived class representing Video tutorials
class CWHVideo : public CWH
{
    float video_length;

public:
    CWHVideo(string s, float r, float length) : CWH(s, r), video_length(length) {}

    void display()
    {
        cout << "Video Title: " << title << endl;
        cout << "Ratings: " << rating << " out of 5" << endl;
        cout << "Length: " << video_length << " minutes" << endl;
    }
};

/// Derived class representing Text tutorials
class CWHText : public CWH
{
    int words;

public:
    CWHText(string s, float r, int count) : CWH(s, r), words(count) {}

    void display()
    {
        cout << "Text Title: " << title << endl;
        cout << "Text Rating: " << rating << " out of 5" << endl;
        cout << "Word Count: " << words << endl;
    }
};

/**
 * @brief Main function demonstrating abstract base class and pure virtual functions.
 */
int main()
{
    // Creating objects of derived classes
    CWHVideo cpp_video("C++ Tutorials", 4.8, 1080);
    CWHText cpp_text("C++ Text", 4.35, 388);

    // Directly calling display() on objects
    cpp_video.display();
    cpp_text.display();

    cout << "\n--- Using base class pointers for polymorphism ---\n";

    // Array of base class pointers
    CWH *tut[2];
    tut[0] = &cpp_video;
    tut[1] = &cpp_text;

    // Calls overridden display() functions of derived classes
    tut[0]->display();
    tut[1]->display();

    return 0;
}
