/**
 * @file 06_SingleResponsibilityPrinciple.cpp
 * @brief Homework: Split DateTime into Date and Time (SRP).
 *
 * @section problem Problem Statement
 * Avoid a `DateTime` struct that handles both date and time logic.
 * Instead, create:
 * - `Date` → date operations
 * - `Time` → time operations
 * - `DateTime` → composition of both
 *
 * @section intuition Intuition
 * **Single Responsibility Principle (SRP)**:
 * > A class should have one reason to change.
 *
 * Mixing date/time logic → harder to maintain.
 * Separation → reusable, testable, clear.
 *
 * @section logic Logic & Flow
 * 1. `Date` and `Time` are independent
 * 2. `DateTime` **has-a** `Date` and `Time`
 */

#include <iostream>
using namespace std;

struct Date
{
    int day, month, year;
    // Date-specific methods...
};

struct Time
{
    int hours, minutes, seconds;
    // Time-specific methods...
};

struct DateTime
{
    Date date;
    Time time;

    DateTime(Date d, Time t) : date(d), time(t) {}
};

int main()
{
    return 0;
}