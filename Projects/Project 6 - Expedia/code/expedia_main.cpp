/**
 * @file expedia_main.cpp
 * @brief Entry point for Expedia.com C++ Console Application
 *
 * This is the **main driver** of the Expedia system.
 * - Initializes frontend
 * - Loads dummy database
 * - Handles user login/signup
 * - Launches customer view
 *
 * @section dummy Dummy Credentials
 * | Type     | Username | Password |
 * |----------|----------|----------|
 * | Customer | `asmaa`  | `222`    |
 *
 * @section input Sample Input Flow
 * @include sample_input.txt
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Core system components
#include "expedia_user_mgr.h"
#include "expedia_backend.h"
#include "expedia_customer_view.h"

/**
 * @class ExpediaFrontend
 * @brief Orchestrates user interaction and system lifecycle.
 *
 * Owns:
 * - UsersManager
 * - ExpediaBackend
 * - CustomerManager (per session)
 *
 * Uses RAII for clean memory management.
 */
class ExpediaFrontend
{
private:
	UsersManager *users_manager{nullptr};
	ExpediaBackend *expedia_manager{nullptr};
	CustomerManager *customer_manager{nullptr};

	/**
	 * @brief Loads initial dummy data (users, payment cards, etc.)
	 */
	void LoadDatabase()
	{
		cout << "Loading system database...\n";
		users_manager->LoadDatabase();
		cout << "Database loaded successfully.\n\n";
	}

public:
	// Prevent copying
	ExpediaFrontend(const ExpediaFrontend &) = delete;
	void operator=(const ExpediaFrontend &) = delete;

	/**
	 * @brief Constructor – initializes core managers.
	 */
	ExpediaFrontend()
		: users_manager(new UsersManager()),
		  expedia_manager(new ExpediaBackend())
	{
		cout << "Expedia.com Console System Initialized\n";
	}

	/**
	 * @brief Destructor – ensures proper cleanup.
	 */
	~ExpediaFrontend()
	{
		cout << "\nDestructor: ExpediaFrontend\n";

		if (customer_manager)
		{
			delete customer_manager;
			customer_manager = nullptr;
		}
		if (expedia_manager)
		{
			delete expedia_manager;
			expedia_manager = nullptr;
		}
		if (users_manager)
		{
			delete users_manager;
			users_manager = nullptr;
		}

		cout << "System shutdown complete.\n";
	}

	/**
	 * @brief Main application loop.
	 *
	 * Flow:
	 * 1. Login/Signup
	 * 2. Launch Customer View (only customer supported)
	 * 3. Repeat
	 */
	void Run()
	{
		LoadDatabase();

		while (true)
		{
			users_manager->AccessSystem(); // Login or Signup

			User *current_user = users_manager->GetCurrentUser();

			if (current_user->GetType() == UserType::CustomerUser)
			{
				customer_manager = new CustomerManager(current_user, *expedia_manager);
				CustomerView view(*customer_manager);
				view.Display();

				// Clean up session
				delete customer_manager;
				customer_manager = nullptr;
			}
			else
			{
				cout << "Error: Unsupported user type. Only customers allowed.\n";
				assert(false && "Admin or unknown user type");
			}
		}
	}
};

/**
 * @brief Program entry point.
 * @return 0 on success
 */
int main()
{
	cout << R"(
=========================================
     EXPEDIA.COM - C++ CONSOLE SYSTEM
     Author: Ualiur Rahman Rahat
     Course: C++ Programming Masterclass
=========================================
)" << endl;

	try
	{
		ExpediaFrontend site;
		site.Run();
	}
	catch (const exception &e)
	{
		cerr << "Fatal Error: " << e.what() << endl;
		return 1;
	}
	catch (...)
	{
		cerr << "Unknown error occurred. Exiting.\n";
		return 1;
	}

	return 0;
}