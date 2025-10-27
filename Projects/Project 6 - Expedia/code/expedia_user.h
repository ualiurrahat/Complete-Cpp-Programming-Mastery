/**
 * @file expedia_user.h
 * @brief User hierarchy and authentication base
 *
 * Defines:
 * - `UserType` enum
 * - Abstract `User` base class
 * - `Admin` concrete subclass
 *
 * Used by:
 * - `UsersManager` for login/signup
 * - `Customer` (defined in expedia_customer.h)
 *
 * @note `Customer` is defined separately to avoid circular includes.
 */

#ifndef EXPEDIA_USER_H_
#define EXPEDIA_USER_H_

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

/**
 * @enum UserType
 * @brief Types of users in the Expedia system.
 */
enum class UserType
{
	CustomerUser = 0, ///< Regular traveler
	AdminUser = 1	  ///< System administrator
};

/**
 * @class User
 * @brief Base class for all user types.
 *
 * Contains common fields:
 * - Username, password, name, email
 * - User type
 *
 * @note Virtual destructor enables polymorphic deletion.
 */
class User
{
protected:
	string username;					   ///< Login username
	string password;					   ///< Plain-text password (for demo)
	string name;						   ///< Full name
	string email;						   ///< Contact email
	UserType type{UserType::CustomerUser}; ///< Default to customer

public:
	// Prevent copying (identity-based)
	User(const User &) = delete;
	void operator=(const User &) = delete;

	/**
	 * @brief Default constructor.
	 */
	User() = default;

	/**
	 * @brief Virtual destructor for polymorphic cleanup.
	 */
	virtual ~User() = default;

	/**
	 * @brief Returns formatted user info.
	 * @return String with name, email, username, and role
	 */
	virtual string ToString() const
	{
		ostringstream oss;
		oss << "Name: " << name << "\n";
		oss << "Email: " << email << "\n";
		oss << "Username: " << username << "\n";
		oss << "Role: " << (type == UserType::AdminUser ? "Admin" : "Customer") << "\n";
		return oss.str();
	}

	/**
	 * @brief Interactive input for user details.
	 * @param username Pre-filled username
	 */
	virtual void Read(const string &username)
	{
		SetUserName(username);

		string input;
		cout << "Enter password: ";
		cin >> input;
		SetPassword(input);

		cout << "Enter full name: ";
		cin >> ws; // Consume whitespace
		getline(cin, input);
		SetName(input);

		cout << "Enter email: ";
		cin >> input;
		SetEmail(input);
	}

	// === Getters ===
	const string &GetUserName() const { return username; }
	const string &GetPassword() const { return password; }
	const string &GetName() const { return name; }
	const string &GetEmail() const { return email; }
	UserType GetType() const { return type; }

	// === Setters ===
	void SetUserName(const string &un) { username = un; }
	void SetPassword(const string &pw) { password = pw; }
	void SetName(const string &n) { name = n; }
	void SetEmail(const string &e) { email = e; }
	void SetType(UserType t) { type = t; }
};

/**
 * @class Admin
 * @brief Administrator user with elevated privileges.
 */
class Admin : public User
{
public:
	// Prevent copying
	Admin(const Admin &) = delete;
	void operator=(const Admin &) = delete;

	/**
	 * @brief Constructor – sets type to Admin.
	 */
	Admin()
	{
		SetType(UserType::AdminUser);
	}
};

#endif /* EXPEDIA_USER_H_ */