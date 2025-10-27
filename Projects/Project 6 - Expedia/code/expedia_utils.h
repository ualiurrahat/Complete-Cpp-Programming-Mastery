/**
 * @file expedia_utils.h
 * @brief Utility functions for console interaction and time
 *
 * Provides:
 * - `ReadInt()` – safe integer input with range validation
 * - `ShowReadMenu()` – interactive numbered menu
 * - `GetCurrentTimeDate()` – formatted current timestamp
 *
 * Used throughout the Expedia console system for UI and logging.
 */

#ifndef EXPEDIA_UTILS_H_
#define EXPEDIA_UTILS_H_

#include <cassert>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* ================================
   SAFE INTEGER INPUT
   ================================ */

/**
 * @brief Reads an integer with range validation.
 *
 * @param low Minimum allowed value (inclusive)
 * @param high Maximum allowed value (inclusive)
 * @param cancel_choice_allowed If true, -1 cancels input
 * @return Valid integer or -1 if canceled
 *
 * @note Recursively retries on invalid input.
 */
int ReadInt(int low, int high, bool cancel_choice_allowed = false)
{
	if (!cancel_choice_allowed)
	{
		cout << "\nEnter number in range " << low << " - " << high << ": ";
	}
	else
	{
		cout << "\nEnter -1 to cancel or number in range " << low << " - " << high << ": ";
	}

	int value;
	cin >> value;

	// Handle cancellation
	if (cancel_choice_allowed && value == -1)
	{
		return value;
	}

	// Validate range
	if (low <= value && value <= high)
	{
		return value;
	}

	cout << "ERROR: Invalid number. Try again.\n";
	return ReadInt(low, high, cancel_choice_allowed);
}

/* ================================
   INTERACTIVE MENU
   ================================ */

/**
 * @brief Displays a numbered menu and returns user choice.
 *
 * @param choices List of menu options
 * @param header Custom header text (default: "Menu")
 * @return Selected option index (1-based)
 */
int ShowReadMenu(const vector<string> &choices, const string &header = "Menu")
{
	cout << "\n"
		 << header << ":\n";
	for (size_t i = 0; i < choices.size(); ++i)
	{
		cout << "\t" << (i + 1) << ": " << choices[i] << "\n";
	}
	return ReadInt(1, static_cast<int>(choices.size()));
}

/* ================================
   CURRENT TIME & DATE
   ================================ */

/**
 * @brief Returns current date and time as formatted string.
 *
 * @return String in format: `YYYY-MM-DD HH:MM:SS`
 *
 * @note Uses system clock and local timezone.
 *
 * @see https://stackoverflow.com/questions/17223096
 */
string GetCurrentTimeDate()
{
	auto now = chrono::system_clock::now();
	auto in_time_t = chrono::system_clock::to_time_t(now);

	stringstream ss;
	ss << put_time(localtime(&in_time_t), "%Y-%m-%d %X");
	return ss.str();
}

#endif /* EXPEDIA_UTILS_H_ */