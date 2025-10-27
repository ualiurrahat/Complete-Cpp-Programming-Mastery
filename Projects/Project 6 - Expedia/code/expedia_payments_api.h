/**
 * @file expedia_payments_api.h
 * @brief Payment gateway abstractions and mock APIs (PayPal, Stripe, Square)
 *
 * Implements:
 * - Mock payment provider APIs
 * - Unified `IPayment` interface (Dependency Inversion)
 * - Concrete adapters: PayPal, Stripe, Square
 * - `PaymentFactory` to decouple from concrete types
 *
 * @section dip Dependency Inversion
 * High-level modules (Expedia backend) depend on `IPayment` abstraction,
 * not on low-level APIs (PayPal/Stripe). This enables easy swapping.
 */

#ifndef EXPEDIA_PAYMENTS_API_H_
#define EXPEDIA_PAYMENTS_API_H_

#include <string>
#include <sstream>
#include "json.hpp" // nlohmann/json library
using json::JSON;

using namespace std;

/* ================================
   MOCK PAYMENT PROVIDER APIS
   ================================ */

/**
 * @struct PayPalCreditCard
 * @brief Data required by PayPal API.
 */
class PayPalCreditCard
{
public:
	string name;
	string address;
	string id;
	string expiry_date;
	int ccv;
};

/**
 * @class PayPalOnlinePaymentAPI
 * @brief Mock PayPal payment processor.
 */
class PayPalOnlinePaymentAPI
{
public:
	void SetCardInfo(const PayPalCreditCard *const) {}
	bool MakePayment(double) { return true; }
};

/**
 * @struct StripeUserInfo
 * @brief User info for Stripe.
 */
class StripeUserInfo
{
public:
	string name;
	string address;
};

/**
 * @struct StripeCardInfo
 * @brief Card info for Stripe.
 */
class StripeCardInfo
{
public:
	string id;
	string expiry_date;
};

/**
 * @class StripePaymentAPI
 * @brief Mock Stripe processor.
 */
class StripePaymentAPI
{
public:
	static bool WithDrawMoney(StripeUserInfo, StripeCardInfo, double)
	{
		return true;
	}
};

/**
 * @class SquarePaymentAPI
 * @brief Mock Square processor using JSON.
 */
class SquarePaymentAPI
{
public:
	static bool WithDrawMoney(const string &JsonQuery)
	{
		// Uncomment for debugging:
		// cout << "Square JSON: " << JsonQuery << "\n";
		JSON obj = JSON::Load(JsonQuery);
		return true;
	}
};

/* ================================
   UNIFIED PAYMENT INTERFACE
   ================================ */

/**
 * @class IPayment
 * @brief Abstract interface for all payment processors.
 *
 * High-level modules depend on this, not concrete APIs.
 */
class IPayment
{
public:
	virtual void SetUserInfo(const string &name, const string &address) = 0;
	virtual void SetCardInfo(const string &id, const string &expiry_date, int ccv) = 0;
	virtual bool MakePayment(double money) = 0;
	virtual ~IPayment() = default;
};

/* ================================
   CONCRETE PAYMENT ADAPTERS
   ================================ */

/**
 * @class PayPalPayment
 * @brief Adapts PayPal API to IPayment.
 */
class PayPalPayment : public IPayment
{
private:
	PayPalOnlinePaymentAPI paypal;
	PayPalCreditCard card;

public:
	virtual void SetUserInfo(const string &name, const string &address) override
	{
		card.name = name;
		card.address = address;
	}

	virtual void SetCardInfo(const string &id, const string &expiry_date, int ccv) override
	{
		card.id = id;
		card.expiry_date = expiry_date;
		card.ccv = ccv;
	}

	virtual bool MakePayment(double money) override
	{
		paypal.SetCardInfo(&card);
		return paypal.MakePayment(money);
	}
};

/**
 * @class StripePayment
 * @brief Adapts Stripe API to IPayment.
 */
class StripePayment : public IPayment
{
private:
	StripeUserInfo user;
	StripeCardInfo card;

public:
	virtual void SetUserInfo(const string &name, const string &address) override
	{
		user.name = name;
		user.address = address;
	}

	virtual void SetCardInfo(const string &id, const string &expiry_date, int) override
	{
		card.id = id;
		card.expiry_date = expiry_date;
	}

	virtual bool MakePayment(double money) override
	{
		return StripePaymentAPI::WithDrawMoney(user, card, money);
	}
};

/**
 * @class SquarePayment
 * @brief Adapts Square JSON API to IPayment (Adapter Pattern).
 */
class SquarePayment : public IPayment
{
private:
	string name;
	string address;
	string id;
	string expiry_date;
	int ccv;

public:
	virtual void SetUserInfo(const string &name_, const string &address_) override
	{
		name = name_;
		address = address_;
	}

	virtual void SetCardInfo(const string &id_, const string &expiry_date_, int ccv_) override
	{
		id = id_;
		expiry_date = expiry_date_;
		ccv = ccv_;
	}

	virtual bool MakePayment(double money) override
	{
		JSON obj;
		obj["user_info"] = JSON::Array(name, address);
		obj["card_info"]["ID"] = id;
		obj["card_info"]["DATE"] = expiry_date;
		obj["card_info"]["CCV"] = ccv;
		obj["money"] = money;

		ostringstream oss;
		oss << obj;
		return SquarePaymentAPI::WithDrawMoney(oss.str());
	}
};

/* ================================
   PAYMENT FACTORY
   ================================ */

/**
 * @class PaymentFactory
 * @brief Creates concrete IPayment implementations.
 *
 * Decouples backend from specific payment types.
 */
class PaymentFactory
{
public:
	/**
	 * @brief Returns a payment processor (configurable).
	 * @return New IPayment* (caller must delete)
	 *
	 * @note Currently returns SquarePayment for JSON demo.
	 */
	static IPayment *GetPaymentHelper()
	{
		return new SquarePayment(); // Change to PayPalPayment() or StripePayment() as needed
									// return new PayPalPayment();
									// return new StripePayment();
	}
};

#endif /* EXPEDIA_PAYMENTS_API_H_ */