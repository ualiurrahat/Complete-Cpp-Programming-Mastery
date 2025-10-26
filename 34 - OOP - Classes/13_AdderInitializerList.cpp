/**
 * @file 13_AdderInitializerList.cpp
 * @brief Uses `std::initializer_list` for flexible sum accumulation.
 *
 * - Constructor accepts `{1,2,3}` → sums all
 * - `Add(a,b)` and `Add({3,4})` both update internal total
 * - Demonstrates **uniform initialization syntax**
 */

#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class Adder
{
private:
    int total_sum = 0; ///< Accumulated sum (C++11 in-class init)

public:
    /** @brief Default constructor – zero sum. */
    Adder() = default;

    /** @brief Construct from initializer_list – sum all elements. */
    Adder(const initializer_list<int> &lst)
    {
        Add(lst);
    }

    /**
     * @brief Add two integers to the total.
     * @return New total
     */
    int Add(int a, int b)
    {
        total_sum += a + b;
        return total_sum;
    }

    /**
     * @brief Add all values from a list.
     * @param lst List of integers
     * @return New total
     */
    int Add(const initializer_list<int> &lst)
    {
        int sum = 0;
        for (int value : lst)
            sum += value;
        total_sum += sum;
        return total_sum;
    }

    /** @brief Get current accumulated sum. */
    int GetCurrentSum() const
    {
        return total_sum;
    }
};

int main()
{
    Adder adder{1, 2, 3};                  // initializer_list ctor
    cout << adder.GetCurrentSum() << "\n"; // 6

    adder.Add(3, 4);
    cout << adder.GetCurrentSum() << "\n"; // 13

    adder.Add({3, 4});
    cout << adder.GetCurrentSum() << "\n"; // 20

    adder.Add({3, 4, 3});
    cout << adder.GetCurrentSum() << "\n"; // 30

    return 0;
}