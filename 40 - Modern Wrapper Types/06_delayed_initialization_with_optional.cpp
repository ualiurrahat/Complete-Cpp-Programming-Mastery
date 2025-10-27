// 06_delayed_initialization_with_optional.cpp
/**
 * @file 06_delayed_initialization_with_optional.cpp
 * @brief Solves the "delayed initialization" problem using std::optional.
 *
 * Some objects don't have default constructors. You can't declare them as
 * members without initializing. std::optional allows deferred construction
 * via emplace().
 */

#include <iostream>
#include <vector>
#include <optional>
#include <string>
using namespace std;

struct MyClass
{
    /**
     * @brief Constructs MyClass with data.
     * @note No default constructor — intentional design.
     */
    MyClass(const vector<int> &v, int x, string name)
    {
        // Imagine heavy initialization here
        cout << "MyClass constructed with vector size " << v.size()
             << ", x=" << x << ", name=" << name << endl;
    }
};

struct AnotherClass
{
    optional<MyClass> obj; // No initialization required!

    /**
     * @brief Constructs and emplaces MyClass in-place.
     * @param n Size of vector to create
     *
     * emplace() forwards arguments to MyClass constructor.
     * Avoids copy/move of temporary MyClass.
     */
    AnotherClass(int n)
    {
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            v[i] = i * i;

        obj.emplace(v, n, "Mostafa"); // In-place construction
    }
};

int main()
{
    AnotherClass ac(3);
    // MyClass is constructed only when emplace is called
    return 0;
}