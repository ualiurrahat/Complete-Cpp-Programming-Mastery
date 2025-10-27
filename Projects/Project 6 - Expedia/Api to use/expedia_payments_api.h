/**
 * @file expedia_payments_api.h
 * @brief Mock payment gateway APIs (PayPal, Stripe, Square)
 *
 * Defines simple payment processing interfaces.  Real implementations
 * would contact external payment services; these are stubs that always
 * succeed (except where noted for testing failure paths).
 */

#ifndef EXPEDIA_PAYMENTS_API_H_
#define EXPEDIA_PAYMENTS_API_H_

#include <string>
#include "json.hpp" // nlohmann/json library
using json::JSON;

using namespace std;

/**
 * @struct PayPalCreditCard
 * @brief Credit card details required by PayPal.
 */
class PayPalCreditCard
{
public:
    string name;        ///< Cardholder name
    string address;     ///< Billing address
    string id;          ///< Card number
    string expiry_date; ///< MM/YY
    int ccv;            ///< CVV code
};

/**
 * @class PayPalOnlinePaymentAPI
 * @brief Mock PayPal payment processor.
 */
class PayPalOnlinePaymentAPI
{
public:
    /**
     * @brief Stores card information for the transaction.
     * @param card Pointer to card details
     */
    void SetCardInfo(const PayPalCreditCard *const card)
    {
        // No-op in mock
    }

    /**
     * @brief Attempts to charge the given amount.
     * @param money Amount in USD
     * @return true if payment succeeded (always true in mock)
     */
    bool MakePayment(double money)
    {
        // Simulate successful payment
        return true;
    }
};

/**
 * @struct StripeUserInfo
 * @brief Basic user info for Stripe.
 */
class StripeUserInfo
{
public:
    string name;
    string address;
};

/**
 * @struct StripeCardInfo
 * @brief Card details for Stripe.
 */
class StripeCardInfo
{
public:
    string id;          ///< Card token or number
    string expiry_date; ///< MM/YY
};

/**
 * @class StripePaymentAPI
 * @brief Mock Stripe payment processor.
 */
class StripePaymentAPI
{
public:
    /**
     * @brief Withdraws money using Stripe.
     * @param user User information
     * @param card Card information
     * @param money Amount to charge
     * @return true on success (always true in mock)
     */
    static bool WithDrawMoney(const StripeUserInfo &user,
                              const StripeCardInfo &card,
                              double money)
    {
        return true;
    }
};

/**
 * @class SquarePaymentAPI
 * @brief Mock Square payment processor using JSON query.
 */
class SquarePaymentAPI
{
public:
    /**
     * @brief Processes payment via JSON payload.
     * @param JsonQuery JSON string containing payment details
     * @return true on success (always true in mock)
     */
    static bool WithDrawMoney(const string &JsonQuery)
    {
        // Uncomment to debug JSON:
        // cout << JsonQuery << "\n";

        JSON obj = JSON::Load(JsonQuery);
        return true;
    }
};

#endif /* EXPEDIA_PAYMENTS_API_H_ */