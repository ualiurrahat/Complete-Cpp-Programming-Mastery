/**
 * @file expedia_payment_card.h
 * @brief Payment card hierarchy (Debit & Credit)
 * @author Rahat (Original: moustafa)
 * @date 2025
 *
 * Defines:
 * - Abstract `PaymentCard` base class
 * - `DebitCard` with billing address
 * - `CreditCard` without address
 *
 * Used for:
 * - Storing user payment methods
 * - Secure display (no CCV)
 * - Deep cloning via `Clone()`
 */

#ifndef EXPEDIA_PAYMENT_CARD_H_
#define EXPEDIA_PAYMENT_CARD_H_

#include <string>
#include <sstream>

using namespace std;

/**
 * @class PaymentCard
 * @brief Abstract base class for all payment cards.
 *
 * Supports:
 * - Owner name
 * - Card number
 * - Expiry date
 * - Security code (CCV)
 *
 * @note Security code is **never** displayed in `ToString()`
 */
class PaymentCard
{
protected:
	string owner_name;	///< Cardholder name
	string card_number; ///< Full card number
	string expiry_date; ///< MM/YY format
	int security_code;	///< CCV (3-4 digits)

public:
	// === Getters ===
	const string &GetCardNumber() const { return card_number; }
	const string &GetExpiryDate() const { return expiry_date; }
	const string &GetOwnerName() const { return owner_name; }
	int GetSecurityCode() const { return security_code; }

	// === Setters ===
	void SetCardNumber(const string &cardNumber) { card_number = cardNumber; }
	void SetExpiryDate(const string &expiryDate) { expiry_date = expiryDate; }
	void SetOwnerName(const string &ownerName) { owner_name = ownerName; }
	void SetSecurityCode(int securityCode) { security_code = securityCode; }

	/**
	 * @brief Returns user-friendly string (no CCV).
	 * @return Formatted card info
	 */
	virtual string ToString() const
	{
		ostringstream oss;
		oss << "Owner: " << owner_name
			<< " | Card: " << card_number
			<< " | Expires: " << expiry_date;
		return oss.str();
	}

	/**
	 * @brief Creates a deep copy of the card.
	 * @return New dynamically allocated clone
	 */
	virtual PaymentCard *Clone() const = 0;

	virtual ~PaymentCard() = default;
};

/**
 * @class DebitCard
 * @brief Debit card with billing address.
 */
class DebitCard : public PaymentCard
{
protected:
	string billing_address; ///< Full billing address

public:
	const string &GetBillingAddress() const { return billing_address; }
	void SetBillingAddress(const string &billingAddress) { billing_address = billingAddress; }

	/**
	 * @brief Deep clone of DebitCard.
	 */
	virtual PaymentCard *Clone() const override
	{
		return new DebitCard(*this);
	}

	/**
	 * @brief Includes billing address in output.
	 */
	virtual string ToString() const override
	{
		ostringstream oss;
		oss << "[Debit Card] " << PaymentCard::ToString()
			<< " | Billing: " << billing_address;
		return oss.str();
	}
};

/**
 * @class CreditCard
 * @brief Credit card (no billing address stored).
 *
 * @note Billing address not required for credit cards in this system.
 */
class CreditCard : public PaymentCard
{
public:
	/**
	 * @brief Deep clone of CreditCard.
	 */
	virtual PaymentCard *Clone() const override
	{
		return new CreditCard(*this);
	}

	/**
	 * @brief Simple credit card display.
	 */
	virtual string ToString() const override
	{
		ostringstream oss;
		oss << "[Credit Card] " << PaymentCard::ToString();
		return oss.str();
	}
};

#endif /* EXPEDIA_PAYMENT_CARD_H_ */