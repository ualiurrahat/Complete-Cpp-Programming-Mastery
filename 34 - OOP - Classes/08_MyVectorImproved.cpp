/**
 * @file 08_MyVectorImproved.cpp
 * @brief Refined version of MyVector with better naming and const correctness.
 *
 * Key improvements:
 * - Parameter `len_` avoids shadowing member `len`
 * - `get()` is `const` (doesn't modify object)
 * - Clear separation between allocation and initialization
 * - Added `set()` for modification (optional)
 */

#include <iostream>
using namespace std;

class MyVector
{
private:
    int *arr; ///< Dynamically allocated storage
    int len;  ///< Current length

public:
    /**
     * @brief Constructs a vector of specified length.
     * @param len_ Number of elements
     * @param default_value Initial value for all elements
     */
    MyVector(int len_, int default_value = 0) : len(len_)
    {
        if (len <= 0)
            len = 1;

        arr = new int[len];

        for (int i = 0; i < len; ++i)
        {
            arr[i] = default_value;
        }

        cout << "MyVector(" << len << ") constructed\n";
    }

    /** @brief Destructor – clean up dynamic memory. */
    ~MyVector()
    {
        delete[] arr;
        cout << "MyVector destroyed\n";
    }

    /**
     * @brief Read value at index (const method).
     * @param pos Index (0-based)
     * @return Stored value
     */
    int get(int pos) const
    {
        if (pos < 0 || pos >= len)
        {
            cout << "Error: index " << pos << " out of bounds [0," << len - 1 << "]\n";
            return 0;
        }
        return arr[pos];
    }

    /**
     * @brief Modify value at index.
     * @param pos Index
     * @param value New value
     */
    void set(int pos, int value)
    {
        if (pos >= 0 && pos < len)
        {
            arr[pos] = value;
        }
        else
        {
            cout << "set(): index out of bounds\n";
        }
    }

    int size() const { return len; }
};

int main()
{
    MyVector v(8, 100);                    // 8 elements, all 100
    cout << "v[3] = " << v.get(3) << "\n"; // 100

    v.set(3, 999);
    cout << "After set: v[3] = " << v.get(3) << "\n"; // 999

    cout << "Size: " << v.size() << "\n";

    return 0;
}