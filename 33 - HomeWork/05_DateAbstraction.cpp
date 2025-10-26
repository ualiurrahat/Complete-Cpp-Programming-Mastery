/**
 * @file 05_DateAbstraction.cpp
 * @brief Homework: Design a Date struct with rich operations.
 *
 * @section problem Problem Statement
 * Create `struct Date` with:
 * - `day`, `month`, `year`
 * - Methods: `LengthOfMonth()`, `IsLeapYear()`, `MinusDays()`, `ToString(format)`, etc.
 *
 * Discuss trade-offs in design.
 *
 * @section intuition Intuition
 * Dates are complex (leap years, variable month lengths).
 * Encapsulating logic in a struct prevents errors.
 * `ToString(format)` enables flexible output.
 *
 * @section logic Logic & Flow
 * 1. Store as 3 ints (clarity over efficiency)
 * 2. Methods operate on `this`
 * 3. `IsLeapYear()` → standard rule
 */

#include <iostream>
#include <string>
using namespace std;

struct Date
{
    int day, month, year;

    int LengthOfMonth() const;
    int LengthOfYear() const { return IsLeapYear() ? 366 : 365; }
    Date MinusDays(int days) const;
    string ToString(const string &format) const;
    bool IsLeapYear() const;
    bool isEqual(const Date &d) const { return day == d.day && month == d.month && year == d.year; }
    bool isBefore(const Date &d) const;
    // PlusDays, MinusMonths, etc. follow similar pattern
};

int Date::LengthOfMonth() const
{
    static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && IsLeapYear())
        return 29;
    return days[month];
}

bool Date::IsLeapYear() const
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Date::isBefore(const Date &d) const
{
    if (year != d.year)
        return year < d.year;
    if (month != d.month)
        return month < d.month;
    return day < d.day;
}

string Date::ToString(const string &format) const
{
    // Simplified — real version would parse format string
    char buf[20];
    snprintf(buf, sizeof(buf), "%04d-%02d-%02d", year, month, day);
    return string(buf);
}

int main()
{
    return 0;
}