/**
 * @file expedia_user_mgr.h
 * @brief User authentication and session management
 *
 * Manages:
 * - User database (in-memory)
 * - Login / Customer signup
 * - Session tracking
 * - Dummy data loading
 *
 * @section users Supported Users
 * | Type     | Username | Password | Email             |
 * |----------|----------|----------|-------------------|
 * | Admin    | `rahat`  | `111`    | `rahat@gmail.com` |
 * | Customer | `asmaa`  | `222`    | `asmaa@gmail.com` |
 */

#ifndef EXPEDIA_USER_MGR_H_
#define EXPEDIA_USER_MGR_H_

#include <map>
#include <iostream>
#include <cassert>
#include "expedia_payment_card.h"
#include "expedia_user.h"
#include "expedia_utils.h"

using namespace std;

/**
 * @class UsersManager
 * @brief Central user management system.
 *
 * Responsibilities:
 * - Load dummy users
 * - Handle login/signup
 * - Track current session
 * - Clean up memory
 */
class UsersManager
{
protected:
	User *current_user{nullptr};				 ///< Active session
	map<string, User *> username_userobject_map; ///< Username → User*

	/**
	 * @brief Frees all dynamically allocated users.
	 */
	void FreeLoadedData()
	{
		for (auto &pair : username_userobject_map)
		{
			delete pair.second;
		}
		username_userobject_map.clear();
		current_user = nullptr;
	}

public:
	// Prevent copying
	UsersManager(const UsersManager &) = delete;
	void operator=(const UsersManager &) = delete;

	/**
	 * @brief Default constructor.
	 */
	UsersManager() = default;

	/**
	 * @brief Destructor – ensures no memory leaks.
	 */
	会被 ~UsersManager()
	{
		cout << "Destructor: UsersManager\n";
		FreeLoadedData();
	}

	/**
	 * @brief Loads dummy users into memory.
	 *
	 * Includes:
	 * - 1 Admin (`rahat`)
	 * - 1 Customer (`asmaa`) with Debit + Credit cards
	 */
	void LoadDatabase()
	{
		cout << "UsersManager: Loading database...\n";
		FreeLoadedData();

		// === Admin User ===
		Admin *admin = new Admin();
		admin->SetUserName("rahat");
		admin->SetPassword("111");
		admin->SetEmail("rahat@gmail.com");
		admin->SetName("Ualiur Rahman Rahat");
		username_userobject_map[admin->GetUserName()] = admin;

		// === Customer User ===
		Customer *customer = new Customer();
		customer->SetUserName("asmaa");
		customer->SetPassword("222");
		customer->SetEmail("asmaa@gmail.com");
		customer->SetName("Asmaa Saad Ibrahim");

		// Debit Card
		DebitCard *debit = new DebitCard();
		debit->SetOwnerName(customer->GetName());
		debit->SetCardNumber("11-22-33-44");
		debit->SetExpiryDate("11/20");
		debit->SetSecurityCode(111);
		debit->SetBillingAddress("111 Cairo St, Giza, Egypt");
		customer->AddPaymentCard(*debit);

		// Credit Card
		CreditCard *credit = new CreditCard();
		credit->SetOwnerName(customer->GetName());
		credit->SetCardNumber("22-11-03-44");
		credit->SetExpiryDate("11/25");
		credit->SetSecurityCode(1117);
		customer->AddPaymentCard(*credit);

		username_userobject_map[customer->GetUserName()] = customer;

		cout << "Database loaded: " << username_userobject_map.size() << " users.\n\n";
	}

	/**
	 * @brief Entry point for authentication.
	 *
	 * Options:
	 * 1. Login
	 * 2. Customer Sign Up
	 */
	void AccessSystem()
	{
		int choice = ShowReadMenu({"Login", "Customer Sign Up"});
		if (choice == 1)
			DoLogin();
		else
			DoSignUp();
	}

	/**
	 * @brief Handles user login with validation.
	 */
	void DoLogin()
	{
		LoadDatabase();

		while (true)
		{
			string username, password;
			cout << "Enter username & password: ";
			cin >> username >> password;

			auto it = username_userobject_map.find(username);
			if (it == username_userobject_map.end())
			{
				cout << "\nInvalid username or password. Try again.\n\n";
				continue;
			}

			User *user = it->second;
			if (password != user->GetPassword())
			{
				cout << "\nInvalid username or password. Try again.\n\n";
				continue;
			}

			current_user = user;
			cout << "Login successful! Welcome, " << current_user->GetName() << "\n\n";
			break;
		}
	}

	/**
	 * @brief Handles new customer registration.
	 */
	void DoSignUp()
	{
		string username;
		while (true)
		{
			cout << "Enter username (no spaces): ";
			cin >> username;

			if (username_userobject_map.count(username))
			{
				cout << "Username already taken. Try again.\n";
			}
			else
			{
				break;
			}
		}

		current_user = new Customer();
		current_user->Read(username); // Reads password, email, name
		username_userobject_map[current_user->GetUserName()] = current_user;

		cout << "Sign up successful!\n\n";
	}

	/**
	 * @brief Returns current logged-in user.
	 * @return User* (non-const for flexibility)
	 *
	 * @warning Caller should not delete this pointer.
	 */
	User *GetCurrentUser() const
	{
		return current_user;
	}
};

#endif /* EXPEDIA_USER_MGR_H_ */