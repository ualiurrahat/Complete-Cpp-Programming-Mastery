/**
 * @file 07_CodeReviewAndDesign.cpp
 * @brief Homework: Critique and improve a BankCustomer struct.
 *
 * @section problem Problem Statement
 * Given a flawed `BankCustomer` struct, identify issues:
 * - Irrelevant fields (favorite movie, food, etc.)
 * - `rectangle_width` → copy-paste error
 * - `birth_of_date` as string → hard to process
 *
 * Suggest improvements using composition and relevance.
 *
 * @section intuition Intuition
 * **Good design** = **relevance + clarity + reusability**.
 * Only include data needed for the **domain** (banking).
 * Use `Date` struct for birth date → reuse + type safety.
 *
 * @section logic Logic & Flow
 * 1. Remove irrelevant fields
 * 2. Use `Date` for birth
 * 3. Keep only banking-relevant data
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 500;
string employee_first_name[MAX]; // Global arrays — avoid in OOP

struct Date
{
    int day, month, year;
};

struct BankCustomer
{
    string name;
    string address;
    string mobile;
    Date birth_date; // Reusable, type-safe

    // Only banking-relevant data
    // No: favorite_food, rectangle_width, etc.
};

/*
 * Code Review Feedback:
 * 1. Remove `rectangle_width` → irrelevant
 * 2. Remove `favourite_*` → not needed in banking
 * 3. Replace `birth_of_date` string → use `Date` struct
 *    → Enables age calculation, validation, formatting
 * 4. Prefer composition over primitive obsession
 */

int main()
{
    return 0;
}